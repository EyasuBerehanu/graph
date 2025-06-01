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
void removeDaVertex(char label){
    int index = edgegionizer(label);
    if (index == -1) {
        cout << "Vertex not found.\n";
        return;
    }
    
    for (int i = index; i < currentSize - 1; ++i) {
        for (int j = 0; j < currentSize; ++j) {
            table[i][j] = table[i + 1][j];
        }
    }

    for (int j = index; j < currentSize - 1; ++j) {
        for (int i = 0; i < currentSize - 1; ++i) {
            table[i][j] = table[i][j + 1];
        }
    }
    
    for (int i = index; i < currentSize - 1; ++i) {
        labels[i] = labels[i + 1];
    }

    currentSize--;
    cout << "Removed vertex: " << label << endl;
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
        } else if (choice == 3){
	  char v;
	  cout << "Enter vertex you want removed: ";
	  cin >> v;
	} else if (choice == 4){
	  char first, second;
	  cout << "Enter first vertex: ";
	  cin >> first;
	  cout << "Enter second vertex: ";
	  cin >> second;

	  int i = edgegionizer(first);
	  int j = edgegionizer(second);

	  table[i][j] = 0;
	  table[j][i] = 0;
	  cout << "Edge removed between " << first << " and " << second << ".\n";	  
	}
        printTable();
    }
    return 0;
}
