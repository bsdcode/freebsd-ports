PORTNAME=	kdeutils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of utilities for KDE (meta port)
WWW=		https://www.kde.org/applications/utilities/

USES=		kde:6 metaport

OPTIONS_DEFINE=	ARK FILELIGHT KCALC KCHARSELECT KDEBUGSETTINGS \
		KDF KGPG KTEATIME KTIMER KWALLETMANAGER \
		PRINTMANAGER

OPTIONS_DEFAULT=${OPTIONS_DEFINE:NKGPG}
OPTIONS_DEFAULT_aarch64=	KGPG
OPTIONS_DEFAULT_amd64=	KGPG
OPTIONS_DEFAULT_i386=	KGPG

ARK_DESC=			Archiving tool
ARK_RUN_DEPENDS=		ark>=${KDE_APPLICATIONS_VERSION}:archivers/ark

FILELIGHT_DESC=			Map of concentric segmented-rings representing file system
FILELIGHT_RUN_DEPENDS=		filelight>=${KDE_APPLICATIONS_VERSION}:sysutils/filelight

KCALC_DESC=			Scientific calculator
KCALC_RUN_DEPENDS=		kcalc>=${KDE_APPLICATIONS_VERSION}:math/kcalc

KCHARSELECT_DESC=		Character selector
KCHARSELECT_RUN_DEPENDS=	kcharselect>=${KDE_APPLICATIONS_VERSION}:deskutils/kcharselect

KDEBUGSETTINGS_DESC=		KDE application to enable/disable qCDebug
KDEBUGSETTINGS_RUN_DEPENDS=	kdebugsettings>=${KDE_APPLICATIONS_VERSION}:sysutils/kdebugsettings

KDF_DESC=			Shows free space of devices
KDF_RUN_DEPENDS=		kdf>=${KDE_APPLICATIONS_VERSION}:sysutils/kdf

KGPG_DESC=			Encryption tool for KDE
KGPG_RUN_DEPENDS=		kgpg>=${KDE_APPLICATIONS_VERSION}:security/kgpg

KTEATIME_DESC=			Handy timer for steeping tea
KTEATIME_RUN_DEPENDS=		kteatime>=${KDE_APPLICATIONS_VERSION}:x11-clocks/kteatime

KTIMER_DESC=			Countdown launcher
KTIMER_RUN_DEPENDS=		ktimer>=${KDE_APPLICATIONS_VERSION}:x11-clocks/ktimer

KWALLETMANAGER_DESC=		Password manager for KDE
KWALLETMANAGER_RUN_DEPENDS=	kwalletmanager>=${KDE_APPLICATIONS_VERSION}:security/kwalletmanager

.include <bsd.port.mk>
