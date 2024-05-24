#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/queue.h"

int main()
{
    // Test Case 1: Enqueue and dequeue elements normally
    QueuePtr queue1 = initQueue("Test", 5);
    printf("Test Case 1: Enqueue and dequeue elements normally\n");
    queue1->enqueue(queue1, 'A');
    queue1->enqueue(queue1, 'B');
    printf("Dequeued: %c\n", queue1->dequeue(queue1)); // A
    queue1->enqueue(queue1, 'C');
    printf("Dequeued: %c\n", queue1->dequeue(queue1)); // B
    queue1->enqueue(queue1, 'D');
    queue1->enqueue(queue1, 'E');
    printf("Dequeued: %c\n", queue1->dequeue(queue1)); // C
    printf("Dequeued: %c\n", queue1->dequeue(queue1)); // D
    printf("Dequeued: %c\n", queue1->dequeue(queue1)); // E
    free(queue1);

    // Test Case 2: Enqueue and dequeue more elements than capacity
    QueuePtr queue2 = initQueue("Test", 3);
    printf("\nTest Case 2: Enqueue and dequeue more elements than capacity\n");
    queue2->enqueue(queue2, 'A');
    queue2->enqueue(queue2, 'B');
    queue2->enqueue(queue2, 'C');
    queue2->enqueue(queue2, 'D');                      // Should not enqueue, queue is full
    printf("Dequeued: %c\n", queue2->dequeue(queue2)); // A
    queue2->enqueue(queue2, 'E');                      // Should enqueue E
    printf("Dequeued: %c\n", queue2->dequeue(queue2)); // B
    printf("Dequeued: %c\n", queue2->dequeue(queue2)); // C
    printf("Dequeued: %c\n", queue2->dequeue(queue2)); // E
    free(queue2);

    // Test Case 3: Enqueue and dequeue from an empty queue
    QueuePtr queue3 = initQueue("Test", 4);
    printf("\nTest Case 3: Enqueue and dequeue from an empty queue\n");
    printf("Attempted to dequeue: ");
    if (queue3->dequeue(queue3) == '\0')
        printf("No element dequeued\n");
    queue3->enqueue(queue3, 'X');
    printf("Dequeued: %c\n", queue3->dequeue(queue3)); // X
    free(queue3);

    // Test Case 4: Check isFull and isEmpty functions
    QueuePtr queue4 = initQueue("Test", 3);
    printf("\nTest Case 4: Check isFull and isEmpty functions\n");
    printf("Is queue full? %s\n", queue4->isFull(queue4) ? "Yes" : "No");   // No
    printf("Is queue empty? %s\n", queue4->isEmpty(queue4) ? "Yes" : "No"); // Yes
    queue4->enqueue(queue4, 'A');
    queue4->enqueue(queue4, 'B');
    queue4->enqueue(queue4, 'C');
    printf("Is queue full? %s\n", queue4->isFull(queue4) ? "Yes" : "No");   // Yes
    printf("Is queue empty? %s\n", queue4->isEmpty(queue4) ? "Yes" : "No"); // No
    free(queue4);

    // Test Case 5: Check peek function
    QueuePtr queue5 = initQueue("Test", 3);
    printf("\nTest Case 5: Check peek function\n");
    queue5->enqueue(queue5, 'X');
    printf("Peeked element: %c\n", queue5->peek(queue5)); // X
    queue5->enqueue(queue5, 'Y');
    queue5->enqueue(queue5, 'Z');
    printf("Peeked element: %c\n", queue5->peek(queue5)); // X
    free(queue5);

    // Test Case 6: Check size function
    QueuePtr queue6 = initQueue("Test", 4);
    printf("\nTest Case 6: Check size function\n");
    printf("Queue size: %u\n", queue6->size(queue6)); // 0
    queue6->enqueue(queue6, 'A');
    queue6->enqueue(queue6, 'B');
    printf("Queue size: %u\n", queue6->size(queue6)); // 2
    queue6->dequeue(queue6);
    printf("Queue size: %u\n", queue6->size(queue6)); // 1
    queue6->enqueue(queue6, 'C');
    queue6->enqueue(queue6, 'D');
    printf("Queue size: %u\n", queue6->size(queue6)); // 3
    free(queue6);

    return 0;
}
