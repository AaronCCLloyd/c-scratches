/**
 * Learning exercise:
 *  Writing a Linked List implementation.
*/

#include "ll.h"

#define SIZE_LIMIT 100

Node* create(int size) {

    if (size <= 0 || size > SIZE_LIMIT) {
        perror("Invalid size provided. Size must be an integer.");
        return EXIT_FAILURE;
    }

    Node* head;

    for (int i = 0; i < size; i++) {
        Node* current = (Node*)calloc(1, sizeof(Node));
        Node* prev;
        if (i == 0) {
            head = current;
        }
        else {
            prev->next = current;
            current->prev = prev;
            current->index = i;
        }
        prev = current;
    }
    return head;
}

void add(Node* node, int index) {
}


Node* delete(Node* current) {
    int current_index = current->index;
    Node* next_node = current->next;
    free(current);
    printf("Freed memory owned by node %d\n", current_index);
    return next_node;
}

void delete_all(int size, Node* head) {
    Node* current = head;
    Node* next_node = current->next;;

    while (--size > 0) {
        current = delete(current);
        next_node = current->next;
    }
}

void delete_at_index(Node* ll, int index) {
    Node* node = access(ll, index);
    // TODO(Aaron): Update links for neighbouring nodes
    free(NULL);
}

Node* access(Node* node, int index) {
}

void update() {}

void move() {}

void show(int size, Node* node) {
    while (size-- > 0) {
        printf("[prev = 0x%x next = 0x%x index = %d]\n", node->prev, node->next, node->index);
        node = node->next;
    }
}

int main(void) {
    int size = 5;
    Node* head = create(size);
    show(size, head);
    delete_all(size, head);
    return EXIT_SUCCESS;
}
