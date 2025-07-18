PORTNAME=	guacamole-server
DISTVERSION=	1.6.0
CATEGORIES=	net
MASTER_SITES=	APACHE/guacamole/${DISTVERSION}/source/

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	HTML5 Clientless Remote Desktop
WWW=		https://guacamole.incubator.apache.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libossp-uuid.so:misc/ossp-uuid \
		libpng.so:graphics/png

CONFLICTS_BUILD=pulseaudio-*+jack_* ffmpeg-*+jack_*

USES=		autoreconf compiler:c11 gnome jpeg libtool localbase pkgconfig \
		shebangfix

USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_RC_SUBR=	guacd
SHEBANG_FILES=	${WRKSRC}/src/protocols/rdp/keymaps/generate.pl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-guacd-conf=${ETCDIR}/guacd.conf
INSTALL_TARGET=	install-strip
CFLAGS+=	-Wno-error=newline-eof

GUACAMOLE_HOME?=	${PREFIX}/guacamole
USERS=		guacamole
GROUPS=		guacamole

SUB_LIST=	GUACD_USER=${USERS} \
		GUACD_GROUP=${GROUPS} \
		GUACD_HOME=${GUACAMOLE_HOME}

PLIST_SUB=	GUACD_USER=${USERS} \
		GUACD_GROUP=${GROUPS} \
		GUACD_HOME=${GUACAMOLE_HOME}

OPTIONS_DEFINE=		GUACENC GUACLOG NLS SSL WEBP
OPTIONS_DEFAULT=	GUACENC GUACLOG KUBERNETES PULSEAUDIO RDP \
			SSH SSL VNC VORBIS WEBP
OPTIONS_GROUP=		SP AUDIO
OPTIONS_GROUP_SP=	KUBERNETES RDP SSH VNC
OPTIONS_GROUP_AUDIO=	VORBIS PULSEAUDIO
OPTIONS_SUB=		yes

AUDIO_DESC=		Audio Support
GUACENC_DESC=		Video Encoding Utility
GUACLOG_DESC=		Input log interpreter
KUBERNETES_DESC=	Kubernetes protocol support
RDP_DESC=		RDP protocol support
SP_DESC=		Supported Protocols
VNC_DESC=		VNC protocol support

GUACENC_CONFIGURE_ENABLE=	guacenc
GUACENC_CONFIGURE_WITH=		libavcodec libavutil libswscale
GUACENC_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
GUACENC_CFLAGS=		-Wno-error=deprecated
GUACLOG_CONFIGURE_ENABLE=	guaclog
KUBERNETES_CONFIGURE_ENABLE=	kubernetes
KUBERNETES_LIB_DEPENDS=		libwebsockets.so:net/libwebsockets \
				libharfbuzz.so:print/harfbuzz
NLS_USES=		gettext-runtime
PULSEAUDIO_CONFIGURE_WITH=	pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
RDP_CONFIGURE_WITH=	rdp
RDP_LIB_DEPENDS=	libfreerdp2.so:net/freerdp
SSH_CONFIGURE_WITH=	ssh
SSH_IMPLIES=		SSL
SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSL_CONFIGURE_WITH=	ssl
SSL_USES=		ssl
VNC_CONFIGURE_WITH=	vnc
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VORBIS_CONFIGURE_WITH=	vorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKUBERNETES}${PORT_OPTIONS:MSSH}
CONFIGURE_ARGS+=	--with-pango --with-terminal
PLIST_SUB+=		TERMINAL=""
USE_GNOME+=		pango
.else
CONFIGURE_ARGS+=	--without-pango --without-terminal
PLIST_SUB+=		TERMINAL="@comment "
.endif

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=strict-prototypes \
			   -Wno-error=unused-but-set-variable
.endif

post-patch:
	@${REINPLACE_CMD} 's/-Werror//' ${WRKSRC}/src/libguac/Makefile.am \
		${WRKSRC}/src/protocols/vnc/Makefile.am
	@${REINPLACE_CMD} 's|/etc/ssl|${PREFIX}/etc/ssl|g ; \
			 s|/etc/guacamole|${ETCDIR}|g' \
			 ${WRKSRC}/src/guacd/man/guacd.conf.5.in

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${GUACAMOLE_HOME}
	${INSTALL_DATA} ${FILESDIR}/guacd.conf.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
