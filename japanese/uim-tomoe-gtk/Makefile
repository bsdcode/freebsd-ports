PORTNAME=	uim-tomoe-gtk
PORTVERSION=	0.6.0
PORTREVISION=	24
CATEGORIES=	japanese
MASTER_SITES=	SF/tomoe/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	UIM helper program for Tomoe
WWW=		https://sourceforge.jp/projects/tomoe/

LIB_DEPENDS=	libtomoe.so:japanese/tomoe \
		libtomoe-gtk.so:japanese/libtomoe-gtk \
		libuim.so:textproc/uim

USES=		gettext gmake gnome libtool pkgconfig
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/uim-tomoe-gtk \
		share/locale/ja/LC_MESSAGES/uim-tomoe-gtk.mo

CONFIGURE_ENV+=	GMSGFMT="${LOCALBASE}/bin/msgfmt"

.include <bsd.port.mk>
