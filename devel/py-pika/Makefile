PORTNAME=	pika
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python AMQP Client Library
WWW=		https://pika.readthedocs.io

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR}

# 2.7,3.4-3.7
USES=		python
USE_GITHUB=	yes #  tests not packaged in PyPI sdist
USE_PYTHON=	autoplist distutils nose2

NO_ARCH=	yes

.include <bsd.port.mk>
