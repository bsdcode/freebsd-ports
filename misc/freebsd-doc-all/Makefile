PORTNAME=	freebsd-doc-all
PORTVERSION=	20250708
PORTEPOCH=	1
CATEGORIES=	misc docs

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Documentation from the FreeBSD Documentation Project

RUN_DEPENDS+=	bn-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-bn		\
		da-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-da		\
		de-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-de		\
		el-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-el		\
		en-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-en		\
		es-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-es		\
		fr-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-fr		\
		hu-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-hu		\
		id-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-id		\
		it-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-it		\
		ja-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-ja		\
		ko-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-ko		\
		mn-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-mn		\
		nl-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-nl		\
		pl-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-pl		\
		pt-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-pt		\
		ru-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-ru		\
		tr-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-tr		\
		zh_cn-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-zh_cn	\
		zh_tw-freebsd-doc>=${PORTVERSION}:misc/freebsd-doc-zh_tw

USES=		metaport

.if make(package)
DEPENDS_TARGET="package"
.endif

.include <bsd.port.mk>
