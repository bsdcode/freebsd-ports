PORTNAME=	lci
PORTVERSION=	0.11.2
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Original LOLCODE interpreter
WWW=		https://lolcode.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	justinmeza

USES=		cmake readline
CFLAGS+=	${CPPFLAGS}
PLIST_FILES=	bin/lci

.include <bsd.port.mk>
