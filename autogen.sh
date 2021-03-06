#! /bin/sh -e
test -n "$srcdir" || srcdir=`dirname "$0"`
test -n "$srcdir" || srcdir=.

autoreconf --verbose --force --install --warnings=all "$srcdir"
test -n "$NOCONFIGURE" || "$srcdir/configure" --enable-maintainer-mode "$@"

