PORTNAME=	annexlib
PORTVERSION=	0.13.2
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://raevnos.pennmush.org/code/extlib/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OCaml subroutines collection
WWW=		http://raevnos.pennmush.org/code/extlib/

LICENSE=	LGPL21

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:devel/ocaml-pcre
RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:devel/ocaml-pcre

USES=		gmake ocaml:findplist,ldconfig

GNU_CONFIGURE=	yes
ALL_TARGET=	all opt
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	cd  ${STAGEDIR}${PREFIX} && \
	    ${STRIP_CMD} lib/ocaml/site-lib/annexlib/dllannexlib_stubs.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/html/* \
	    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
