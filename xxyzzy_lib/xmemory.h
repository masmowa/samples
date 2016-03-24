#ifndef XMEMORY_H_INCLUDED
#define XMEMORY_H_INCLUDED
#include "stddef.h"

#define MAX_XMEM    (1024 * 100)

void* xmem_alloc(size_t size);

void xmem_free(void* mem);


#endif // XMEMORY_H_INCLUDED
