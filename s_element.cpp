#include <iostream>
#include <cstring>

struct Node {
    char data[10];
    Node* next;

    Node(char name[10]) : next(NULL) {
        strcpy(data, name);
    }
};

void insert(Node*& head, char val[10]) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

int searchList(char val[10], Node* current) {
    int bool = 0;
    int index = 0;

    while (current != NULL) {
        if (strcmp(current->data, val) == 0) {
            bool = 1;
            index = index + 1;
            break;
        }
        current = current->next;
        index++;
    }

    if (bool == 0) {
        std::cout << "Not found";
    }

    return index;
}

void main() {
    Node* head = NULL;
    char temp[10];

    insert(head, "Apple");
    insert(head, "Ball");
    insert(head, "Cat");
    insert(head, "Dog");

    std::cout << "Enter a string to search: ";
    std::cin >> temp;

    int result = searchList(temp, head);
    std::cout << "Element found at index: " << result << std::endl;
}