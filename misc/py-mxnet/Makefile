PORTNAME=	mxnet
DISTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Apache MXNet: Ultra-scalable deep learning framework
WWW=		https://mxnet.apache.org/

LICENSE=	APACHE20

DEPRECATED=	Depends on expired misc/mxnet
EXPIRATION_DATE=2025-06-01

BUILD_DEPENDS=	mxnet>0:misc/mxnet
RUN_DEPENDS=	mxnet>0:misc/mxnet \
		${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR}

USES=		python localbase
USE_GITHUB=	yes
USE_PYTHON=	distutils cython autoplist

GH_ACCOUNT=	apache
GH_PROJECT=	incubator-mxnet

WRKSRC_SUBDIR=	python

POST_PLIST=	fix-plist

PYDISTUTILS_BUILDARGS=		--with-cython
PYDISTUTILS_INSTALLARGS=	--with-cython

post-patch:
	@${REINPLACE_CMD} -e 's|dll_path = \[curr_path, api_path, cmake_build_path\]|dll_path = ["${LOCALBASE}/lib"]|' ${WRKSRC}/mxnet/libinfo.py

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}
	# https://github.com/apache/incubator-mxnet/issues/17081
	@${RM} ${STAGEDIR}${PREFIX}/mxnet/libmxnet.so
	@${RMDIR} ${STAGEDIR}${PREFIX}/mxnet

fix-plist: # see post-install
	@${REINPLACE_CMD} '/^mxnet\/libmxnet.so$$/d' ${TMPPLIST}

.include <bsd.port.mk>
