#ifndef QUEUE2_H_
#define QUEUE2_H_
#include <iostream>

template<class T>
class QueueTp{
	private:
		struct Node{
			T value;
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
		QueueTp(int max_size = Q_SIZE);
		const T& Front() const;
		T& Front();
		~QueueTp();
		bool isempty() const;
		bool isfull() const;
		int queuecount() const;
		// Deleting from the queue
		bool dequeue(T&);
		// Inserting to the queue
		bool enqueue(const T&);
		QueueTp(const QueueTp& other) = delete;
		QueueTp& operator=(const QueueTp& other) = delete;

};

template<class T>
QueueTp<T>::QueueTp(int max_size) : queue_size(max_size)
{
	front = rear = nullptr;
	items = 0;
}

template<class T>
QueueTp<T>::~QueueTp()
{
	Node* deletion_node = front;
	while(deletion_node != nullptr)
	{
		front = front->next;
		delete deletion_node;
		deletion_node = front;
	}

}

template<class T>
bool QueueTp<T>::isempty() const
{
	return items == 0;
}

template<class T>
bool QueueTp<T>::isfull() const
{
	return items == queue_size;
}

template<class T>
int QueueTp<T>::queuecount() const
{
	return items;
}


// Deleting from the front of queue (FIFO)
template<class T>
bool QueueTp<T>::dequeue(T& val)
{
	if(isempty()){
		return false;
	}
	Node* deletion_node = front;
	front = front->next;
	--items;
	val = deletion_node->value;
	delete deletion_node;
	if(items == 0){
		front = rear = nullptr;
	}
	return true;
}


// Inserting to the end of queue (FIFO)
template<class T>
bool QueueTp<T>::enqueue(const T& val){
	if(isfull()){
		return false;
	}
	Node* insertion_node = new Node;
	insertion_node->value = val;
	insertion_node->next = nullptr;
	// Empty queue case
	if(rear == nullptr){
		front = rear = insertion_node;
	}
	else{
		rear->next = insertion_node;
		rear = rear->next;
	}
	++items;
	return true;

}

template<class T>
T& QueueTp<T>::Front()
{
	return front->value;
}


template<class T>
const T& QueueTp<T>::Front() const
{
	return front->value;
}


#endif
