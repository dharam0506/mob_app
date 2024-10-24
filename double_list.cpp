#include <iostream.h>
#include <conio.h>

struct Node {
    Node* prev;
    Node* next;
    int data;

    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void sort(Node*& head) {
    Node* current, *index;
    int temp;

    if (head == NULL) {
        return;
    } else {
        for (current = head; current != NULL; current = current->next) {
            for (index = current->next; index != NULL; index = index->next) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

void printlist(Node* head) {
    Node* current = head;

    while (current != NULL) {
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void main() {
    clrscr();

    Node* head = NULL;
    int n;

    cout << "Enter 5 numbers: ";
    for (int j = 0; j < 5; j++) {
        cin >> n;
        insert(head, n);
    }

    cout << "Before sorting: ";
    printlist(head);
    cout << endl;

    sort(head);
    cout << "After sorting: ";
    printlist(head);
    getch();
}