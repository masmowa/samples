#include "xmemory.h"

// TODO: should this be static?
static size_t g_mem[MAX_XMEM] = {0};
size_t g_memsize = MAX_XMEM;

typedef struct xmem_node {
    size_t allocated;
    struct xmem_node*  next;
} xmem_node_t;

#define MEM_BLOCK_SIZE(ptr, ptr_next) (size_t)((ptr_next - ptr) - sizeof(xmem_node_t))
#define BLOCK_PTR(ptr) ((void*)ptr + sizeof(xmem_node_t))
#define NODE_PTR(ptr) ((xmem_node_t*)(ptr - sizeof(xmem_node_t)))
#define MEM_END() ((void*)(g_mem + MAX_XMEM))
#define NEXT_MEM_NODE(ptr, size) ((void*)(ptr + sizeof(xmem_node_t)+ size))
void* get_g_mem() {return (void*)g_mem; }
void* xmem_alloc(size_t size)
{
    xmem_node_t* next_mn = 0;
    xmem_node_t* this_mn = 0;
    xmem_node_t * mn = (xmem_node_t*)g_mem;
    xmem_node_t* remaining_mem = 0;

    void* result = 0;
    size_t block_size = 0;

    while (mn < (xmem_node_t*)MEM_END()) {
        /*
            advance to unallocated block
         */
        while (mn->allocated)
        {
            mn = mn->next;
        }
        this_mn = mn;
        next_mn = mn->next;
        if (mn->next) {
            block_size = MEM_BLOCK_SIZE(mn, mn->next);
        }
        if (block_size > size) {
            next_mn = mn->next;
            this_mn->allocated = 1;
            this_mn->next = ((xmem_node_t*)mn + sizeof(xmem_node_t) + size);
            remaining_mem = this_mn->next;
            remaining_mem->allocated = 0;
            /* get pointer to block after this block */
            remaining_mem->next = next_mn;
            return BLOCK_PTR(this_mn);
        }
        else if (block_size == size) {
            this_mn->allocated = 1;
            this_mn->next = next_mn;
            return BLOCK_PTR(this_mn);
        }
        if (this_mn == (xmem_node_t*)g_mem && block_size == 0) {
            this_mn->allocated = 1;
            this_mn->next = ((xmem_node_t*)mn + sizeof(xmem_node_t) + size);
            /* just in case the memory was used before and needs to be cleared */
            this_mn->next->allocated = 0;
            this_mn->next->next = 0;
            return BLOCK_PTR(this_mn);
        }
        else if (MEM_END() > NEXT_MEM_NODE(this_mn, size)) {
            this_mn->allocated = 1;
            this_mn->next = ((xmem_node_t*)mn + sizeof(xmem_node_t) + size);
            /* just in case the memory was used before and needs to be cleared */
            this_mn->next->allocated = 0;
            this_mn->next->next = 0;
            return BLOCK_PTR(this_mn);
        }
        else {
            printf("this_mn[0x%x] :: mem_end[0x%x] :: next_mem_node[0x%x]\n", (size_t)this_mn, (size_t)MEM_END(), (size_t)NEXT_MEM_NODE(this_mn, size));
            return(result);
        }

    }
    return result;
}

void xmem_free(void* mem)
{
    xmem_node_t* this_mn = (xmem_node_t*)(g_mem);

    if (!mem || 0 >= NODE_PTR(mem)) {
        return;
    }
    /* find the matching block */
    while (this_mn && NODE_PTR(mem) != this_mn) {
        this_mn = this_mn->next;
    }
    /* mark block as free */
    if (this_mn) {
        this_mn->allocated = 0;
    }

}
