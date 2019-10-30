/*
 * A macro-based generic vector.
 *
 * Requires a C11 compiler with support for various GCC extensions.
 *
 * -----------------------------------------------------------------------------
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Marc Tiehuis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef QVEC_H
#define QVEC_H

#include <stdio.h>
#include <stdlib.h>

#define QVEC_ALEN(a) (sizeof(a) / sizeof(*a))

#define qvec_base       \
    struct {            \
        size_t cap, len;\
    }

#define qvec(T,N)         \
    struct qvec_##T_##N {   \
        qvec_base;      \
        T data[];       \
    }

#define qvec_new(T,N, xs...)                                                         \
({                                                                                   \
    const T _xs[] = {xs};                                                            \
    struct qvec_##T_##N *v = malloc(sizeof(qvec(T,N)) + sizeof(T) * QVEC_ALEN(_xs)); \
    v->cap = sizeof(_xs) / sizeof(T);                                                \
    v->len = QVEC_ALEN(_xs);                                                         \
                                                                                     \
    for (int i = 0; i < v->len; ++i)                                                 \
        v->data[i] = _xs[i];                                                         \
                                                                                     \
    v;                                                                               \
})

#define qvec_free(v) free(v)

#define qvec_pop(v) (v->data[--v->len])

#define qvec_ref(v, i) (&v->data[i])

#define qvec_at(v, i) (*(qvec_ref(v, i)))

#define qvec_push(v, i)                                  \
({                                                      \
        v->cap += sizeof(i);                            \
        typeof(v) tem =realloc(v, (2* sizeof(i) + v->cap * sizeof(v)) ) ;\
        v =  tem;    \
                                                        \
    v->data[v->len++] = (i);                            \
})

#define GET_FMT_SPEC(x) _Generic((x), int: "%d", float: "%f", char*: "%s")

#define qvec_print(v)                                                   \
({                                                                      \
    printf("[");                                                        \
    for (int i = 0; i < v->len; ++i) {                                  \
        printf(GET_FMT_SPEC(v->data[i]), v->data[i]);                   \
        if (i + 1 < v->len)                                             \
            printf(", ");                                               \
    }                                                                   \
    printf("]\n");                                                      \
})

#ifdef QVEC_USE_RAII
static inline _qvec_free(void **qvec) { free(*qvec); }
#define raii __attribute__ ((cleanup(_qvec_free)))
#endif

#endif