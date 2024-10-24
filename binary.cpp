#include <iostream.h>
#include <conio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, high, x);
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
    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1) {
        cout << "Element is present at index " << result;
    } else {
        cout << "Element is not present in array";
    }

    getch();
    return 0;
}