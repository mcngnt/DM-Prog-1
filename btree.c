#include <unistd.h>
#include <stdio.h>

typedef struct btree_s btree_t;

struct btree_s
{
    int value;
    btree_t* parent;
    btree_t* lson;
    btree_t* rson;
};


#define MAX_TAB 20000

#define BTREE_PARENT(n) *(n)->parent;
#define BTREE_LSON(n) (n)->lson;
#define BTREE_RSON(n) (n)->rson;

#define BTREE_ISFREE(n) ((size_t)n.parent & 1)
#define DISCARD_LSB(x) (x >> 1) << 1

static btree_t mem[MAX_TAB];
int isInit = 0;

void init_memory()
{
    for (size_t i = 0; i < MAX_TAB; i++)
    {
        mem[i].parent = (btree_t*)1;
    }
    isInit = 1;
}


btree_t* btree_alloc(void)
{
    if(!isInit)
    {
        init_memory();
    }

    for (size_t i = 0; i < MAX_TAB; i++)
    {
        if(BTREE_ISFREE(mem[i]))
        {
            mem[i].parent = (btree_t*)((size_t)mem[i].parent);
            return &mem[i];
        }
    }

    return NULL;
    
}



int main(void)
{
    btree_t* vars[2];
    vars[0] = btree_alloc();
    vars[1] = btree_alloc();


    BTREE_PARENT(vars[0]) = vars[1];

    // printf("%p\n", vars[0]);
    // vars[0]->parent = vars[1];
    
    // BTREE_LSON(vars[1]) = vars[0];
    // BTREE_RSON(vars[1]) = BTREE_LSON(vars[0]) = BTREE_RSON(vars[0]) = NULL;
    // vars[1] = NULL;
    // printf("%d collected nodes\n", btree_gc(vars));
    return 0;
}