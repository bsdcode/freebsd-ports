PORTNAME=	twemoji-color-font-ttf
PORTVERSION=	15.1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/eosrei/twemoji-color-font/releases/download/v${PORTVERSION}/
DISTNAME=	TwitterColorEmoji-SVGinOT-Linux-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Color emoji font using Twitter Unicode 10
WWW=		https://github.com/eosrei/twemoji-color-font

LICENSE=	CC-BY-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-4.0=	${WRKSRC}/LICENSE-CC-BY.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/TwitterColorEmoji-SVGinOT.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
