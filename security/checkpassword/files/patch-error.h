--- error.h.orig
+++ error.h
@@ -1,7 +1,7 @@
 #ifndef ERROR_H
 #define ERROR_H
 
-extern int errno;
+#include <errno.h>
 
 extern int error_intr;
 extern int error_nomem;
