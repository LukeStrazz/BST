#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* insert_key(Node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = insert_key(root->left, key);
    } else if (key > root->key) {
        root->right = insert_key(root->right, key);
    }

    return root;
}

Node* search_key(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search_key(root->left, key);
    } else {
        return search_key(root->right, key);
    }
}

Node* find_min_key_node(Node* node) {
    if (node == NULL || node->left == NULL) {
        return node;
    } else {
        return find_min_key_node(node->left);
    }
}

bool delete_key(Node** root, int key) {
    if (*root == NULL) {
        return false;
    }

    if (key < (*root)->key) {
        return delete_key(&((*root)->left), key);
    } else if (key > (*root)->key) {
        return delete_key(&((*root)->right), key);
    } else {
        Node* temp;
        if ((*root)->left == NULL) {
            temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if ((*root)->right == NULL) {
            temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            temp = find_min_key_node((*root)->right);
            (*root)->key = temp->key;
            delete_key(&((*root)->right), temp->key);
        }
        return true;
    }
}


void in_order_traversal(Node* root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        printf("%d ", root->key);
        in_order_traversal(root->right);
    }
}

void pre_order_traversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void post_order_traversal(Node* root) {
    if (root != NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->key);
    }
}

void delete_tree(Node* root) {
    if (root == NULL) {
        return;
    }

    delete_tree(root->left);
    delete_tree(root->right);

    free(root);
}
