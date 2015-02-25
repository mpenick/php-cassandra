#include "cassandra_cluster.h"

static zend_function_entry cluster_methods[] = {
  PHP_FE_END
};

void cassandra_init_Cluster(TSRMLS_D) {
  zend_class_entry ce;
  
  INIT_CLASS_ENTRY(ce, "cassandra\\Cluster", cluster_methods);
  ce.create_object = php_cluster_new;
  cassandra_ce_Cluster = zend_register_internal_class(&ce TSRMLS_CC);
}
