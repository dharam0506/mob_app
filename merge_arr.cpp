#include <iostream.h>
#include <conio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]);

void main() {
    clrscr(); // Clear the screen

    const int MAX_SIZE = 100; // Maximum size for the arrays
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
    int size1, size2;

    // Input for the first array
    cout << "Enter the number of elements in the first array: ";
    cin >> size1;
    cout << "Enter elements of the first array:\n";
    for (int i = 0; i < size1; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr1[i];
    }

    // Input for the second array
    cout << "Enter the number of elements in the second array: ";
    cin >> size2;
    cout << "Enter elements of the second array:\n";
    for (int i = 0; i < size2; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr2[i];
    }

    // Merge the two arrays
    mergeArrays(arr1, size1, arr2, size2, merged);

    // Display the merged array
    cout << "\nMerged Array:\n";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    getch(); // Wait for a key press
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int index = 0;

    // Copy elements from first array
    for (int i = 0; i < size1; i++) {
        merged[index] = arr1[i];
        index++;
    }

    // Copy elements from second array
    for (int j = 0; j < size2; j++) {
        merged[index] = arr2[j];
        index++;
    }
}