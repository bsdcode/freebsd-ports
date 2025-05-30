PORTNAME=	atlas
PORTVERSION=	3.10.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	SF/math-${PORTNAME}/Stable/${PORTVERSION}
PKGNAMESUFFIX=	-math
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically Tuned Linear Algebra Software (ATLAS)
WWW=		https://math-atlas.sourceforge.net/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${NONEXISTENT}:math/lapack:checksum

USES=		fortran gmake tar:bzip2
USE_GCC=	yes

CONFLICTS=	cblas
CONFLICTS_INSTALL=	openblas	# $PREFIX/include/cblas.h
MANUAL_PACKAGE_BUILD=	Optimizes for the local machine.

OPTIONS_DEFINE=		DOCS DATA ARCHDEF TSC WALL_TIMER
OPTIONS_DEFAULT=	DATA
ARCHDEF_DESC=		Use a specified architectural default
DATA_DESC=		Install tuning data and logs from the build
TSC_DESC=		If WALL_TIMER is enabled, use the TSC
WALL_TIMER_DESC=	Use less robust timing with higher resolution

PORTSCOUT=	limitw:1,even
WRKSRC=		${WRKDIR}/ATLAS

.include <bsd.port.options.mk>

#Increase ATLAS_MAXMALLOC if the atlas threaded libraries perform poorly on large problems:
# http://math-atlas.sourceforge.net/errata.html#MaxMalloc
ATLAS_MAXMALLOC?=	67108864

.if !empty(ARCH:M*64*)
POINTER?=	64
.else
POINTER?=	32
.endif

.if defined(MAINTAINER_MODE)
LIB_DEPENDS+=	libblas.so:math/blas
.endif

.if ${PORT_OPTIONS:MDATA}
PORTDATA=	*
.endif
PORTDOCS=	*

.if ${PORT_OPTIONS:MARCHDEF}
.  if defined(ARCHDEF)
.    if ${ARCHDEF} == "NONE"
ARCHDEFFLAG=	-Si archdef 0
.    endif
.  else
IGNORE=		you have set WITH_ARCHDEF, but have not defined ARCHDEF
.  endif
.endif

USE_LDCONFIG=	yes

EXTRA_FLAGS?=	${PICFLAG} -Wl,-rpath=${_GCC_RUNTIME}
SHARED_FLAGS=	${PICFLAG} -DPIC
SHARED_LAPACK_WRKSRC=	WRKSRC
STATIC_LAPACK_WRKSRC=	WRKSRC
PICFLAG?=	-fPIC
CFLAGS+=	${PICFLAG}
CONFIGURE_ENV+=	PATH="${WRKDIR}/.bin:${PATH}"
MAKE_ENV+=	MAKE=${GMAKE} PATH="${WRKDIR}/.bin:${PATH}"
BINARY_ALIAS=	make=${GMAKE} gcc=${CC} gfortran=${FC} f77=${FC}

pre-everything::
	@${CAT} ${FILESDIR}/tuning-message

pre-configure:
	${REINPLACE_CMD} -e 's|$$(ARCH)|$$(ATLAS_ARCH)|g' \
		${WRKSRC}/Make.top \
		${WRKSRC}/makes/Make.bin \
		${WRKSRC}/makes/Make.lib \
		${WRKSRC}/makes/Make.sysinfo \
		${WRKSRC}/CONFIG/src/Makefile \
		${WRKSRC}/CONFIG/ARCHS/Makefile
	${REINPLACE_CMD} -e "\|OS=ALL|{N; \
		s|-mavx|-msse3|;s|'| ${EXTRA_FLAGS}'|4;}" \
		${WRKSRC}/CONFIG/src/atlcomp.txt
	${REINPLACE_CMD} -E -e \
	"\|(#define ATL_MaxMalloc[[:blank:]]+)([[:digit:]]+)|s||\1${ATLAS_MAXMALLOC}|" \
		${WRKSRC}/include/atlas_lvl3.h
	${REINPLACE_CMD} -e 's|%%WRKBIN%%|${WRKDIR}/.bin|'	\
		${WRKSRC}/CONFIG/src/probe_comp.c

do-configure:
	echo "PATH=${PATH} *****************************************"
	if [ ${PORT_OPTIONS:MWALL_TIMER} ] ; then \
		TIMEFLAG= ; \
		if [ \( ${ARCH} = "i386" -o ${ARCH} = "amd64" \) -a ${PORT_OPTIONS:MTSC} ] ; then \
			freq=`${SYSCTL} -ni machdep.tsc_freq` ; \
			if [ "x$${freq}" != "x" ] ; then \
				if [ $${freq} -gt 1000000 ] ; then \
					MHZ=$$(($${freq}/1000000)) ; \
					TIMEFLAG="-D c -DPentiumCPS=$${MHZ}" ; \
				fi ; \
			fi ; \
		fi ; \
		if [ "x$${TIMEFLAG}" = "x" ] ; then \
			TIMEFLAG="-D c -DWALL" ; \
		fi ; \
	fi ; \
	${ECHO_CMD} "TIMEFLAG = $${TIMEFLAG}" \
		> ${WRKSRC}/saved_flags ; \
	${ECHO_CMD} "Dummy configuration of ATLAS to obtain compiler flags:" ; \
	${MKDIR} ${WRKSRC}/static ; cd ${WRKSRC}/static ; \
		${SETENV} ${CONFIGURE_ENV} ../configure --cc="${CC}" --cflags="${CFLAGS}" \
		--prefix="${PREFIX}" -v 2 $${TIMEFLAG} ${ARCHDEFFLAG} \
		-Ss f77lib " " -Ss pmake "${MAKE} ${_MAKE_JOBS}" \
		-Fa alg "${STATIC_FLAGS} " -b ${POINTER}
	${SED} -ne "\|F77FLAGS =|p" ${WRKSRC}/static/Make.inc \
		>> ${WRKSRC}/saved_flags

post-configure:
	@${RM} -r ${WRKSRC}/static

do-build:
.for opt in shared static
	@${ECHO_CMD} "Building the LAPACK archives with ${opt} ATLAS flags:"
	F77FLAGS="`${MAKE} -f ${WRKSRC}/saved_flags -V F77FLAGS` ${EXTRA_FLAGS}" ; \
	LW=`${MAKE} -C ${PORTSDIR}/math/lapack -V ${${opt:tu}_LAPACK_WRKSRC}` ; \
	${MAKE} -C ${PORTSDIR}/math/lapack WITH=${opt:tu} clean patch ; \
	${REINPLACE_CMD} -e 's|-O0|-O0 ${EXTRA_FLAGS}|'	$${LW}/make.inc ; \
	cd $${LW} ; ${SETENV} ${MAKE_ENV:NFFLAGS=*} EXTRAFLAGS="${${opt:tu}_FLAGS} ${PICFLAG} " \
		FFLAGS="-pipe $${F77FLAGS}" ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} \
		ARCH="${AR}" lapacklib ; \
	TIMEFLAG=`${MAKE} -f ${WRKSRC}/saved_flags -V TIMEFLAG` ; \
	${MKDIR} ${WRKSRC}/${opt}/lib ; cd ${WRKSRC}/${opt} ; \
	${MV} $${LW}/liblapack.a liblapack_${opt}.a ; \
	${AR} -dv liblapack_${opt}.a lsame.o xerbla.o csrot.o zdrot.o ; \
	${CP} liblapack_${opt}.a lib/liblapack.a ; \
	${MAKE} -C ${PORTSDIR}/math/lapack clean ; \
	${ECHO_CMD} "Configuring ${opt} ATLAS:" ; \
		${SETENV} ${CONFIGURE_ENV} ../configure --cc="${CC}" --cflags="${CFLAGS}" \
		--prefix="${PREFIX}" -v 2 $${TIMEFLAG} ${ARCHDEFFLAG} \
		-Ss flapack "${WRKSRC}/${opt}/liblapack_${opt}.a" \
		-Ss f77lib " " -Ss pmake "${MAKE_CMD} ${_MAKE_JOBS}" \
		-Si lapackref 1 -D c -DATL_FULL_LAPACK \
		-Fa alg "${${opt:tu}_FLAGS} " -b ${POINTER} ; \
	if [ "x${WITH_ARCHDEF}" != "x" ] ; then \
		if [ "x${ARCHDEF}" != "xNONE" ] ; then \
			if [ -f ${ARCHDEF} ] ; then \
				${CP} -f ${ARCHDEF} ${WRKSRC}/CONFIG/ARCHS/ ; \
			elif [ ! -f ${WRKSRC}/CONFIG/ARCHS/${ARCHDEF} ] ; then \
				${ECHO_CMD} \
				"==> ${PKGNAME} : ARCHDEF \"${ARCHDEF}\" does not exist" ; \
				exit 1 ; \
			fi ; \
			${REINPLACE_CMD} -E -e \
			"\|[[:blank:]]*ARCH =|s|=.*|= ${ARCHDEF:T:S/.tgz$//}|" \
			${WRKSRC}/${opt}/Make.inc ; \
		fi ; \
	fi ; \
	${ECHO_CMD} "Building ${opt} ATLAS:" ; cd ${WRKSRC}/${opt} ; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} all
.endfor

L1=	${FC} $${F77FLAGS} ${SHARED_FLAGS} ${LDFLAGS} -shared -Wl,-x \
	-Wl,--whole-archive -Wl,-soname,
L2=	-Wl,--no-whole-archive -Wl,--as-needed -lpthread

post-build:
.for opt in shared static
	@${ECHO_CMD} "Timing ${opt} ATLAS:"
	(cd ${WRKSRC}/${opt} ; ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} time ; \
		cd ARCHS ; ${SETENV} ${MAKE_ENV} \
			${MAKE_CMD} ${MAKE_ARGS} ArchNew tarfile)
.endfor
	@${ECHO_CMD} "Building ATLAS shared libraries:"
	F77FLAGS="`${MAKE} -f ${WRKSRC}/saved_flags -V F77FLAGS` ${EXTRA_FLAGS}" ; \
	cd ${WRKSRC}/shared/lib ; \
	${L1}libatlas.so.2 -o libatlas.so.2 libatlas.a ${L2} ; \
	${L1}libf77blas.so.2 -o libf77blas.so.2 libf77blas.a ${L2} libatlas.so.2 ; \
	${L1}libptf77blas.so.2 -o libptf77blas.so.2 libptf77blas.a ${L2} libatlas.so.2 ; \
	${L1}libcblas.so.2 -o libcblas.so.2 libcblas.a ${L2} libatlas.so.2 ; \
	${L1}libptcblas.so.2 -o libptcblas.so.2 libptcblas.a ${L2} libatlas.so.2 ; \
	${L1}libalapack.so.2 -o libalapack.so.2 liblapack.a ${L2} libatlas.so.2

.if defined(MAINTAINER_MODE)
STATIC_BLAS=	${LOCALBASE}/lib/libblas.a
SHARED_BLAS=	-L${LOCALBASE}/lib -lblas

test: build
.  for opt in shared static
	@${ECHO_CMD} "Testing ${opt} ATLAS:"
	@cd ${WRKSRC}/${opt} ; ${SETENV} ${MAKE_ENV} BLAS="${${opt:tu}_BLAS}" \
	${MAKE_CMD} ${MAKE_ARGS} check ptcheck error_report
.  endfor
.endif

do-install:
.for i in libatlas libcblas libf77blas liblapack libptcblas libptf77blas
	${INSTALL_DATA} ${WRKSRC}/static/lib/${i}.a \
		${STAGEDIR}${PREFIX}/lib/${i:S|lapack|alapack|}.a
	${INSTALL_DATA} ${WRKSRC}/shared/lib/${i}.a \
		${STAGEDIR}${PREFIX}/lib/${i:S|lapack|alapack|}_pic.a
	${INSTALL_LIB} ${WRKSRC}/shared/lib/${i:S|lapack|alapack|}.so.2 \
		${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${i:S|lapack|alapack|}.so.2 \
		${STAGEDIR}${PREFIX}/lib/${i:S|lapack|alapack|}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/cblas.h ${WRKSRC}/include/clapack.h \
		${STAGEDIR}${PREFIX}/include
.for opt in shared static
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/atlas/${opt}
	${INSTALL_DATA} ${WRKSRC}/${opt}/include/* \
		${STAGEDIR}${PREFIX}/include/atlas/${opt}
.    if ${PORT_OPTIONS:MDATA}
	@${MKDIR} ${STAGEDIR}${DATADIR}/${opt}
	(cd ${WRKSRC}/${opt}/bin; \
		${COPYTREE_SHARE} INSTALL_LOG ${STAGEDIR}${DATADIR}/${opt})
	(cd ${WRKSRC}/${opt}/ARCHS; \
		${COPYTREE_SHARE} "*" ${STAGEDIR}${DATADIR}/${opt} \
		"! -name Makefile -and ! -name *.tgz")
	@${FIND} ${STAGEDIR}${DATADIR}/${opt} -type d -empty -delete
.    endif
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif

post-install:
.for d in shared static
.  for f in xnegmm xnegmv xnegr1
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/${d}/${f}
.  endfor
.endfor

.include <bsd.port.mk>
