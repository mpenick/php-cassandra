#ifndef PHP_CASSANDRA_H
#define PHP_CASSANDRA_H

extern zend_module_entry cassandra_module_entry;
#define phpext_cassandra_ptr &cassandra_module_entry

#ifdef PHP_WIN32
#    define PHP_CASSANDRA_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#    define PHP_CASSANDRA_API __attribute__ ((visibility("default")))
#else
#    define PHP_CASSANDRA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(cassandra);
PHP_MSHUTDOWN_FUNCTION(cassandra);
PHP_RINIT_FUNCTION(cassandra);
PHP_RSHUTDOWN_FUNCTION(cassandra);
PHP_MINFO_FUNCTION(cassandra);

PHP_FUNCTION(example);

ZEND_BEGIN_MODULE_GLOBALS(cassandra)
  /* globals go here */
ZEND_END_MODULE_GLOBALS(cassandra)


#ifdef ZTS
#define CASSANDRA_G(v) TSRMG(cassandra_globals_id, zend_cassandra_globals *, v)
#else
#define CASSANDRA_G(v) (cassandra_globals.v)
#endif

#endif /* PHP_CASSANDRA_H */
