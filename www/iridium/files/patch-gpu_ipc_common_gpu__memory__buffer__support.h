--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2025-05-07 06:48:23 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.h
@@ -21,7 +21,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 namespace gfx {
 class ClientNativePixmapFactory;
 }  // namespace gfx
