PORTNAME=	libmt32emu
DISTVERSION=	2_7_1
CATEGORIES=	devel

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Emulate Roland MT-32, CM-32L and LAPC-I synthesiser modules
WWW=		https://munt.sourceforge.net

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER.txt

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	munt
GH_PROJECT=	munt
GH_TAGNAME=	${PORTNAME}_${DISTVERSION}
USE_LDCONFIG=	yes

CMAKE_ARGS=	-Dlibmt32emu_PKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata

DOCSDIR=	${PREFIX}/share/doc/${GH_PROJECT}/${PORTNAME}
EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT}-${GH_TAGNAME}/mt32emu \
			--no-same-owner --no-same-permissions

WRKSRC_SUBDIR=	mt32emu

OPTIONS_DEFINE=			DOCS
OPTIONS_DEFAULT=		LIBSOXR
OPTIONS_RADIO=			RESAMPLER
OPTIONS_RADIO_RESAMPLER=	INTERNAL LIBSAMPLERATE LIBSOXR

INTERNAL_DESC=		Built-in samplerate conversion
LIBSAMPLERATE_DESC=	Build with libsamplerate support
LIBSOXR_DESC=		Build with libsoxr support

INTERNAL_CMAKE_BOOL=	libmt32emu_WITH_INTERNAL_RESAMPLER

LIBSAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

LIBSOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr

.include <bsd.port.mk>
