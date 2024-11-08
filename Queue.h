#pragma once
using namespace std;

template <typename T>
//A single node of the linked list queue storing a data variable, and a pointer to the following node
class Node {
public: 
	T data;	
	Node* next;

	Node(T val);
};

template <typename T>
//Implements a queue using a linked list of Nodes
class Queue {
private: 
	Node<T>* frontNode;
	Node<T>* rearNode;
	int queueSize;

public:
	//Default constructor of a Queue
	Queue();
	//Destructor of a queue implementation
	~Queue();
	//Adds a new element at the rear of the queue
	void push(T value);
	//removes the front element from the queue
	void pop();
	//Returns the front element without removing it
	T front();
	//Returns the number of elements in the queue
	int size();
	//Returns whether the queue is empty or not
	bool empty();
	//Moves the front element to the rear of the queue
	void move_to_rear();
	//display all elements in the queue
	void display();


};

