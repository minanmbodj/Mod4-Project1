#ifndef NODE_H
#define NODE_H


template <typename T> class List;

template <typename T>

class Node {

	friend class List<T>;

  public:
	Node<T>():next(nullptr){};
	Node<T>(T v):value(v), next(nullptr){}; //explicit ListNode(const NODETYPE& info): data(info), nextPtr{nullptr}{}

	void setValue(T val){ 
		value = val; 
	};

	void setNext(Node<T> *n){
		next = n;
	};

	Node<T> * getNext() const{
		return next;
	};

	T& getValue() {
		return value;
	};


	
	private:
		T	value;
		Node<T> * next;

};
#endif
