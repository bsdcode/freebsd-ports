PORTNAME=	Test-Dependencies
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ensure that your Makefile.PL specifies all module dependencies
WWW=		https://metacpan.org/release/Test-Dependencies

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Find-Rule-Perl>=0:devel/p5-File-Find-Rule-Perl \
		p5-IPC-Cmd>=0:devel/p5-IPC-Cmd \
		p5-Pod-Strip>=0:textproc/p5-Pod-Strip \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
