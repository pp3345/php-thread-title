#ifndef PHP_THREAD_TITLE_H
#define PHP_THREAD_TITLE_H

extern zend_module_entry thread_title_module_entry;
#define phpext_thread_title_ptr &thread_title_module_entry

#define PHP_THREAD_TITLE_VERSION "1.0"

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_THREAD_TITLE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
