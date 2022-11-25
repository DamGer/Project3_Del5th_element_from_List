#include <iostream>

using namespace std;


template<typename T>
struct Node
{
		Node* next;
		T payload;
		void Print_List();
		void push_back(T payload);
		void pop_front();
		void clear();
		~Node();
		Node<T>* head = nullptr;
		int size = 0;
		Node(T payload = T(), Node* next = nullptr)
		{
			this->payload = payload;
			this->next = next;
		}
};




template<typename T>
void Node<T>::push_back(T payload)
{
	if (head == nullptr) {
		head = new Node<T>(payload);
	}
	else {
		Node<T>* current = this->head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node<T>(payload);
	}
	size++;
}

template<typename T>
void Node<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}

template<typename T>
void Node<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>
Node<T>::~Node()
{
	cout << "destuctor" << endl;
	clear();
}

template<typename T>
void Node<T>::Print_List() {
cout << "Number of elements in list:" << size << endl;
	if (size != 0) {
		Node<T>* current = this->head;
		while (current->next != nullptr) {
			cout << current->payload << endl;
			current = current->next;
			
		}
		
	}
}


template<typename T>
void Del5(Node<T> &list) {
	Node<T>* cur = list.head;
	Node<T>* prev = list.head;
	for (int i = 0; cur != nullptr; i++) {
		prev = cur;
		cur = cur->next;
		if ((i + 1) % 5 == 0) {
				if (cur != nullptr) {
					prev->next = cur->next;
				}
				else {
					prev->next = nullptr;
				}
			delete cur;
			cur = prev->next;
			i++;
			list.size--;
		}
	}
}


int main() {

	Node<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);
	l.push_back(11);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);
	l.push_back(15);
	l.Print_List();
	//l.pop_front();
	//cout << "Pop Front:" << endl;
	//l.Print_List();
	Del5(l);
	cout << "Pop 5:" << endl;
	l.Print_List();
	return 0;
}

