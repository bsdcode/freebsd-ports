PORTNAME=	vile
PORTVERSION=	9.8z
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://invisible-island.net/archives/vile/current/ \
		https://invisible-mirror.net/archives/vile/current/
PKGNAMEPREFIX=	x

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=	# none

MAINTAINER=	dickey@invisible-island.net
COMMENT=	VI Like Emacs -- X11 version
WWW=		https://invisible-island.net/vile/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	reflex:textproc/reflex

USES=		pkgconfig shebangfix tar:tgz xorg
SHEBANG_FILES=	macros/lxvile macros/lxvile-fonts perl/vileget
USE_XORG=	x11 xext xpm xt
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	cf_cv_crypt_works=yes
CONFIGURE_ARGS=	--disable-imake \
		--disable-desktop \
		--enable-fontset \
		--with-icon-theme \
		--with-xpm \
		--datarootdir=${PREFIX}/share/xvile \
		--with-icondir=${PREFIX}/share/icons \
		--with-libdir-path=${PREFIX}/lib/xvile \
		--with-pixmapdir=${PREFIX}/share/pixmaps \
		--with-startup-path=${PREFIX}/share/xvile
MAKEFILE=	makefile
INSTALL_TARGET=	install install-doc install-html

OPTIONS_DEFINE=		DOCS FILTERS ICONV PERL
OPTIONS_RADIO=		MENUS
OPTIONS_RADIO_MENUS=	MOTIF XAW XAW3D
OPTIONS_DEFAULT=	ICONV
OPTIONS_SUB=		yes

FILTERS_DESC=		Loadable filters
FILTERS_CONFIGURE_WITH=	loadable-filters
ICONV_USES=		iconv
ICONV_CONFIGURE_ON=	--with-iconv ${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--without-iconv --without-locale
MENUS_DESC=		Support for menus
MOTIF_USES=		motif
MOTIF_CONFIGURE_ON=	--enable-colored-menus \
			--with-screen=motif
PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl
XAW_DESC=		X Athena Widgets
XAW_USE=		XORG=xaw
XAW_CONFIGURE_ON=	--with-screen=athena
XAW3D_DESC=		X Athena Widgets with 3D effect
XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/libXaw3d
XAW3D_CONFIGURE_ON=	--enable-colored-menus \
			--with-Xaw3d \
			--with-screen=xaw3d

# fixes to make this not conflict with the "vile" port
DATADIR=		${PREFIX}/share/xvile
DOCSDIR=		${PREFIX}/share/doc/xvile

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTERS}
PLIST_SUB+=	SO_EXT=".so"
.else
PLIST_SUB+=	SO_EXT=""
.endif

.if empty(PORT_OPTIONS:MMOTIF) && empty(PORT_OPTIONS:MXAW) && empty(PORT_OPTIONS:MXAW3D)
CONFIGURE_ARGS+=	--with-screen=x11
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/doc|@prefix@/share/doc/xvile| ; \
		 s|^\(datadir[ 	]*=[ 	]*\)@datadir@.*|\1@datarootdir@| ; \
		 s|@datadir@/doc/vile|@datarootdir@/doc/xvile| ; \
		 s|$$(datadir)/html|$$(docdir)/html| ; \
		 s|$$(datadir)/perl|@datadir@/perl| ; \
		 s|$$(BINDIR)/vileget|$$(BINDIR)/xvileget| ; \
		 s|\($$(DOCDIR)\) \($$(MANDIR)\)|\1 $$(HTMLDIR) \2|' \
		${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e \
		's|^\(datadir[ 	]*=[ 	]*\)@datadir@.*|\1@datarootdir@|' \
		${WRKSRC}/filters/makefile.in

post-install:
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.desktop \
		${STAGEDIR}${PREFIX}/share/applications)

.include <bsd.port.mk>
