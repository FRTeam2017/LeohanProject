#ifdef _Queue
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int *array;
	//size 表示剩余空间的大小
};

struct Queue * createQueue(unsigned capacity)
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int *)malloc(sizeof(queue->capacity * sizeof(int)));
	return queue;
}

int isFull(struct Queue *queue)
{
	return queue->size == queue->capacity;
}

int isEmpty(struct Queue * queue)
{
	return queue->size == 0;
}

void enqueue(struct Queue * queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << "enqueued to queue " << item << endl;
}

int dequeue(struct Queue *queue)
{
	if (isEmpty(queue))
	{
		return INT_MIN;
	}
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int Front(struct Queue * queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main()
{
	struct Queue* queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	printf("%d dequeued from queue\n", dequeue(queue));

	printf("Front item is %d\n", Front(queue));
	printf("Rear item is %d\n", rear(queue));

	return 0;
}
#endif // _Queue