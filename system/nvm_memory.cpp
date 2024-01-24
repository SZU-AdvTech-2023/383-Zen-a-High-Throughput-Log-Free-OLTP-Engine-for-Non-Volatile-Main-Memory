#include"nvm_memory.h"

void *nvm_mem_alloc(long size){
    void * addr = numa_alloc_onnode(size, 1);
    if(addr == NULL){
    	printf("allocation failed!\n");
    	exit(1);
    } else
    	return addr;
}

void *dram_mem_alloc(int size){
    void *addr = numa_alloc_onnode(size, 0);
    return addr;
}

void nvm_mem_free(void *p, int size){
    numa_free(p, size);
}

void dram_mem_free(void *p, int size){
    numa_free(p, size);
}

