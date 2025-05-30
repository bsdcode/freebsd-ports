PORTNAME=	muon
DISTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~lattis/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Build system compatible with meson
WWW=		https://muon.build/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		ninja pkgconfig:both

BUILD_WRKSRC=	${WRKSRC}/_build
INSTALL_WRKSRC=	${WRKSRC}/_build

ALL_TARGET=
PLIST_FILES=	bin/muon \
		share/man/man1/muon.1.gz \
		share/man/man5/meson.build.5.gz
USE_CSTD=	c99
CFLAGS+=	-D__XSI_VISIBLE=1
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

do-configure:
	@(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${SH} bootstrap.sh . && \
		${SETENV} ${CONFIGURE_ENV} ./muon-bootstrap setup \
			-Dlibcurl=disabled \
			-Dlibarchive=disabled \
			-Dtracy=disabled \
			${BUILD_WRKSRC})

do-install:
	@(${SETENV} ${MAKE_ENV} ${BUILD_WRKSRC}/muon -C ${BUILD_WRKSRC} install)

.include <bsd.port.mk>
