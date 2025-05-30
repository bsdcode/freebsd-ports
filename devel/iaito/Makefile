PORTNAME=	iaito
DISTVERSION=	5.9.9
CATEGORIES=	devel

PATCH_SITES=	https://github.com/radareorg/iaito/commit/
PATCHFILES+=	14d843c138defd36b8550c37f067e64d6b8316fb.patch:-p1 # Fix build with Qt >= 6.9.0

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official QT frontend of radare2, a libre reverse engineering framework
WWW=		https://github.com/radareorg/iaito

LICENSE=	GPLv3

BROKEN_i386=	error: non-constant-expression cannot be narrowed from type 'const unsigned long long' to 'size_t' (aka 'unsigned int')

LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libr_core.so:devel/radare2

FLAVORS=		qt6 qt5
FLAVOR?=		qt6
qt5_PKGNAMESUFFIX=	-qt5
qt6_PKGNAMESUFFIX=	-qt6

USES=		compiler:c++17-lang desktop-file-utils gl gmake pkgconfig \
		qmake:no_configure
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GNU_CONFIGURE=	yes

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_GL=		gl
USE_QT=		core gui network svg widgets \
		buildtools:build linguisttools:build qmake:build
.else
USES+=		qt:6
USE_GL=		opengl
USE_QT=		base svg
CONFIGURE_ARGS=	--with-qmake6
.endif

MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		QMAKE_FLAGS="PREFIX=${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/iaito \
		share/applications/org.radare.iaito.desktop \
		share/icons/hicolor/scalable/apps/org.radare.iaito.svg \
		share/metainfo/org.radare.iaito.appdata.xml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/org.radare.iaito.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/img/org.radare.iaito.svg \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/src/org.radare.iaito.appdata.xml \
			${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
