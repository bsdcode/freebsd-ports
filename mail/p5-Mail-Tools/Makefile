PORTNAME=	Mail-Tools
PORTVERSION=	2.22
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	MailTools-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules for dealing with Internet e-mail messages
WWW=		https://metacpan.org/release/MailTools

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README.md

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-TimeDate>=0:devel/p5-TimeDate

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
