PORTNAME=	fast-histogram
DISTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast simple 1D and 2D histograms
WWW=		https://github.com/astrofrog/fast-histogram

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fast_histogram/_histogram_core*.so

.include <bsd.port.mk>
