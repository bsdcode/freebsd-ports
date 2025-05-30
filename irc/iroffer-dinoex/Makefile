PORTNAME=	iroffer
PORTVERSION=	3.33
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	https://iroffer.net/
PKGNAMESUFFIX=	-dinoex${PKGNAMESUFFIX2}
DISTNAME=	iroffer-dinoex-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	IRC "bot" that makes sharing files via DCC extremely easy
WWW=		https://iroffer.net/

LICENSE=	GPLv2

CONFLICTS=	iroffer-1* iroffer-lamm-1.*

USES=		ssl
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	CC="${CC}" LDFLAGS="${LDFLAGS}" LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV=	LANG=en_EN.UTF-8
MAKE_ENV=	LANG=en_EN.UTF-8
ALL_TARGET=	all-lang doc
USE_RC_SUBR=	iroffer

IROFFER_DOCS=	README README.modDinoex LIESMICH.modDinoex \
		LICENSE THANKS TODO \
		help-admin-de.txt help-admin-en.txt \
		help-admin-fr.txt help-admin-it.txt \
		doc/iroffer.1.txt doc/iroffer.1.html doc/iroffer.1.ps \
		doc/INSTALL-linux-de.html doc/INSTALL-linux-de.txt \
		doc/INSTALL-linux-en.html doc/INSTALL-linux-en.txt \
		doc/INSTALL-linux-fr.html doc/INSTALL-linux-fr.txt \
		doc/INSTALL-linux-it.html doc/INSTALL-linux-it.txt \
		doc/INSTALL-vhost-de.html doc/INSTALL-vhost-de.txt \
		doc/INSTALL-vhost-en.html doc/INSTALL-vhost-en.txt \
		doc/INSTALL-vhost-fr.html doc/INSTALL-vhost-fr.txt
IROFFER_EXAMPLES=	iroffer.cron \
		sample.config beispiel.config exemple.config \
		header.html footer.html ruby-sample.rb
IROFFER_HTDOCS=	iroffer-state.css robots.txt \
		info.txt.rb list.json.rb md5.txt.rb sfv.txt.rb

OPTIONS_DEFINE=	CURL RUBY UPNP GEOIP DOCS EXAMPLES
OPTIONS_DEFAULT=CURL RUBY UPNP GEOIP

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	-curl
RUBY_USES=		ruby
RUBY_LIB_DEPENDS=	libruby${RUBY_SHLIBVER}.so:${RUBY_PORT}
RUBY_CONFIGURE_ON=	-ruby
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CONFIGURE_ON=	-upnp
GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_CONFIGURE_ON=	-geoip

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MRUBY}
# make stage-qa happy
# keep in sync with all platforms where libunwind is available
.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer-de ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer-it ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer-fr ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/iroffer.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/xdcc.7 ${STAGEDIR}${PREFIX}/share/man/man7/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${IROFFER_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/htdocs
.for i in ${IROFFER_HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/${i} ${STAGEDIR}${EXAMPLESDIR}/htdocs/
.endfor
.for i in ${IROFFER_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EXAMPLESDIR}/
.endfor

.include <bsd.port.post.mk>
