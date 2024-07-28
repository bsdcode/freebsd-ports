PORTNAME=	ares
DISTVERSION=	139.20240731
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-system emulator
WWW=		https://github.com/ares-emulator/ares

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librashader.so:devel/librashader

FLAVORS=	gtk3 qt5
FLAVOR?=	${FLAVORS:[1]}

gtk3_LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3

qt5_PKGNAMESUFFIX=	-qt5

USES=		compiler:c11 compiler:c++17-lang gmake pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ares-emulator
GH_TAGNAME=	cac454a
.if ${FLAVOR:U} == gtk3
USES+=		gnome
USE_GNOME=	gtksourceview3
.elif ${FLAVOR:U} == qt5
USES+=		qt:5
USE_QT=		core gui widgets buildtools:build
.endif
USE_XORG=	x11 xext xrandr

MAKEFILE=	GNUmakefile
MAKE_ARGS=	compiler=${CC} \
		cores= \
		CPUTYPE=${CPUTYPE} \
		librashader=true \
		local=false \
		prefix=${PREFIX} \
		ruby=video.none \
		sdl2=false \
		threaded=true
.if ${FLAVOR:U} == gtk3
MAKE_ARGS+=	hiro=gtk3-se
.elif ${FLAVOR:U} == qt5
MAKE_ARGS+=	hiro=qt5
.endif

CONFLICTS_INSTALL=	ares ares-qt5

OPTIONS_DEFINE=		DEBUG DOCS LTO OPENMP SHADERS
OPTIONS_DEFAULT=	A26 ALSA AO CV FC GB GBA GLX LTO MD MS MSX MYVISION N64 \
			NG NGP OPENAL OPENMP OSS PCE PERFORMANCE PS1 SDLAUDIO \
			SDLINPUT SFC SG SHADERS SPEC UDEV UHID VULKAN WS XLIB \
			XVIDEO
OPTIONS_GROUP=		AUDIO CORES INPUT VIDEO
OPTIONS_GROUP_AUDIO=	ALSA AO OPENAL OSS PULSEAUDIO SDLAUDIO
OPTIONS_GROUP_CORES=	A26 CV FC GB GBA MD MS MSX MYVISION N64 NG NGP PCE PS1 \
			SFC SG SPEC WS
OPTIONS_GROUP_INPUT=	SDLINPUT UDEV UHID XLIB
OPTIONS_GROUP_VIDEO=	GLX VULKAN XVIDEO
OPTIONS_SINGLE=		PROFILE
OPTIONS_SINGLE_PROFILE=	ACCURACY PERFORMANCE
.if ${FLAVOR:U} == qt5
OPTIONS_EXCLUDE=	LTO # https://github.com/ares-emulator/ares/issues/1572
.endif

A26_DESC=		Atari 2600
ACCURACY_DESC=		Slower but more accurate
CV_DESC=		ColecoVision
FC_DESC=		NES / Famicom
GBA_DESC=		Game Boy Advance
GB_DESC=		Game Boy
MD_DESC=		Mega Drive / Genesis
MSX_DESC=		MSX
MS_DESC=		Master System / Mark III
MYVISION_DESC=		My Vision
N64_DESC=		Nintendo 64 (implies ${N64_IMPLIES})
NGP_DESC=		Neo Geo Pocket
NG_DESC=		Neo Geo (AES/MVS)
PCE_DESC=		PC-Engine / TurboGrafx
PERFORMANCE_DESC=	Faster but less accurate
PROFILE_DESC=
PS1_DESC=		PlayStation
SDLAUDIO_DESC=		${SDL_DESC}
SDLINPUT_DESC=		${SDL_DESC}
SFC_DESC=		SNES / Super Famicom
SG_DESC=		SG-1000
SHADERS_DESC=		Build and/or install shaders
SPEC_DESC=		ZX Spectrum
UDEV_DESC=		UDEV input support
UHID_DESC=		UHID input support
VIDEO_DESC=
VULKAN_DESC=		Vulkan rendering support (used by ${_VULKAN_USED})
WS_DESC=		WonderSwan
XLIB_DESC=		XLIB input support

A26_MAKE_ARGS=		cores+=a26
ACCURACY_MAKE_ARGS=	profile=accuracy
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MAKE_ARGS=		ruby+=audio.alsa
AO_LIB_DEPENDS=		libao.so:audio/libao
AO_MAKE_ARGS=		ruby+=audio.ao
CV_MAKE_ARGS=		cores+=cv
DEBUG_MAKE_ARGS=	build=debug
DEBUG_MAKE_ARGS_OFF=	build=optimized
FC_MAKE_ARGS=		cores+=fc
GBA_MAKE_ARGS=		cores+=gba
GB_MAKE_ARGS=		cores+=gb
GLX_USES=		gl
GLX_USE=		GL=egl
GLX_MAKE_ARGS=		ruby+=video.glx
LTO_MAKE_ARGS=		lto=true
LTO_MAKE_ARGS_OFF=	lto=false
MD_MAKE_ARGS=		cores+=md
MSX_MAKE_ARGS=		cores+=msx
MS_MAKE_ARGS=		cores+=ms
MYVISION_MAKE_ARGS=	cores+=myvision
N64_IMPLIES=		VULKAN
N64_MAKE_ARGS=		cores+=n64
N64_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ares_n64_vulkan_parallel-rdp_util_timer.cpp
NGP_MAKE_ARGS=		cores+=ngp
NG_MAKE_ARGS=		cores+=ng
OPENAL_USES=		openal
OPENAL_MAKE_ARGS=	ruby+=audio.openal
OPENMP_MAKE_ARGS=	openmp=true
OPENMP_MAKE_ARGS_OFF=	openmp=false
OSS_MAKE_ARGS=		ruby+=audio.oss
PCE_MAKE_ARGS=		cores+=pce
PERFORMANCE_MAKE_ARGS=	profile=performance
PS1_MAKE_ARGS=		cores+=ps1
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio \
			libpulse.so:audio/pulseaudio
PULSEAUDIO_MAKE_ARGS=	ruby+=audio.pulseaudio \
			ruby+=audio.pulseaudiosimple
SDLAUDIO_USES=		sdl
SDLAUDIO_USE=		SDL=sdl2
SDLAUDIO_MAKE_ARGS=	ruby+=audio.sdl \
			sdl2=true
SDLINPUT_USES=		sdl
SDLINPUT_USE=		SDL=sdl2
SDLINPUT_MAKE_ARGS=	ruby+=input.sdl \
			sdl2=true
SFC_MAKE_ARGS=		cores+=sfc
SG_MAKE_ARGS=		cores+=sg
SHADERS_RUN_DEPENDS=	${LOCALBASE}/${_SHADERS_DIR}/bilinear.slangp:games/libretro-shaders-slang
SHADERS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-desktop-ui_desktop-ui.cpp
SPEC_MAKE_ARGS=		cores+=spec
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd
UDEV_MAKE_ARGS=		ruby+=input.udev
UHID_MAKE_ARGS=		ruby+=input.uhid
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader
VULKAN_MAKE_ARGS=	vulkan=true
VULKAN_MAKE_ARGS_OFF=	vulkan=false
WS_MAKE_ARGS=		cores+=ws
XLIB_MAKE_ARGS=		ruby+=input.xlib
XVIDEO_USE=		XORG=xv
XVIDEO_MAKE_ARGS=	ruby+=video.xvideo

_SHADERS_DIR=	share/libretro/shaders/shaders_slang
_VULKAN_USED=	N64

post-patch-SHADERS-on:
	${REINPLACE_CMD} -e 's|@@SHADERS@@|${PREFIX}/${_SHADERS_DIR}/|g' \
		${WRKSRC}/desktop-ui/desktop-ui.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/desktop-ui/out/ares \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/desktop-ui/resource/ares.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/desktop-ui/resource/ares.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${MKDIR} ${STAGEDIR}${DATADIR}/Database
	cd ${WRKSRC}/mia/Database && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/Database

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
