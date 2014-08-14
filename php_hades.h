#ifndef PHP_HADES_H
#define PHP_HADES_H

extern zend_module_entry hades_module_entry;
#define phpext_hades_ptr &hades_module_entry

#ifdef PHP_WIN32
#    define PHP_HADES_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#    define PHP_HADES_API __attribute__ ((visibility("default")))
#else
#    define PHP_HADES_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(hades);
PHP_MSHUTDOWN_FUNCTION(hades);
PHP_RINIT_FUNCTION(hades);
PHP_RSHUTDOWN_FUNCTION(hades);
PHP_MINFO_FUNCTION(hades);

PHP_FUNCTION(example);

ZEND_BEGIN_MODULE_GLOBALS(hades)
  /* globals go here */
ZEND_END_MODULE_GLOBALS(hades)


#ifdef ZTS
#define HADES_G(v) TSRMG(hades_globals_id, zend_hades_globals *, v)
#else
#define HADES_G(v) (hades_globals.v)
#endif

#endif /* PHP_HADES_H */
