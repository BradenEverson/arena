#ifndef ARENA_H
#define ARENA_H
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t* memory;
    size_t size;
    size_t offset;
} arena_t;

void arena_init(arena_t* self, size_t mem_size);
void* arena_alloc(arena_t* self, size_t requested_size);
void arena_free(arena_t* self);

#endif // ARENA_H
