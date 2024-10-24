#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void displayReverse(Node* head) {
    if (head == NULL) {
        return;
    }

    displayReverse(head->next);
    std::cout << head->data << " ";
}

void display(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    std::cout << "Linked list elements in normal order: ";
    display(head);
    std::cout << std::endl;

    std::cout << "Linked list elements in reverse order: ";
    displayReverse(head);
    std::cout << std::endl;

    return 0;
}