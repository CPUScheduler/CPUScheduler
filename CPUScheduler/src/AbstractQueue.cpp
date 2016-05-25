#include "AbstractQueue.h"

AbstractQueue::AbstractQueue()
{
    maxSize = 0;
}

AbstractQueue::AbstractQueue(unsigned int ms)
{
    maxSize = ms;
}

AbstractQueue::~AbstractQueue()
{
    //dtor
}

int AbstractQueue::pushBack(PCB proc)
{
    if(PCBqueue.size() < maxSize)
    {
        PCBqueue.push(proc);
        maxSize++;
        return 1;
    }
    else
    {
        return -1;
    }

}

int AbstractQueue::popFront()
{
    if(PCBqueue.size() == 0)
    {
        return -1;
    }
    else
    {
        PCBqueue.pop();
        maxSize--;
        return 1;
    }
}
