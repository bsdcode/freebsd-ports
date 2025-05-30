PORTNAME=	pytest4-cache
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/4//}-${PORTVERSION}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Pytest plugin with mechanisms for caching across test runs (legacy version for pytest 4)
WWW=		https://bitbucket.org/hpk42/pytest-cache/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expiring devel/py-pytest4
EXPIRATION_DATE=2025-06-21

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pytest-cache

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest4>=2.2:devel/py-pytest4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}execnet>=1.2:sysutils/py-execnet@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest4>0:devel/py-pytest4@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP}
TEST_TARGET=	test
PYDISTUTILS_PKGNAME=	${PORTNAME:C/4//}

.include <bsd.port.mk>
