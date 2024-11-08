#include "Queue.h"
#include <iostream>
using namespace std;


template <typename T> 
Node<T>::Node(T val) : data(val), next(nullptr) {}

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

template <typename T>
Queue<T>::~Queue() {
	while (!empty()) {
		pop();
		}
}

template <typename T>
void Queue<T>::push(T value) {
	Node<T>* newNode = new Node<T>(value);
	if (rearNode) {
		rearNode->next = newNode;
	}
	else {
		frontNode = newNode; //Queue was empty
	}
	rearNode = newNode;
	queueSize++;
}

template <typename T>
void Queue<T>::pop() {
	if (empty()) {
		cerr << "Queue is empty, cannot pop" << endl;
		return;
	}
	Node<T>* temp = frontNode;
	frontNode = frontNode->next;
	delete temp;
	queueSize--;
	if (empty()) {
		rearNode = nullptr; //Queue is now empty
	}
}

template <typename T>
T Queue<T>::front() {
	if (empty()) {
		throw runtime_error("Queue is empty. Cannot access front.");
	}
	return frontNode->data;
}

template <typename T>
int Queue<T>::size() {
	return queueSize;
}

template <typename T>
bool Queue<T>::empty() {
	return queueSize == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {
	if (empty()) {
		cerr << "Queue is empty, no items to move to rear." << endl;
		return;
	}
	T frontValue = front();
	pop();
	push(frontValue);
}

template <typename T>
void Queue<T>::display() {
	Node<T>* current = frontNode;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {
	Queue<int> q;

	//a) test push function
	for (int i = 0; i < 10; ++i) {
		q.push(i + 1); //pushes values from 1-10
	}

	//b) display all elements in the queue
	cout << "Elements in the queue: " << endl;
	q.display();

	//c) display front element
	cout << "Front element: " << q.front() << endl;

	//d) display size of queue
	cout << "Size of the queue is: " << q.size() << endl;

	//e) move an eement to the rear
	q.move_to_rear();
	cout << "After moving to front to rear, elements in queue are: ";
	q.display();

	return 0;
}