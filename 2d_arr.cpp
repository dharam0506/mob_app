#include <iostream.h>
#include <conio.h>

void sortArray(int arr[], int size);
void displayArray(int arr[], int size);

void main() {
    clrscr(); 

    const int rows = 3; // Number of rows
    const int cols = 4; // Number of columns
    int arr[rows][cols];
    int temp[rows * cols]; // Temporary array to hold elements for sorting

    // Input the 2D array
    cout << "Enter elements for a " << rows << "x" << cols << " array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
            temp[i * cols + j] = arr[i][j]; // Store in temporary array
        }
    }

    // Sort the temporary array
    sortArray(temp, rows * cols);

    // Display sorted elements
    cout << "\nSorted elements in the array:\n";
    displayArray(temp, rows * cols);

    getch(); // Wait for a key press
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}