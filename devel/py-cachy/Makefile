PORTNAME=	cachy
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple yet effective caching library
WWW=		https://github.com/sdispater/cachy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	MEMCACHED MSGPACK
MEMCACHED_DESC=	Memcached support
MSGPACK_DESC=	MessagePack support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=1.59<2.0:databases/py-python-memcached@${PY_FLAVOR}
MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.5:devel/py-msgpack@${PY_FLAVOR}

.include <bsd.port.mk>
