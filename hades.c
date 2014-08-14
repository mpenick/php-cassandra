#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_hades.h"

ZEND_DECLARE_MODULE_GLOBALS(hades)

zend_class_entry *cluster_ce;

const zend_function_entry hades_functions[] = {
  PHP_FE(example, NULL)
  PHP_FE_END /* Must be the last line in hades_functions[] */
};

zend_module_entry hades_module_entry = {
  STANDARD_MODULE_HEADER,
  "Hades",
  hades_functions,
  PHP_MINIT(hades),
  PHP_MSHUTDOWN(hades),
  PHP_RINIT(hades),
  PHP_RSHUTDOWN(hades),
  PHP_MINFO(hades),
  "0.1",
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HADES
ZEND_GET_MODULE(hades)
#endif

PHP_MINIT_FUNCTION(hades)
{
  return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(hades)
{
  /* UNREGISTER_INI_ENTRIES(); */
  return SUCCESS;
}

PHP_RINIT_FUNCTION(hades)
{
  return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(hades)
{
  return SUCCESS;
}

PHP_FUNCTION(example)
{
  long number;

  if (zend_parse_paramenters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &number) != SUCCESS) {
    return;
  }

  number *= 2;

  RETURN_LONG(number);
}
