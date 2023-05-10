typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int key);
Node* insert_key(Node* root, int key);
Node* search_key(Node* root, int key);
_Bool delete_key(Node** root, int key);
void in_order_traversal(Node* root);
void pre_order_traversal(Node* root);
void post_order_traversal(Node* root);
void delete_tree(Node* root);
