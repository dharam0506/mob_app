#include <iostream.h>
#include <conio.h>

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(NULL), right(NULL) {}
};

template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;

public:
    BinarySearchTree() : root(NULL) {}

    void insert(T value) {
        root = insertRecursive(root, value);
    }

    void deleteNode(T value) {
        root = deleteRecursive(root, value);
    }

    void search(T value) {
        Node<T>* current = searchRecursive(root, value);
        if (current != NULL) {
            cout << "Element found" << endl;
        } else {
            cout << "Element not found" << endl;
        }
    }

    void inorder() {
        inorderRecursive(root);
    }

    void preorder() {
        preorderRecursive(root);
    }

    void postorder() {
        postorderRecursive(root);
    }

    void levelOrder() {
        if (root == NULL) {
            return;
        }

        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL) {
                q.push(current->left);
            }

            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }

private:
    Node<T>* insertRecursive(Node<T>* current, T value) {
        if (current == NULL) {
            return new Node<T>(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    Node<T>* deleteRecursive(Node<T>* current, T value) {
        if (current == NULL) {
            return current;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            if (current->left == NULL) {
                Node<T>* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == NULL) {
                Node<T>* temp = current->left;
                delete current;
                return temp;
            }

            Node<T>* temp = minValue(current->right);
            current->data = temp->data;
            current->right = deleteRecursive(current->right, temp->data);
        }

        return current;
    }

    Node<T>* searchRecursive(Node<T>* current, T value) {
        if (current == NULL || current->data == value) {
            return current;
        }

        if (value < current->data) {
            return searchRecursive(current->left, value);
        }

        return searchRecursive(current->right, value);
    }

    Node<T>* minValue(Node<T>* node) {
        Node<T>* current = node;

        while (current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    void inorderRecursive(Node<T>* current) {
        if (current == NULL) {
            return;
        }

        inorderRecursive(current->left);
        cout << current->data << " ";
        inorderRecursive(current->right);
    }

    void preorderRecursive(Node<T>* current) {
        if (current == NULL) {
            return;
        }

        cout << current->data << " ";
        preorderRecursive(current->left);
        preorderRecursive(current->right);
    }

    void postorderRecursive(Node<T>* current) {
        if (current == NULL) {
            return;
        }

        postorderRecursive(current->left);
        postorderRecursive(current->right);
        cout << current->data << " ";
    }
};

int main() {
    clrscr();

    BinarySearchTree<int> tree;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    cout << "Inorder traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder();
    cout << endl;

    cout << "Level order traversal: ";
    tree.levelOrder();
    cout << endl;

    int searchVal;
    cout << "Enter the element to search: ";
    cin >> searchVal;
    tree.search(searchVal);

    getch();
    return 0;
}