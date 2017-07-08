#ifndef HASH_SET
# define HASH_SET

typedef struct HashStruct Hash;
Hash* newHash(unsigned int size);
int delete(unsigned int key);
int insert(Hash* hash, void* data, unsigned int key);
void* search(unsigned int key);

#endif
