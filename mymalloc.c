#include <stdio.h>
#include <stdint.h> 
#include <stdbool.h> // for header_t

#define HEAP_SIZE 4096

/*
Declaring union 
initilizing the static heap here 
also ensuring 8 bytes is aligned
*/
union heap_union {
    uint64_t align;  // aligning 8 bytes 
    char heap[HEAP_SIZE]; // heap arr 
};

// static calling the heap and making heap var 
// static union heap_union heap;

/*
Header T struct
checkking size 
flagging to see if chunk is free 
aiding us in seeing if the chunk of memeory is free and how much space its taking 
*/
struct header_t {
    size_t size; // size of the chunk
    bool is_free; // flag to check if the block is free
};

static struct header_t first_chunk;
// initilizaiton function for when first allocation occurs
bool init_heap() {
    first_chunk.size = HEAP_SIZE;
    first_chunk.is_free = true;
    // testing steps 1 to 3 before logging off 
    printf("Chunk size: %zu bytes\n", first_chunk.size);
    printf("Is chunk free? %s\n", first_chunk.is_free ? "Yes" : "No");
    return first_chunk.is_free;
};


int main() {
    // testing steps 1 to 3 before logging off 
    init_heap();

    return 0;
};
