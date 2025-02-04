--- chrome/browser/ui/actions/chrome_action_id.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -515,7 +515,7 @@
     IDC_CONTENT_CONTEXT_QUICK_ANSWERS_INLINE_ANSWER) \
   E(kActionContentContextQuickAnswersInlineQuery, \
     IDC_CONTENT_CONTEXT_QUICK_ANSWERS_INLINE_QUERY)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
