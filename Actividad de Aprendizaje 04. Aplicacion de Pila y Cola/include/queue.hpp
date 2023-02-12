// queue.hpp and .cpp
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "queueexception.hpp"
// DEFINITION
template <typename T, int ARRAYSIZE = 1024>
class Queue {
 private:
  T data[ARRAYSIZE];
  int front;
  int end;

  void copyAll(const Queue<T, ARRAYSIZE>&);  // auxiliar method to copy element
                                             // from another Queue
 public:
  Queue();
  Queue(const Queue<T, ARRAYSIZE>&);  // starts the queue with another queue

  bool isEmpty();  // checks if its empty returns true or false
  bool isFull();   // checks if its full returns true or false

  void removesAll();  // removes all the data from the queue

  void enqueue(const T&);  // adds an element on the end of the queue
  void dequeue();          // removes an element on the front of the queue

  T getFront();  // return the element on the front of the queue

  Queue<T, ARRAYSIZE>& operator=(const Queue<T, ARRAYSIZE>&);
};

// IMPLEMENTATION
template <typename T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE>& copyQueue) {
  if (copyQueue.front < copyQueue.end) {
    int i(copyQueue.front);
    while (i <= copyQueue.end) {
      this->data[i] = copyQueue.data[i];
      i++;
    }
    this->front = copyQueue.front;
    this->end = copyQueue.end;
  }
  if (copyQueue.front > copyQueue.end) {
    int i(copyQueue.front);
    while (i <= ARRAYSIZE - 1) {
      this->data[i] = copyQueue.data[i];
      i++;
    }
    i = 0;
    while (i <= copyQueue.end) {
      this->data[i] = copyQueue.data[i];
      i++;
    }
    this->front = copyQueue.front;
    this->end = copyQueue.end;
  }
  if (copyQueue.front == copyQueue.end) {
    data[copyQueue.front] == data[copyQueue.front];
    this->front = copyQueue.front;
    this->end = copyQueue.end;
  }
}

template <typename T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() : front(0), end(ARRAYSIZE - 1) {}

template <typename T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE>& copyQueue) {
  copyAll(copyQueue);
}

template <typename T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty() {
  return (front == end + 1) || (front == 0 && end == ARRAYSIZE - 1);
}

template <typename T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull() {
  return (front == end + 2) || (front == 0 && end == ARRAYSIZE - 2) ||
         (front == 1 && end == ARRAYSIZE - 1);
}

template <typename T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::removesAll() {
  front = 0;
  end = ARRAYSIZE - 1;
}

template <typename T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& element) {
  if (isFull()) {
    throw QueueException("Desbordamiento de datos, enqueue()");
  }
  if (++end == ARRAYSIZE) {
    end = 0;
  }
  data[end] = element;
}

template <typename T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::dequeue() {
  if (isEmpty()) {
    throw QueueException("Insuficiencia de datos, dequeue()");
  }

  if (++front == ARRAYSIZE) {
    front = 0;
  }
}

template <typename T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFront() {
  if (isEmpty()) {
    throw QueueException("Insuficiencia de datos, getFront()");
  }
  return data[front];
}

template <typename T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator=(
    const Queue<T, ARRAYSIZE>& copyQueue) {
  copyAll(copyQueue);
  return *this;
}

#endif  // __QUEUE_H__