#include <stdio.h>
#include <stdlib.h>
#include "xmemory.h"

#define BLOCK_SIZE 1024
#define MAX_XMEM_BLOCKS 100

void simple_test()
{
    void* mem[MAX_XMEM_BLOCKS] = {0};
    size_t i = 0;

    for (i=0; i < MAX_XMEM_BLOCKS; ++i)
    {
        printf("+++ xmem_alloc(%d)\n", BLOCK_SIZE);
        mem[i] = xmem_alloc(BLOCK_SIZE);
        printf ("---- mem[%d] @0x%x\n", i, (size_t)mem[i]);
        if (mem[i] == (void*)0) {
            break;
        }

    }
    for (i=0; i < MAX_XMEM_BLOCKS; ++i) {
        printf("+++ xmem_free(mem[%d]@0x%x) \n", i, (size_t)mem[i]);
        xmem_free(mem[i]);
        printf("---- xmem_free(mem[%d]@0x%x) \n", i, (size_t)mem[i]);
    }
}

int main()
{
    void* mem = 0;

    printf("Hello world!\n");

    printf("++++ xmem_alloc( %d ) \n", BLOCK_SIZE);

    mem = xmem_alloc(BLOCK_SIZE);
    printf ("---- xmem_alloc() \n");
    printf( "mem location 0x%x \n", (size_t)mem);
    if (mem) {

    }
    xmem_free(mem);

    simple_test();

    return 0;
}
