#include <iostream.h>
#include <conio.h>

class stack {
private:
    int array[100];
    int size, top;

public:
    stack(int arg = 100) : array(arr), size(size), top(-1) {}

    void push(int el) {
        if (top == size - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        array[top++] = el;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return array[top--];
    }

    void display() const {
        if (top == -1) {
            cout << "Stack empty" << endl;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

void main() {
    clrscr();

    int size, opt;

    cout << "Enter size of stack: ";
    cin >> size;

    stack s(size);

    while (1) {
        cout << "\nSelect operation to perform on stack:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cin >> opt;

        switch (opt) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                free(array);
                cout << "\nPress any key to exit...";
                getch();
                break;
            default:
                cout << "\nEnter valid option\n";
        }
    }
}