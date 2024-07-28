--- ruby/video/opengl/opengl.hpp.orig	2024-07-28 21:40:16 UTC
+++ ruby/video/opengl/opengl.hpp
@@ -18,7 +18,7 @@
 
 #include "bind.hpp"
 #include "utility.hpp"
-#include "librashader_ld.h"
+#include <librashader/librashader_ld.h>
 
 struct OpenGL;
 
