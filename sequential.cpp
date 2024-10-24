#include <iostream.h>
#include <conio.h>

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    clrscr();

    int arr[10];
    int n, x;

    cout << "Enter the number of Elements: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number to search: ";
    cin >> x;

    n = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr, n, x);

    if (result == -1) {
        cout << "Element is not present in array";
    } else {
        cout << "Element is present at index " << result;
    }

    getch();
    return 0;
}