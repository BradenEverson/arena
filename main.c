#include "arena.h"
#include <stddef.h>
#include <stdio.h>
int main() {
    arena_t arena;
    arena_init(&arena, 256);

    int* arr = (int*)arena_alloc(&arena, 10 * sizeof(int));
    if (arr == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    for (size_t i = 0; i < 10; i++) {
        arr[i] = i;
    }

    for (size_t i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
