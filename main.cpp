#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
int table[MAX_SIZE][MAX_SIZE] = {0, 0}; 
char labels[MAX_SIZE]; 
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
            } else {
	        cout << table[i][j] << " | ";
	    }
	}
        cout << "\n";
    }

    cout << endl;
}

int edgegionizer(char label) {
    for (int i = 0; i < currentSize; ++i) {
        if (labels[i] == label) {
            return i;
        }
    }
    return -1;
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
            char v;
            cout << "Enter vertex number: ";
            cin >> v;
	    labels[currentSize++] = v;
	    cout << "Added vertex: " << v << endl;
	    
        }
        else if (choice == 2) {
            char first;
            char second;
            int depth;
            
            cout << "Enter first vertex: ";
            cin >> first;
            cout << "Enter second vertex: ";
            cin >> second;
            cout << "Enter depth (edge weight): ";
            cin >> depth;

            int i = edgegionizer(first);
            int j = edgegionizer(second);
            
            if ((i != -1) && (j != -1)) {
                table[i][j] = depth;
                table[j][i] = depth; 
            }           
        }
        printTable();
    }
    return 0;
}
