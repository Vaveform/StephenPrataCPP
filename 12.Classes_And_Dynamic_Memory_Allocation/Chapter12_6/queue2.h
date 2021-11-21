
#ifndef QUEUE2_H_
#define QUEUE2_H_


#include "customer.h"




typedef Customer Item;

class Queue{
	private:
		struct Node{
			Item value;
			Node* next;
		};
		enum {Q_SIZE = 10};
		const int queue_size; // I will use constructor list initializer 
				      // to initialze const fields and references
				      // by passing parametr to constructor
		// Front of the Queue
		Node* front;
		// Rear of the Queue
		Node* rear;
		// Current number of items in queue
		int items;

	public:
		Queue(int max_size = Q_SIZE);
		const Item& Front() const;
		Item& Front();
		~Queue();
		bool isempty() const;
		bool isfull() const;
		int queuecount() const;
		// Deleting from the queue
		bool dequeue(Item&);
		// Inserting to the queue
		bool enqueue(const Item&);
		Queue(const Queue& other) = delete;
		Queue& operator=(const Queue& other) = delete;

};

#endif
