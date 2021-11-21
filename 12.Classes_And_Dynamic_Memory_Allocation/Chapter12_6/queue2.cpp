#include "queue2.h"

Queue::Queue(int max_size) : queue_size(max_size){
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue(){
	Node* deletion_node = front;
	while(deletion_node != nullptr ){
		front = front->next;
		delete deletion_node;
		deletion_node = front;
	}
}

bool Queue::isempty() const 
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == queue_size;
}

int Queue::queuecount() const 
{
	return items;
}

bool Queue::dequeue(Item& Value){
	if(this->isempty()){
		return false;
	}
	Node* deletion_node = front;
	front = front->next;
	--items;
	Value = deletion_node->value;
	delete deletion_node;
	if(items == 0){
		rear = nullptr;
	}
	return true;
}

bool Queue::enqueue(const Item& Value){
	if(this->isfull()){
		return false;
	}
	Node* insertion_node = new Node;
	insertion_node->value = Value;
	insertion_node->next = nullptr;
	if(rear == nullptr){
		// Empty queue case
		front = rear = insertion_node;
	}
	else{
		// One or other number of items in queue
		rear->next = insertion_node;
		rear = rear->next;
	}
	++items;
	return true;
}

const Item& Queue::Front() const {
	return front->value;
}
Item& Queue::Front() {
	return front->value;
}
