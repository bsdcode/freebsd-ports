PORTNAME=	yandex-money-sdk
PORTVERSION=	0.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	SDK yandex money API
WWW=		https://pypi.org/project/yandex-money-sdk/

LICENSE=	MIT

DEPRECATED=	Dead project. Yandex.Money is no more
EXPIRATION_DATE=	2025-02-11

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.4.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
