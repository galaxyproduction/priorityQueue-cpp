#include "PriorityQueue.h"

template<class T>
PriorityQueue<T>::PriorityQueue() {
    head = NULL;
    queueLength = 0;
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    makeEmpty();
}

template<class T>
void PriorityQueue<T>::makeEmpty() {
    QNode<T>* current = head;
    while(head != NULL) {
        current = head;
        head = head->next;
        delete current;
    }

    queueLength = 0;
    head = NULL;
}

template<class T>
void PriorityQueue<T>::enqueue(T item, int priority) {
    if(isFull())
        throw QueueOverflow();

    QNode<T>* node = new QNode<T>();
    node->info = item;
    node->priority = priority;

    QNode<T>* current = head;
    QNode<T>* previous = NULL;
    while(current != NULL && current->priority < node->priority) {
        previous = current;
        current = current->next;
    }

    if(previous == NULL) {
        node->next = head;
        head = node;
    } else {
        previous->next = node;
        node->next = current;
    }

    queueLength++;
}

template<class T>
T PriorityQueue<T>::dequeue() {
    if (isEmpty()) 
        throw QueueUnderflow();

    QNode<T>* first = head;
    T item = first->info;
    head = head->next;
    queueLength--;
    delete first;
    return item;
}

template<class T>
T PriorityQueue<T>::peek() const{
    if(isEmpty()) 
        throw QueueUnderflow();

    return head->info;
}

template<class T>
int PriorityQueue<T>::peekPriority() const {
    if(isEmpty()) 
        throw QueueUnderflow();

    return head->priority;
}

template<class T>
int PriorityQueue<T>::length() const {
    return queueLength;
}

template<class T>
bool PriorityQueue<T>::isEmpty() const {
    return head == NULL;
}

template<class T>
bool PriorityQueue<T>::isFull() const {
	QNode<T>* location;
	try {
		location = new QNode<T>();
		delete location;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}   
}

template<class T>
void PriorityQueue<T>::printQueue(ofstream& output) const{
    QNode<T>* current = head;
    while(current != NULL) {
        output << current->info << ' ';
        current = current->next;
    }

    output << endl;
}