PORTNAME=	flycast
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-platform Sega Dreamcast emulator
WWW=		https://github.com/flyinghead/flycast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	flyinghead
USE_SDL=	sdl2

.include "${.CURDIR}/Makefile.tuples"

# CMAKE_ON=
CMAKE_OFF=	USE_HOST_GLSLANG \
		USE_OPENGL \
		USE_OPENMP \
		USE_VULKAN

# For maintainer (do not forget to clean up Makefile.tuples afterwards to
# remove useless submodules)
Makefile.tuples::
	${RM} -f ${.CURDIR}/Makefile.tuples
	${RM} -rf ${WRKDIR}/.maintainer.checkout
	${MKDIR} ${WRKDIR}/.maintainer.checkout
	(cd ${WRKDIR}/.maintainer.checkout && \
		git clone --recursive --branch=${DISTVERSIONPREFIX}${DISTVERSION} \
		https://github.com/${GH_ACCOUNT}/${PORTNAME} . && \
		${SH} ${FILESDIR}/gen_gh_tuple.sh > ${.CURDIR}/Makefile.tuples)

.include <bsd.port.mk>
