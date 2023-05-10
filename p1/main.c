#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int get_key_input(const char *prompt) {
    int value;
    char input[50];
    int result;
    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            continue;
        }
        result = sscanf(input, "%d", &value);
        if (result != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            continue;
        }
        break;
    }
    return value;
}

void test_insert_key() {
    Node* root = NULL;
    root = insert_key(root, 5);
    root = insert_key(root, 3);
    root = insert_key(root, 7);

    if (root->key != 5) {
        printf("Test insert_key failed: root key is not 5\n");
    } else if (root->left->key != 3) {
        printf("Test insert_key failed: left child of root is not 3\n");
    } else if (root->right->key != 7) {
        printf("Test insert_key failed: right child of root is not 7\n");
    } else {
        printf("Test insert_key passed!\n");
    }
    delete_tree(root);
}

int main() {
    //test_insert_key(); Use this to see the BST is a clean working tree.
    Node* root = NULL;
    int choice, key;
    printf("\nBinary Search Tree Operations\n");
    printf("1. Insert a key\n");
    printf("2. Search for a key\n");
    printf("3. Delete a key\n");
    printf("4. In-order traversal\n");
    printf("5. Pre-order traversal\n");
    printf("6. Post-order traversal\n");
    printf("7. Delete the BST\n");
    printf("8. Exit\n");
    while (1) {
        choice = get_key_input("Enter your choice: ");

        switch (choice) {
            case 1:
                key = get_key_input("Enter the key to insert: ");
                root = insert_key(root, key);
                printf("\nBinary Search Tree Operations\n");
                printf("1. Insert a key\n");
                printf("2. Search for a key\n");
                printf("3. Delete a key\n");
                printf("4. In-order traversal\n");
                printf("5. Pre-order traversal\n");
                printf("6. Post-order traversal\n");
                printf("7. Delete the BST\n");
                printf("8. Exit\n");
                break;
            case 2:
                key = get_key_input("Enter the key to search: ");
                if (search_key(root, key))
                    printf("Key found!\n");
                else
                    printf("Key not found!\n");
                printf("\nBinary Search Tree Operations\n");
                printf("1. Insert a key\n");
                printf("2. Search for a key\n");
                printf("3. Delete a key\n");
                printf("4. In-order traversal\n");
                printf("5. Pre-order traversal\n");
                printf("6. Post-order traversal\n");
                printf("7. Delete the BST\n");
                printf("8. Exit\n");
                break;
            case 3:
                printf("Enter the key to delete: ");
                key = get_key_input("");
                if (delete_key(&root, key)) {
                    printf("Key deleted successfully!\n");
                } else {
                    printf("Key not found!\n");
                }
                break;
            case 4:
                printf("In-order traversal: ");
                in_order_traversal(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order traversal: ");
                pre_order_traversal(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order traversal: ");
                post_order_traversal(root);
                printf("\n");
                break;
            case 7:
                delete_tree(root);
                root = NULL;
                printf("BST deleted successfully!\n");
                break;
            case 8:
                delete_tree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
