#include<stdio.h>
#include<stdlib.h>
#include"airportserver.h"

/*      The create_queue() function is intended to work similar to the
/*      getnode() function usually defined with respect to linked lists.
/*      It statically generates a queue struct to allow easy definitions
/*      to structs later on.                                                */
queue* create_queue(int capacity)
{
    queue* queue = (struct Queue *) malloc(sizeof(queue));
    queue->tail = 0;
    queue->capacity = capacity;

    //A dynamically allocated array of integers allows easy  resizing of the queue.
    queue->entry = (int *) malloc(capacity*sizeof(int));
    return queue;
}

int queue_length(queue* runway)
{
    return runway->tail;
}


/*      Two basic queueing operations have been simulated here: enqueue and
/*      dequeue. The queue is a data structure working on a First-In, First
/*      -Out (FIFO) model, which is difficult to directly simulate within
/*      the main function. Thus, the functions are declared separately.     */
void enqueue(queue* runway, int air_req)
{
    runway->entry[runway->tail] = air_req;
    if (runway->tail == runway->capacity - 1)
            {
                //runway->tail = 0;
                printf("\nWarning: Runway reaching full capacity");
            }

    else runway->tail++;
}

int dequeue(queue* runway)
{
    int x = runway->entry[0];

    /*      The following reshaping of the array is a time-cost heavy operation,
    /*      capable of optimization by implementing a floating head pointer. However,
    /*      implementing a secondary pointer to the queue in addition to the tail
    /*      enables the program to encounter multiple segmentation faults in its
    /*      implementation in certain instances of emptying the queues.         */

    for (int i = 0; i < runway->tail; i++)
        runway->entry[i] = runway->entry[i+1];
    runway->tail--;
    return x;
}

/*      The following function implements a random probability generator
/*      to determine whether or not a particular plane will send in a request
/*      during a particular simulation or not. The generator is not very
/*      sophisticated, and manipulates the constant RAND_MAX to check whether
/*      a plane will land or not. A Poisson distribution can also be used to
/*      create a more sophisticated probability generator.                  */
int will_Occur(float arr_prob)
{
    float lim = arr_prob*RAND_MAX;
    float x = rand();
    if (x < lim)
        return 1;
    return 0;
}