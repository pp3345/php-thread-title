PHP_ARG_ENABLE(thread_title, whether to enable thread_title support,
[  --enable-thread_title           Enable thread_title support])

if test "$PHP_THREAD_TITLE" != "no"; then
  PHP_NEW_EXTENSION(thread_title, thread_title.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
