PORTNAME=	3270font
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/rbanffy/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	3270_fonts_d916271

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	IBM 3270 font for the nostalgic
WWW=		https://github.com/rbanffy/3270font

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts zip

FONTNAME=	3270

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${FONTSDIR} "! -name LICENSE.txt")

.include <bsd.port.mk>
