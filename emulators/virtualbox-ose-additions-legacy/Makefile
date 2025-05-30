PORTNAME=	virtualbox-ose
DISTVERSION=	5.2.44
PORTREVISION?=	8
CATEGORIES=	emulators
MASTER_SITES=	https://download.virtualbox.org/virtualbox/${DISTVERSION}/
PKGNAMESUFFIX?=	-additions-legacy
DISTNAME=	VirtualBox-${DISTVERSION}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox additions for FreeBSD guests
WWW=		https://www.virtualbox.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	yasm:devel/yasm \
		kmk:devel/kBuild \
		xsltproc:textproc/libxslt

USES=		compiler:c++11-lang cpe iconv kmod tar:bzip2
CPE_VENDOR=	oracle
CPE_PRODUCT=	vm_virtualbox
USE_RC_SUBR=	vboxguest vboxservice

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-alsa \
			--disable-docs \
			--disable-libvpx \
			--disable-opengl \
			--disable-pulse \
			--disable-python \
			--disable-sdl-ttf \
			--disable-xpcom
CONFIGURE_ARGS+=	--nofatal --with-gcc="${CC}" --with-g++="${CXX}"

MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	virtualbox-ose-additions \
			virtualbox-ose-additions-nox11 \
			virtualbox-ose-additions-70 \
			virtualbox-ose-additions-nox11-70 \
			virtualbox-ose-additions-71 \
			virtualbox-ose-additions-nox11-71

PATCHDIR=		${.CURDIR}/../${PORTNAME}-legacy/files
EXTRACT_AFTER_ARGS=	--exclude tools/*.x86 --exclude tools/*.amd64 --exclude Firmware
PORTSCOUT=		limit:^5\.

WRKSRC=			${WRKDIR}/VirtualBox-${DISTVERSION}

OPTIONS_DEFINE=		DBUS DEBUG X11
OPTIONS_DEFINE_i386=	PAE
OPTIONS_DEFAULT=	DBUS X11
OPTIONS_SUB=		yes

PAE_DESC=		Build kernel modules for PAE-kernels
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	--disable-dbus
DEBUG_CONFIGURE_ON=	--build-debug
DEBUG_VARS=		KMK_BUILDTYPE=debug
DEBUG_VARS_OFF=		KMK_BUILDTYPE=release
X11_BUILD_DEPENDS=	${LOCALBASE}/include/xorg/compiler.h:x11-servers/xorg-server
X11_RUN_DEPENDS=	xrandr:x11/xrandr
X11_USES=		pkgconfig xorg
X11_USE=		XORG=x11,xcursor,xext,xorgproto,xmu,xrandr,xt
X11_VARS=		VBOX_WITH_X11=1

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
CONFLICTS_INSTALL+=	virtualbox-ose-additions-nox11-legacy
.else
CONFLICTS_INSTALL+=	virtualbox-ose-additions-legacy
.endif

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/additions
VBOX_SBINS=	VBoxControl \
		VBoxService \
		mount_vboxvfs

BUILD_WRKSRC=	${VBOX_BIN}/src

KMK_ARCH=	freebsd.${ARCH:S/i386/x86/}
KMK_CONFIG+=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys

.if ${PORT_OPTIONS:MX11}
.else
VBOX_WITH_X11=
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-src-VBox-Additions-x11-VBoxClient-Makefile.kmk
.endif
.endif

post-patch:
	@${ECHO_CMD} 'VBOX_ONLY_ADDITIONS = 1' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_DRAG_AND_DROP = ${VBOX_WITH_X11}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_DRAG_AND_DROP_GH = ${VBOX_WITH_X11}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_X11_ADDITIONS = ${VBOX_WITH_X11}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_GCC_std = -std=c++11' >> ${WRKSRC}/LocalConfig.kmk
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's| -finline-limit=8000||' \
	    -e 's| -fno-merge-constants||' \
	    -e 's| -mpreferred-stack-boundary=2||' ${WRKSRC}/Config.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/X11|${LOCALBASE}|g' \
	    ${WRKSRC}/src/VBox/Additions/x11/VBoxClient/display.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    ${WRKSRC}/Config.kmk ${WRKSRC}/configure \
	    ${WRKSRC}/kBuild/header.kmk ${WRKSRC}/kBuild/units/qt4.kmk \
	    ${WRKSRC}/kBuild/units/qt5.kmk ${WRKSRC}/kBuild/sdks/LIBSDL.kmk \
	    ${WRKSRC}/src/VBox/Additions/common/crOpenGL/load.c \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/98vboxadd-xclient \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
	    ${WRKSRC}/src/VBox/Additions/x11/vboxmouse/Makefile.kmk \
	    ${WRKSRC}/src/VBox/Additions/x11/vboxvideo/Makefile.kmk
	@${REINPLACE_CMD} \
	    -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' \
	    ${WRKSRC}/configure
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's|iconv||' ${WRKSRC}/Config.kmk \
	    ${WRKSRC}/src/VBox/Runtime/Makefile.kmk \
	    ${WRKSRC}/src/VBox/Additions/x11/VBoxClient/Makefile.kmk
	@${ECHO_CMD} 'VBOX_ICONV_DEFS = LIBICONV_PLUG' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${PORT_OPTIONS:MPAE}
	@${ECHO_CMD} 'VBOX_FREEBSD = -DPAE' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${OSVERSION} >= 1500038
	@${ECHO_CMD} 'HAVE_MNTOPTS_IN_LIBUTIL = 1' >> \
	    ${WRKSRC}/LocalConfig.kmk
.endif

post-patch-X11-on:
	@${ECHO_CMD} 'VBOX_USE_SYSTEM_XORG_HEADERS = 1' >> \
	    ${WRKSRC}/LocalConfig.kmk

pre-build:
	cd ${WRKSRC} && ${SH} -c \
	    ". env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk"

do-install:
	${MKDIR} ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/src/vboxguest/vboxguest.ko \
	    ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxvfs.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_LIB} ${VBOX_BIN}/pam_vbox.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${VBOX_SBINS:S|^|${VBOX_BIN}/|} \
	    ${STAGEDIR}${PREFIX}/sbin/

do-install-X11-on:
	${INSTALL_PROGRAM} ${VBOX_BIN}/VBoxClient ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/98vboxadd-xclient \
	    ${STAGEDIR}${PREFIX}/bin/VBoxClient-all
	# X11 autostart
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart/
	${INSTALL_DATA} \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
	    ${STAGEDIR}${PREFIX}/etc/xdg/autostart/
	# KDE autostart
	${MKDIR} ${STAGEDIR}${PREFIX}/share/autostart/
	${INSTALL_DATA} \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
	    ${STAGEDIR}${PREFIX}/share/autostart/
	${MKDIR} ${STAGEDIR}${VIDEODIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxvideo_drv_system.so \
	    ${STAGEDIR}${VIDEODIR}/vboxvideo_drv.so
	${MKDIR} ${STAGEDIR}${INPUTDIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxmouse_drv_system.so \
	    ${STAGEDIR}${INPUTDIR}/vboxmouse_drv.so

.include <bsd.port.post.mk>
