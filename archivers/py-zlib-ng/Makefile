PORTNAME=	zlib-ng
DISTVERSION=	0.5.1
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zlib_ng-${PORTVERSION}

MAINTAINER=	osidorkin@gmail.com
COMMENT=	Python bindings for the zlib-ng library
WWW=		https://github.com/pycompression/python-zlib-ng

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=51:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioningit>=2.0.0:devel/py-versioningit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist pep517

OPTIONS_DEFINE=			SYSTEM_ZLIB_NG

SYSTEM_ZLIB_NG_DESC=		Use archivers/zlib-ng instead of bundled version

SYSTEM_ZLIB_NG_LIB_DEPENDS=	libz-ng.so:archivers/zlib-ng
SYSTEM_ZLIB_NG_MAKE_ENV=	PYTHON_ZLIB_NG_LINK_DYNAMIC=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME:S/-/_/}/${PORTNAME:S/-/_/}.cpython-${PYTHON_VER:S/.//}.so

.include <bsd.port.mk>
