#include <stdio.h>
#include <stdlib.h>

#include "HashSet.h"

int main(int argc, char *argv[]) {
    Hash* hash = newHash(5);
    insert(hash, "SCV Ready", 27);
    char* str = search(hash, 27);
    printf("Expected: SCV Read \n");
    printf("Result: %s\n", str);

    Hash* hash2 = newHash(5);
    insert(hash2, "Deleted String", 30);
    delete(hash2, 30);
    void* result = search(hash2, 30);
    if(result == NULL) {
      printf("This should be NULL \n");
    }
    return 0;
}
