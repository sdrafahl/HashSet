#include <stdio.h>
#include <stdlib.h>

#include "HashSet.h"

int main(int argc, char *argv[]) {
    Hash* hash = newHash(5);
    insert(hash, "SCV Ready", 27);
    char* str = search(hash, 27);
    printf("%s\n", str);
    return 0;
}
