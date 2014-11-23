
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_REXPRO_H
#define PHP_REXPRO_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_REXPRO_NAME        "rexpro"
#define PHP_REXPRO_VERSION     "0.0.1"
#define PHP_REXPRO_EXTNAME     "rexpro"
#define PHP_REXPRO_AUTHOR      ""
#define PHP_REXPRO_ZEPVERSION  "0.5.9a"
#define PHP_REXPRO_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(rexpro)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(rexpro)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(rexpro)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(rexpro_globals_id, zend_rexpro_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (rexpro_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_rexpro_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(rexpro_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(rexpro_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def rexpro_globals
#define zend_zephir_globals_def zend_rexpro_globals

extern zend_module_entry rexpro_module_entry;
#define phpext_rexpro_ptr &rexpro_module_entry

#endif
