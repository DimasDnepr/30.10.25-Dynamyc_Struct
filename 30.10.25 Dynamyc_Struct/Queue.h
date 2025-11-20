#pragma once
template<typename T>
class Queue
{
	struct Node
	{
		T el;
		Node* next;
	};
	Node* front;
	Node* back;
public:
	Queue()
	{
		front = nullptr;
		back = nullptr;
	}
	~Queue();
	void enqueue(const T&);
	T dequeue();
	bool isEmpty();
};

template<typename T>
inline Queue<T>::~Queue()
{
	Node* nodePtr = front;
	Node* nextNode = nullptr;;
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template<typename T>
inline void Queue<T>::enqueue(const T& inf)
{
	Node* newNode = new Node;
	newNode->el = inf;
	newNode->next = nullptr;
	if (front == nullptr)
	{
		front = back = newNode;
	}
	else
	{
		back->next = newNode;
		back = newNode;
	}
}


template<typename T>
inline T Queue<T>::dequeue()
{
	Node* tmp;
	if (!isEmpty())
	{
		T val = front->el;
		tmp = front->next;
		delete front;
		front = tmp;
		if (front == nullptr)
			back = nullptr;
		return val;
	}

}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	if (front == nullptr)
		return true;
	return false;
}
