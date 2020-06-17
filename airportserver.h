/*      Initially, we begin by creating a struct to simulate a queue.
/*      The purpose of a user-defined struct is to enable ease of use
/*      and write functions suited specifically for the purpose required.   */
typedef struct Queue
{
    int * entry;
    int tail;
    int capacity;
} queue;

queue * create_queue(int);

int queue_length(queue *);

void enqueue(queue *, int);

int dequeue(queue *);

int will_Occur(float);