/*
 * Heap.hpp
 *
 *  Created on: Nov 18, 2019
 *      Author: johnwest
 */

#ifndef HEAP_HPP_
#define HEAP_HPP_
#include <vector>
#include "Planet.hpp"
#include <iostream>
using namespace std;

struct heapNode {
	int key;
	Planet* data;
};

class Heap {
public:
	Heap();						// set heapType to 0.
	virtual ~Heap();
	void push(int, Planet*);	// Add a node to the heap
	void pop();					// Delete a node from the heap, do not delete the Planet*
	Planet* top();				// Return the planet at the top of the heap
	int size(void);				// How many nodes are in the heap?
	void setType(int);			// 0 = minHeap, 1 = maxHeap... if the type of the heap is already set
								// do not allow to change it.
private:
	vector<heapNode> theHeap;
	void upHeap();
	void downHeap();
	int heapSize;
	int heapType;
};

#endif /* HEAP_HPP_ */
