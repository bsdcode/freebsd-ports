PORTNAME=	lv2proc
DISTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/naspro/naspro/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple command line effect processor using LV2 plugins
WWW=		https://sourceforge.net/projects/naspro/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		gmake pkgconfig tar:bz2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/lv2proc \
		share/man/man1/lv2proc.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=strict-prototypes
.endif

.include <bsd.port.mk>
