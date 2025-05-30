PORTNAME=	typo3
DISTVERSION=	${PORT_V_MAJOR}.${PORT_V_MINOR}.${PORT_V_PATCH}
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://typo3.azureedge.net/typo3/${DISTVERSION}/
PKGNAMESUFFIX=	-${PORT_V_MAJOR}${PHP_PKGNAMESUFFIX}
DISTNAME=	${TYPO3SRC}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	Typo3 content management system
WWW=		https://typo3.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe php:web,flavors shebangfix
USE_PHP=	ctype dom fileinfo filter intl session simplexml tokenizer xml \
		zip

WRKSRC=		${WRKDIR}/${TYPO3SRC}
SHEBANG_GLOB=	*.php *.sh
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^${PORT_V_MAJOR}\.${PORT_V_MINOR}\.
SUB_FILES=	pkg-message
SUB_LIST+=	PREFIX=${PREFIX} \
		TYPO3DIR=${TYPO3DIR} \
		TYPO3WWW=${TYPO3WWW}

PORT_V_MAJOR=	11
PORT_V_MINOR=	5
PORT_V_PATCH=	40

TYPO3WWW=	www
TYPO3SRC=	${PORTNAME}_src-${DISTVERSION}
TYPO3DIR=	${PORTNAME}-${PORT_V_MAJOR}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

OPTIONS_DEFINE=		CURL GD GMP IMAGICK MBSTRING MYSQL POSTGRES SQLITE X11 ZLIB
OPTIONS_DEFAULT=	MYSQL
GD_DESC=		GDlib/freetype support
IMAGICK_DESC=		${IMAGEMAGICK_DESC}
MBSTRING_DESC=		${MULTIBYTE_DESC}
MYSQL_DESC=		Use MySQL as DBMS
POSTGRES_DESC=		Use PostgreSQL as DBMS
SQLITE_DESC=		Use SQLite as DBMS

CURL_USE=	PHP=curl
GD_USE=		PHP=gd
GMP_USE=	PHP=gmp
MBSTRING_USE=	PHP=mbstring
MYSQL_USE=	PHP=mysqli
POSTGRES_USE=	PHP=pgsql
SQLITE_USE=	PHP=sqlite3
ZLIB_USE=	PHP=zlib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
USES+=		magick:7,run
.else
USES+=		magick:7,run,nox11
.endif
.endif

do-install:
# workaround fix for:
# "Checking for items in STAGEDIR missing from pkg-plist"
# "Error: Orphaned: @dir %%WWWDIR%%_src-10.4.16/vendor/symfony/string/Resources/bin"
	${RMDIR} ${WRKSRC}/vendor/symfony/string/Resources/bin
# remove source empty directory
	${MKDIR} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/
	${LN} -fs ../${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/typo3_src
	${LN} -fs typo3_src/index.php ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/index.php
	${LN} -fs typo3_src/typo3 ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/typo3

post-install:
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3DIR}/*" | \
		${SORT} >> ${TMPPLIST}; \
		${ECHO} "@owner ${WWWOWN}" >> ${TMPPLIST}; \
		${ECHO} "@dir ${TYPO3WWW}/${TYPO3DIR}" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; \
		${ECHO} "@owner" >> ${TMPPLIST}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3SRC}/*" | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
