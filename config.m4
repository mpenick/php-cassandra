dnl $Id$
dnl dnl config.m4 for hades extension

PHP_ARG_ENABLE(hades, for hades support, [--with-hades Include hades support])

if test "$PHP_HADES" != "no"; then
  PHP_NEW_EXTENSION(hades, hades.c, $ext_shared)
  PHP_SUBST(HADES_SHARED_LIBADD)
fi
