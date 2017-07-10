#ifndef HASH_SET
# define HASH_SET

typedef struct HashStruct Hash;
Hash* newHash(unsigned int size);
int delete(Hash* hash, unsigned int key);
int insert(Hash* hash, void* data, unsigned int key);
void* search(Hash* hash, unsigned int key);

#endif
