#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List{
	private:
		static const int MAX = 10;
		int size;
		struct Node{
			Item value;
			Node* _next;
			Node(const Item& val, Node* next = nullptr);
			Node();
			~Node();
		};
		Node* ptr_to_begin;
		Node* ptr_to_last;
	public:
		List();
		~List();
		bool push(const Item& val);
		void VisitAll(void(*functor)(Item&));
		bool isEmpty() const;
		bool isFull() const;


};

#endif
