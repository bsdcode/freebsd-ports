PORTNAME=	Scalar-List-Utils
PORTVERSION=	1.69
PORTEPOCH=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl subroutines that would be nice to have in the perl core
WWW=		https://metacpan.org/release/Scalar-List-Utils

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/List/Util/Util.so

.include <bsd.port.mk>
