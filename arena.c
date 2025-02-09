#include "arena.h"
#include <stdint.h>
#include <stdlib.h>

void arena_init(arena_t* self, size_t mem_size) {
    self->memory = malloc(sizeof(uint8_t) * mem_size);
    self->size = mem_size;
    self->offset = 0;
}

void* arena_alloc(arena_t* self, size_t requested_size) {
    if (self->offset + requested_size > self->size) {
        /// OOM
        return NULL;
    }

    void* allocated = self->memory + self->offset;
    self->offset += requested_size;

    return allocated;
}

void arena_free(arena_t* self) {
    free(self->memory);
    self->memory = NULL;
    self->offset = 0;
    self->size = 0;
}

