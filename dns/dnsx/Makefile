PORTNAME=	dnsx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	DNS toolkit allow to run multiple DNS queries
WWW=		https://github.com/projectdiscovery/dnsx

LICENSE=	MIT

USES=		go:1.21,modules

GO_MODULE=	github.com/projectdiscovery/dnsx
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
