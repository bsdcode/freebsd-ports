PORTNAME=	kdenlive
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite
WWW=		https://www.kdenlive.org

LICENSE=	GPLv2

LIB_DEPENDS=	librttr_core.so:devel/rttr
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/lib/mlt-7/libmltglaxnimate-qt6.so:multimedia/mlt7-glaxnimate@qt6
RUN_DEPENDS=	ffmpeg${FFMPEG_SUFX}:multimedia/ffmpeg${FFMPEG_SUFX} \
		${LOCALBASE}/lib/mlt-7/libmltqt6.so:multimedia/mlt7-qt@qt6 \
		${LOCALBASE}/lib/mlt-7/libmltglaxnimate-qt6.so:multimedia/mlt7-glaxnimate@qt6

USES=		cmake compiler:c++11-lang desktop-file-utils gettext-tools gl \
		kde:6 mlt:7 pkgconfig qt:6 shared-mime-info tar:xz xorg
USE_GL=		gl glu
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons filemetadata \
		guiaddons i18n iconthemes itemviews jobwidgets kdeclarative \
		kio newstuff notifications notifyconfig package service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		qqc2-desktop-style:run \
		ecm:build
USE_QT=		base networkauth
USE_XORG=	x11
CFLAGS+=	-isystem${LOCALBASE}/include # linux/input.h
CMAKE_ARGS=	-DFFMPEG_SUFFIX:STRING="${FFMPEG_SUFX}"

# Keep in sync with multimedia/mlt, possibly.
FFMPEG_SUFX=	# Currently empty.

OPTIONS_DEFINE=	DVDWIZARD FILESHARE FREI0R LADSPA SCREENCAST V4L XINE DOCS
OPTIONS_DEFAULT=DVDWIZARD FILESHARE FREI0R LADSPA SCREENCAST V4L
OPTIONS_SUB=	yes

DVDWIZARD_DESC=	DVD authoring via DVDAuthor and cdrtools
FILESHARE_DESC=	Common KF6 filesharing support
SCREENCAST_DESC=Screen capture support via recordMyDesktop
V4L_DESC=	Webcam support via Video4Linux
XINE_DESC=	DVD preview support via xine

DVDWIZARD_RUN_DEPENDS=	dvdauthor:multimedia/dvdauthor \
			cdrecord:sysutils/cdrtools

FILESHARE_USE=	KDE=purpose
FILESHARE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF6Purpose

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

SCREENCAST_RUN_DEPENDS=	recordmydesktop:multimedia/recordmydesktop

V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CMAKE_OFF=		-DWITH_LibV4L2:BOOL=FALSE

XINE_RUN_DEPENDS=	xine:multimedia/xine

post-patch:
	@${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		-e '/SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/data/CMakeLists.txt

.include <bsd.port.mk>
