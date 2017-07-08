#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "HashSet.h"

static Node newNode(void* data, unsigned int key);
static unsigned int hash(Hash hash,unsigned int key);
static Node* searchRightForNode(Node* node , unsigned int key);
static Node newNode(void* data, unsigned int key);

struct Hash {
    Node** node;
    unsigned int size;
};

typedef struct {
    unsigned int key;
    void* data;
    Node* right;
    Node* left;
} Node;

Hash* newHash(unsigned int size) {
    Hash* hash = malloc(sizeof(Hash));
    hash->node = (Node**)calloc(size, sizeof(Node));
    hash->size = ldexp(2, size);
    return hash;
}

int insert(Hash* hash, void* data, unsigned int key) {
    unsigned int hash = hash(key);
    Node* node = newNode(void* data, unsigned int key);
    if((*hash)->node + hash) {
        ((*hash)->node + hash)->right = node;
    }else{
        ((*hash)->node + hash) = node;
    }
    hash->size++;
    return 0;
}

int delete(unsigned int key) {
    unsigned int hash = hash(key);
    if((*hash)->node + hash) {
        Node *node = searchRightForNode((*hash)->node + hash);
        if(node) {
            deleteNode(node);
        }
    }
    return 0;
}

void* search(unsigned int key) {
    unsigned int hash = hash(key);
    if((*hash)->node + hash) {
        return searchRightForNode((*hash)->node + hash)->data;
    }
}

static Node newNode(void* data, unsigned int key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

 static int deleteNode(Node* node) {
    node->key = 0;
    node->data = NULL;
    if(node->right && !(node->left)) {
        free(node);
        node = node->right;
        node = NULL;
    }else{
        if(node->right && node->left) {
            free(node);
            node->right->left = node->left;
            node->left->right = node->right;
            node = NULL;
        }else{
            if(!(node->right)) {
                free(node);
                node = NULL;
            }else{
                return 1;
            }
        }
    }
    return 0;
}

static Node* searchRightForNode(Node* node , unsigned int key) {
    if(node->key == key) {
        return node;
    }else{
        if(!node->right) {
            return NULL;
        }
        searchRightForNode(node->right);
    }
}

static unsigned int hash(Hash hash,unsigned int key) {
    float const A = (sqrt(5.0)-1.0)/2.0;
    unsigned int size = hash->size;
    return (unsigned int)floor(size * (key * A - floor(key * A)));
}
