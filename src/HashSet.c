#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "HashSet.h"

typedef struct NodeStruct Node;
static unsigned int hashNumber(Hash* hash,unsigned int key);
static Node* searchRightForNode(Node* node , unsigned int key);
static int placeNodeAtEndOfLinkedChain(Node* from ,Node* node);
static Node* newNode(void* data, unsigned int key);
static int deleteNode(Node* node);

struct NodeStruct {
    unsigned int key;
    void* data;
    Node* right;
    Node* left;
};

struct HashStruct {
    Node** node;
    unsigned int size;
};

Hash* newHash(unsigned int size) {
    Hash* hash = malloc(sizeof(Hash));
    hash->node = (Node**)calloc(size, sizeof(Node));
    hash->size = ldexp(2, size);
    return hash;
}

int insert(Hash* hash, void* data, unsigned int key) {
    unsigned int hashed = hashNumber(hash, key);
    Node* node = newNode(data, key);
    if(*(hash->node + hashed)) {
        Node* node = (*(hash->node + hashed));
        if((*(hash->node + hashed))->key != key) {
            placeNodeAtEndOfLinkedChain((*((hash)->node + hashed))->right, node);
        }
    }else{
        (*((hash)->node + hashed)) = node;
    }
    return 0;
}

int delete(Hash* hash, unsigned int key) {
    unsigned int hashed = hashNumber(hash, key);
    if(*(hash->node + hashed)) {
        Node* baseNode = *(hash->node + hashed);
        Node* node = searchRightForNode(baseNode, key);
        if(node) {
            deleteNode(node);
        }
    }
    return 0;
}

void* search(Hash* hash, unsigned int key) {
    unsigned int hashed = hashNumber(hash, key);
    Node* node = *(hash->node + hashed);
    if(node->data) {
        return searchRightForNode(node, key)->data;
    }else{
        return NULL;
    }
}

static Node* newNode(void* data, unsigned int key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

static int placeNodeAtEndOfLinkedChain(Node* from ,Node* node) {
    if(from->right) {
        placeNodeAtEndOfLinkedChain(from->right, node);
    } else {
        from->right = node;
    }
    return 0;
}

 static int deleteNode(Node* node) {
    node->key = 0;
    node->data = NULL;
    if(node->right && !(node->left)) {
        node = node->right;
        node = NULL;
    }else{
        if(node->right && node->left) {
            node->right->left = node->left;
            node->left->right = node->right;
            node = NULL;
        }else{
            if(!(node->right)) {
                node = NULL;
            }else{
                return 1;
            }
        }
    }
    free(node);
    return 0;
}

static Node* searchRightForNode(Node* node , unsigned int key) {

    if(node->key == key) {
        return node;
    } else {
        if(!node->right) {
            return NULL;
        }
        return searchRightForNode(node->right, key);
    }
}

static unsigned int hashNumber(Hash* hash,unsigned int key) {
    float const A = (sqrt(5.0)-1.0)/2.0;
    unsigned int size = hash->size;
    return (unsigned int)floor(size * (key * A - floor(key * A)));
}
