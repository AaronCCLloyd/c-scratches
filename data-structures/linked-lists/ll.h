#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

typedef struct Node Node;

struct Node {
    Node* prev;
    Node* next;
    int   index;
};

// Single, Double and Circular type
typedef enum type { SINGLE, DOUBLE, CIRCULAR } Type;

Node* create(int size);
