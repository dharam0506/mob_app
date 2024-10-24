#include <iostream.h>
#include <conio.h>

void max_heap(int a[], int m, int n) {
    int j, t;
    t = a[m];
    j = 2 * m;

    while (j <= n) {
        if (j < n && a[j + 1] > a[j]) {
            j = j + 1;
        }

        if (t > a[j]) {
            break;
        } else {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }

    a[j / 2] = t;
    return;
}

void build_maxheap(int a[], int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        max_heap(a, k, n);
    }
}

int main() {
    int n, i;
    clrscr();

    cout << "Enter no of elements of array: ";
    cin >> n;

    int a[30];
    for (i = 1; i <= n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> a[i];
    }

    build_maxheap(a, n);
    cout << "Heap: ";

    for (i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }

    getch();
    return 0;
}