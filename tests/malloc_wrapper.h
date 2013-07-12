/*
 * nghttp2 - HTTP/2.0 C Library
 *
 * Copyright (c) 2012 Tatsuhiro Tsujikawa
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef MALLOC_WRAPPER_H
#define MALLOC_WRAPPER_H

#include <stdlib.h>

/* Global variables to control the behavior of malloc() */

/* If nonzero, malloc failure mode is on */
extern int nghttp2_failmalloc;
/* If nghttp2_failstart <= nghttp2_nmalloc and nghttp2_failmalloc is
   nonzero, malloc() fails. */
extern int nghttp2_failstart;
/* If nonzero, nghttp2_nmalloc is incremented if malloc() succeeds. */
extern int nghttp2_countmalloc;
/* The number of successful invocation of malloc(). This value is only
   incremented if nghttp2_nmalloc is nonzero. */
extern int nghttp2_nmalloc;

void* malloc(size_t size);

/* Copies nghttp2_failmalloc and nghttp2_countmalloc to statically
   allocated space and sets 0 to them. This will effectively make
   malloc() work like normal malloc(). This is useful when you want to
   disable malloc() failure mode temporarily. */
void nghttp2_failmalloc_pause(void);

/* Restores the values of nghttp2_failmalloc and nghttp2_countmalloc
   with the values saved by the previous
   nghttp2_failmalloc_pause(). */
void nghttp2_failmalloc_unpause(void);

#endif /* MALLOC_WRAPPER_H */
