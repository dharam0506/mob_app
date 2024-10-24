#include <iostream.h>
#include <conio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void main() {
    clrscr();

    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "The sequence of moves included in the tower of Hanoi are: " << endl;
    towerOfHanoi(n, 'A', 'C', 'B');

    getch();
}