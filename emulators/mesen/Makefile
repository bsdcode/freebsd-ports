PORTNAME=	mesen
DISTVERSION=	0.9.9
CATEGORIES=	emulators

MAINTAINER=	cpetrik@proton.me
COMMENT=	Cross-platform Nintendo Entertainment System (NES/Famicom) emulator
WWW=		https://www.mesen.ca/

LICENSE=	GPLv3

# ARM/MIPS are only supported on Android
ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	zip:archivers/zip \
		evdev-proto>0:devel/evdev-proto \
		msbuild:devel/msbuild
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libgdiplus.so:x11-toolkits/libgdiplus

USES=		compiler:c++17-lang gmake pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	SourMesen
GH_PROJECT=	Mesen
USE_SDL=	sdl2
MAKEFILE=	makefile
MAKE_ARGS=	MESENPLATFORM=${MESEN_ARCH} \
		CC="${CC}" CPPC="${CXX}" \
		FSLIB=-lc++experimental \
		LTO=true \
		SYSTEM_LIBEVDEV=true
MESEN_ARCH=	${ARCH:S/amd64/x64/:S/i386/x86/}

OPTIONS_MULTI=			FRONTENDS
OPTIONS_MULTI_FRONTENDS=	MONO LIBRETRO
OPTIONS_DEFAULT=		MONO LIBRETRO
OPTIONS_SUB=			yes

MONO_DESC=	Mono based GUI frontend
LIBRETRO_DESC=	Libretro core

MONO_ALL_TARGET=	ui
MONO_BUILD_DEPENDS=	mono:lang/mono${MONO_DEFAULT}
MONO_RUN_DEPENDS=	mono:lang/mono${MONO_DEFAULT}
MONO_DESKTOP_ENTRIES=	"Mesen" "NES/Famicom Emulator" \
			"${PORTNAME}" "${PORTNAME}" "Game;Emulator;" false

LIBRETRO_ALL_TARGET=	libretro

.include <bsd.port.pre.mk>

.if defined(MONO_DEFAULT) && ${MONO_DEFAULT} > 6
BROKEN=		fails to build with Mono version ${MONO_DEFAULT}: error MSB4184: The expression ""Program.cs".GetPathsOfAllDirectoriesAbove()" cannot be evaluated. Method 'System.String.GetPathsOfAllDirectoriesAbove' not found.
.endif

do-install: 	# empty to avoid default

do-install-MONO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/mesen
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	${INSTALL_LIB} ${WRKSRC}/bin/${MESEN_ARCH}/Release/Dependencies/libMesenCore.${MESEN_ARCH}.dll \
			${STAGEDIR}${PREFIX}/libexec/mesen/libMesenCore.dll
	${INSTALL_DATA} ${WRKSRC}/bin/${MESEN_ARCH}/Release/Mesen.exe \
			${STAGEDIR}${PREFIX}/libexec/mesen/
	${INSTALL_DATA} ${WRKSRC}/GUI.NET/Resources/MesenIcon.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/mesen.png
	${INSTALL_DATA} ${WRKSRC}/GUI.NET/Resources/MesenIconMedium.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/mesen.png
	${INSTALL_DATA} ${WRKSRC}/GUI.NET/Resources/MesenIconSmall.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/mesen.png
	${INSTALL_SCRIPT} ${FILESDIR}/launch.sh ${STAGEDIR}${PREFIX}/bin/mesen
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${STAGEDIR}${PREFIX}/bin/mesen

do-install-LIBRETRO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/bin/mesen_libretro.${MESEN_ARCH}.so \
			${STAGEDIR}${PREFIX}/lib/libretro/mesen_libretro.so

.include <bsd.port.post.mk>
