PHP_ARG_ENABLE(rexpro, whether to enable rexpro, [ --enable-rexpro   Enable Rexpro])

if test "$PHP_REXPRO" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, REXPRO_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_REXPRO, 1, [Whether you have Rexpro])
	rexpro_sources="rexpro.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c rexpro/client.zep.c
	rexpro/exception.zep.c
	rexpro/exception/socket.zep.c
	rexpro/message.zep.c
	rexpro/message/body.zep.c
	rexpro/message/body/request.zep.c
	rexpro/message/body/request/script.zep.c
	rexpro/message/body/request/session.zep.c
	rexpro/message/body/response.zep.c
	rexpro/message/body/response/error.zep.c
	rexpro/message/body/response/script.zep.c
	rexpro/message/body/response/session.zep.c "
	PHP_NEW_EXTENSION(rexpro, $rexpro_sources, $ext_shared,, )
	PHP_SUBST(REXPRO_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([rexpro], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([rexpro], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/rexpro], [php_REXPRO.h])

fi
