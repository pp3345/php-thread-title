#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_thread_title.h"
#include <sys/prctl.h>

ZEND_FUNCTION(set_thread_title) {
	char *title;
	size_t title_length;

	if(zend_parse_parameters(ZEND_NUM_ARGS(), "s", &title, &title_length) == FAILURE) {
		RETURN_FALSE;
	}

	if(prctl(PR_SET_NAME, title) == -1) {
		zend_error(E_WARNING, "Unable to set thread title: %s", strerror(errno));
		RETURN_FALSE;
	}

	RETURN_TRUE;
}

const zend_function_entry thread_title_functions[] = {
	ZEND_FE(set_thread_title, NULL)
	PHP_FE_END
};


zend_module_entry thread_title_module_entry = {
	STANDARD_MODULE_HEADER,
	"thread_title",
	thread_title_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_THREAD_TITLE_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_THREAD_TITLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(thread_title)
#endif

