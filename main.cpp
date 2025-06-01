//Eyasu Berehanu
//5/31/2025
//This is a graph creator which creates a graph using an adjacency table which allows you too add remove and change values in the graph like vertex, weught, and edges
//Sources: Geeks for Geeks and wikipedia to explain how the adjacny matrix works but besides that prior knowlage on forloops and more info around youtube carried the assigment
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; //max number of vertiexs 
int table[MAX_SIZE][MAX_SIZE] = {0, 0}; //for adjancy table to store the weights
char labels[MAX_SIZE]; //array to store the vertex lebels
int currentSize = 0; //tracks how many vertexes are on the graph

void printTable();
int edgegionizer(char label);
void removeVertex(char label);

void printTable() { //this prints the adjacency table depending on the inputs inputed it can look diffrent
    cout << "    " ;
    for (int i = 0; i < currentSize; ++i) { //prints the column head or the labels for vertex
        cout << labels[i] << "   "; 
    }
    cout << "\n";

    for (int i = 0; i < currentSize; ++i) { //prints the table rows
        cout << labels[i] << " | ";
        
        for (int j = 0; j < currentSize; ++j) {
            if (table[i][j] == 0) {
	      cout << "_ | "; //when there is no edge
            } else {
	      cout << table[i][j] << " | "; //fpr edge weogjt
	    }
	}
        cout << "\n";
    }

    cout << endl;
}

int edgegionizer(char label) { //finds the edge or index of the vertex label asked for
    for (int i = 0; i < currentSize; ++i) {
        if (labels[i] == label) {
            return i;
        }
    }
    return -1;
}
void removeDaVertex(char label){ // removes a vertex and shift the table depending on what was told
    int index = edgegionizer(label);
    if (index == -1) {
        cout << "Vertex not found.\n";
        return;
    }
    
    for (int i = index; i < currentSize - 1; ++i) { //shifts the row up
        for (int j = 0; j < currentSize; ++j) {
            table[i][j] = table[i + 1][j];
        }
    }

    for (int j = index; j < currentSize - 1; ++j) { //shifts the columns left
        for (int i = 0; i < currentSize - 1; ++i) {
            table[i][j] = table[i][j + 1];
        }
    }
    
    for (int i = index; i < currentSize - 1; ++i) { //shifts labels array
        labels[i] = labels[i + 1];
    }

    currentSize--; //decreases the size
    cout << "Removed vertex: " << label << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Vertex" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Remove Vertex" << endl;
	cout << "4. Remove Edge" << endl;
	cout << "5. Quit" << endl;
	cout << "Input: " ;
        cin >> choice;

        if (choice == 1) { //adds a vertex
            char v;
            cout << "Enter vertex number: ";
            cin >> v;
	    labels[currentSize++] = v; //stores the label then increases size
	    cout << "Added vertex: " << v << endl;
	    
        }
        else if (choice == 2) { //adds an edge bettwen the two vertexes
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
            
            if ((i != -1) && (j != -1)) { //puts weight in boths sides or directions
                table[i][j] = depth;
                table[j][i] = depth; 
            }
	    
        } else if (choice == 3){ //removes vertex
	  char v;
	  cout << "Enter vertex you want removed: ";
	  cin >> v;
	  removeDaVertex(v);
	  
	} else if (choice == 4){ //removes edge
	  char first;
	  char second;
	  cout << "Enter first vertex: ";
	  cin >> first;
	  cout << "Enter second vertex: ";
	  cin >> second;
	  int i = edgegionizer(first);
	  int j = edgegionizer(second);
	  
	  table[i][j] = 0; //sets weight to 0 to remove edge
	  table[j][i] = 0;
	  cout << "Edge removed between " << first << " and " << second << ".\n";
	  
	} else if (choice == 5){ //quits the program
	  break;
	  
	}else{
	  cout << "Invalid choice try again\n";
	}
	
        printTable(); 
    }
    return 0;
}
