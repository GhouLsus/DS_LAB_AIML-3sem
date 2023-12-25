#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *queue; 
    int r,f;
    int cap;
} QUEUE;

void PriorityQueuePush (QUEUE *apq,int x)
{
    if (apq->f==-1)
        apq->f=0;
    apq->r = (apq->r+1)%apq->cap;
    apq->queue[apq->r] = x;
}

void PriorityQueueDelete (QUEUE *apq)
{
        int small = apq->queue[apq->f];
    int index = 0;
    for (int i = apq->f + 1; i <= apq->r; i++)
    {
        if (small > apq->queue[i])
        {
            small = apq->queue[i];
            index = i;
        }
    }
    for (int i = index + 1; i <= apq->r; i++)
        apq->queue[i - 1] = apq->queue[i];
    apq->r--;
    return small;
}