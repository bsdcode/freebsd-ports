PORTNAME=	kross-interpreters
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	lang kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Language interpreters to enable in-process scripting with Kross
WWW=		https://techbase.kde.org/Development/Tutorials/Kross/Introduction

DEPRECATED=	Development discontinued, not shipped with the next KDE Gear release
EXPIRATION_DATE=	2025-05-30

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	kross \
		ecm:build
USE_QT=		core gui script widgets xml \
		buildtools:build qmake:build

CFLAGS+=	-fdeclspec

OPTIONS_DEFINE=		RUBY DOCS
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_PythonLibs

RUBY_USES=		ruby
RUBY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Ruby

KDE_APPLICATIONS_VERSION=	24.12.3

.include <bsd.port.mk>
