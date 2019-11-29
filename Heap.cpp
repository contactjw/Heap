/*
 * Heap.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: johnwest
 */

#include "Heap.hpp"

// Description
// 	- Default constructor to set the heapSize to 0 and heapType to a max-heap.
// Preconditions
//  - None.
// Postconditions
// 	- The heapSize is set to 0.
//  - The default heapType is 1, which is maxHeap.
Heap::Heap() {
	heapSize = 0;		// Sets heap to min-heap
	heapType = 1;		// Sets heap to a max-heap
}

// Description
// 	- Destructor
// Preconditions
//  - None.
// Postconditions
// 	- None.
Heap::~Heap() {

}

// Description
// 	- Function to add a new Planet to a heapNode and push the heapNode to the back of the heap.
// Preconditions
//  - Heap must exist.
//  - keyVal must be a valid integer variable, and Planet must have valid data members.
//  - Assigns Key and Planet to a valid heapNode.
//  - If the heap is empty, simply add the Planet to first position in the heap.
// Postconditions
// 	- The Heap is changed and heapNode is added to the back of the heap.
//  - Increase heapSize by 1.
//  - If the heap is not empty, the function calls upHeap to move the heapNode where it belongs.
void Heap::push(int keyVal, Planet* value) {
	if (heapSize == 0) {
		heapNode newNode;
		newNode.key = keyVal;
		newNode.data = value;
		theHeap.push_back(newNode);
		heapSize++;
	}
	else {
		heapNode newNode;
		newNode.key = keyVal;
		newNode.data = value;
		theHeap.push_back(newNode);
		heapSize++;
		upHeap();
	}
}

// Description
// 	- Function to remove the first heapNode in the heap and replace it with the last heapNode.
// Preconditions
//  - Heap must exist.
//  - Heap must not be empty, else return.
// Postconditions
// 	- The heapNode that was at the end of the heap is now at first, and downHeap is called to sort
//    the heap back to where values belong.
//  - heapSize is decremented by 1.
void Heap::pop() {
	if (heapSize == 0)
		return;
	else {
		swap(theHeap[0], theHeap[heapSize - 1]);
		theHeap.pop_back();
		heapSize--;
		downHeap();
	}
}

// Description
// 	- Function to return the Planet at the top of the heap back to main.
// Preconditions
//  - Heap must exist.
//  - Heap must not be empty, else return nullptr.
//  - Return the planet at index 0.
// Postconditions
//  - Empty heap returns nullptr.
// 	- The Planet pointer that was at index[0] is returned back to main.
Planet* Heap::top() {
	if (heapSize == 0)
		return nullptr;
	else {
		return theHeap[0].data;
	}
}

// Description
// 	- Function to compare the last element in the heap to its parent element.
//  - Depending on heapType, it will sort the heap from greatest to least or least to greatest
//    in an upward fashion.
// Preconditions
//  - Heap must exist.
//  - key values must have proper integer variables to compare.
// Postconditions
// 	- If the parent is greater than heapNode (minHeap), swap the parent and Node.
// 	- If the parent is less than heapNode (maxHeap), swap the parent and Node.
//  - Will perform swaps until the heapNode inserted will be in it's proper location.
void Heap::upHeap() {
	int index = heapSize - 1;
	int parentPosition = (index - 1) / 2;
	if(heapType == 0) {
		while(index > 0) {
			parentPosition = (index - 1) / 2;
			if (theHeap[index].key < theHeap[parentPosition].key) {
				swap(theHeap[parentPosition], theHeap[index]);
				index = parentPosition;
			}
			else
				break;
		}
	}
	else if (heapType == 1){
		while(index > 0) {
			int parentPosition = (index - 1) / 2;
			if (theHeap[index].key > theHeap[parentPosition].key) {
				swap(theHeap[parentPosition], theHeap[index]);
				index = parentPosition;
			}
			else
				break;
		}
	}
}

// Description
// 	- Function to compare the first element in the heap to its children elements.
//  - Depending on heapType, it will sort the heap from greatest to least or least to greatest
//    in a downward fashion.
// Preconditions
//  - Heap must exist.
//  - key values must have proper integer variables to compare.
//  - Function checks if there is a left and right child and compares which is smaller.
// Postconditions
// 	- If the parent is greater than heapNode (minHeap), swap the parent and smallerChild.
// 	- If the parent is smaller than heapNode (maxHeap), swap the parent and largerChild.
//  - Will perform swaps until the heap will be in proper order.
void Heap::downHeap() {
	int index = 0,
		leftChild = index * 2 + 1,
		rightChild = index * 2 + 2;

	if (heapType == 0) {
		while (leftChild < heapSize) {
			int smallerChild = leftChild;
			if (rightChild < heapSize && theHeap[rightChild].key < theHeap[leftChild].key) {
				smallerChild = rightChild;
			}
			if (theHeap[index].key < theHeap[smallerChild].key) {
				break;
			}
			else {
				swap(theHeap[index], theHeap[smallerChild]);
			}
			index = smallerChild;
			leftChild = index * 2 + 1;
			rightChild = index * 2 + 2;
		}
	}
	else if (heapType == 1) {
		while (leftChild < heapSize) {
			int largerChild = leftChild;
			if (rightChild < heapSize && theHeap[rightChild].key > theHeap[leftChild].key) {
				largerChild = rightChild;
			}
			if (theHeap[index].key > theHeap[largerChild].key) {
				break;
			}
			else {
				swap(theHeap[index], theHeap[largerChild]);
			}
			index = largerChild;
			leftChild = index * 2 + 1;
			rightChild = index * 2 + 2;
		}
	}
}

// Description
// 	- Function to return the current size of the heap.
// Preconditions
//  - Heap must exist.
// Postconditions
// 	- If the heap is empty, the heapSize will return 0.
//  - Returns the integer value of the heapSize back to main.
int Heap::size() {
	return heapSize;
}

// Description
// 	- Function to set the type of heap, either min-heap or max-heap.
// Preconditions
//  - Heap must not have heapNodes currently in it.
// Postconditions
// 	- If the heapSize is not zero, an exception will be thrown, and will not change type.
//  - If the heap was empty, 0 will set the heap to a min-heap.
//  - If the heap was empty, 1 will set the heap to a max-heap.
void Heap::setType(int type) {
	if (heapSize != 0)
		throw "Cannot change heap type with heapNodes currently in the heap.";
	else if (type == 0)			// Sets heap to a min-heap
		heapType = 0;
	else if (type == 1)			// Sets heap to a max-heap
		heapType = 1;
}

