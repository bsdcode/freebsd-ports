PORTNAME=	CommonMark
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	commonmark-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Python parser for the CommonMark Markdown spec
WWW=		https://github.com/rtfd/CommonMark-py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
