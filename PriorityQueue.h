#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class QueueOverflow {};
class QueueUnderflow {};

template<class T>
struct QNode {
    T info;
    int priority;
    QNode<T>* next;
};

template<class T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    void makeEmpty();
    void enqueue(T item, int priority);
    T dequeue();

    T peek() const;
    int peekPriority() const;
    int length() const;
    bool isEmpty() const;
    bool isFull() const;
    void printQueue(ofstream&) const;
private:
    QNode<T>* head;
    int queueLength;
};