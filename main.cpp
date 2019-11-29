#include <iostream>
#include <ctime>
#include "Heap.hpp"
#include "Planet.hpp"
using namespace std;


int main() {
	srand(time(NULL));

	// Create a minHeap
	cout << "CREATING A MIN HEAP\n\n";
    Heap minHeap;
    Planet* newPlanet;

    minHeap.setType(0);            //Min Heap
    //theHeap.setType(1);                //Max Heap

    for (int i = 0; i < 9; i++) {
        newPlanet = new Planet();
        newPlanet->value = (rand() % 1000) + 1;
        newPlanet->name = "Neptune";
        newPlanet->url = "https://cdn.mos.cms.futurecdn.net/eNTJrysq4A6DqXncBtsRrB-320-80.jpg";
        minHeap.push(newPlanet->value, newPlanet);
    }

    unsigned int theSize = minHeap.size();
    for (unsigned int i = 0; i < theSize; i++) {
        newPlanet = minHeap.top();
        cout << newPlanet->value << endl;
        cout << newPlanet->name << endl;
        cout << newPlanet->url << endl;
        minHeap.pop();
        delete newPlanet;
    }


    // Create a maxheap
    cout << "\nCREATING A MAXHEAP\n\n";
    Heap maxHeap;

    //maxHeap.setType(0);            //Min Heap
    maxHeap.setType(1);                //Max Heap

    for (int i = 0; i < 9; i++) {
        newPlanet = new Planet();
        newPlanet->value = (rand() % 1000) + 1;
        newPlanet->name = "Venus";
        newPlanet->url = "https://en.es-static.us/upl/2019/08/Venus-atmosphere-composite-image-Akatsuki-800x800.jpg";
        maxHeap.push(newPlanet->value, newPlanet);
    }//for

    theSize = maxHeap.size();
    for (unsigned int i = 0; i < theSize; i++) {
        newPlanet = maxHeap.top();
        cout << newPlanet->value << endl;
        cout << newPlanet->name << endl;
        cout << newPlanet->url << endl;
        maxHeap.pop();
        delete newPlanet;
    }//for

    cout << "\nProgram ending, have a nice day" << endl;
    return 0;
}//main
