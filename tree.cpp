#include <iostream.h>
#include <conio.h>

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = new Node;
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertValue(struct Node* root, int value, queue<Node*>& q) {
    if (root == NULL) {
        root = newNode(value);
        return root;
    } else if (q.front()->left == NULL) {
        q.front()->left = newNode(value);
    } else {
        q.front()->right = newNode(value);
        q.pop();
    }

    q.push(newNode(value));
    return root;
}

struct Node* createTree(int arr[], int n) {
    struct Node* root = NULL;
    queue<Node*> q;

    for (int i = 0; i < n; i++) {
        root = insertValue(root, arr[i], q);
    }

    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        cout << q.front()->key << " ";

        if (q.front()->left != NULL) {
            q.push(q.front()->left);
        }

        if (q.front()->right != NULL) {
            q.push(q.front()->right);
        }

        q.pop();
    }
}

int main() {
    clrscr();

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    struct Node* root = createTree(arr, n);

    cout << "Level order traversal of the tree: ";
    levelOrder(root);

    getch();
    return 0;
}