PORTNAME=	cellranger
DISTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Translate Spreadsheet Cell Ranges to Rows and Columns
WWW=		https://github.com/rsheets/cellranger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-rematch>0:textproc/R-cran-rematch \
		R-cran-tibble>0:devel/R-cran-tibble
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=1.0.0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
