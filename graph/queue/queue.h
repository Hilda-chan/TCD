#ifndef QUEUE_H_
#define QUEUE_H_

#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};


struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);


#endif
