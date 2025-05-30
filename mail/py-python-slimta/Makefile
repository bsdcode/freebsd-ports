PORTNAME=	python-slimta
PORTVERSION=	5.0.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Python libraries to send, receive, and queue email
WWW=		https://www.slimta.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=1.1rc:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycares>=1:dns/py-pycares@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysasl>=0.4.0:mail/py-pysasl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=		BOTO REDIS SASL
OPTIONS_DEFAULT=	SASL

BOTO_DESC=		Support for Amazon Web Services
REDIS_DESC=		Redis Support
SASL_DESC=		SASL Support

BOTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}
SASL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyspf>0:mail/py-pyspf@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}py3dns>0:dns/py-py3dns@${PY_FLAVOR}

.include <bsd.port.mk>
