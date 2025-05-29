#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
int table[MAX_SIZE][MAX_SIZE] = {0, 0}; 
int labels[MAX_SIZE]; 
int currentSize = 0; 

void printTable() {
    cout << "    " ;
    for (int i = 0; i < currentSize; ++i) {
        cout << labels[i] << "   "; 
    }
    cout << "\n";

    for (int i = 0; i < currentSize; ++i) {
        cout << labels[i] << " | ";
        
        for (int j = 0; j < currentSize; ++j) {
            if (table[i][j] == 0) {
                cout << "_ | "; 
            }
        }
        cout << "\n";
    }

    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Vertex" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Quit " << endl;
        cout << "Input: " ;
        cin >> choice;

        if (choice == 1) {
            int v;
            cout << "Enter vertex number: ";
            cin >> v;
	    labels[currentSize++] = v;
	    cout << "Added vertex: " << v << endl;
	    
        }
        else if (choice == 2) {
           
        }
        printTable();
    }
    return 0;
}
