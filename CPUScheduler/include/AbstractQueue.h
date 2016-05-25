#ifndef ABSTRACTQUEUE_H
#define ABSTRACTQUEUE_H

#include <queue>
#include "PCB.h"

class AbstractQueue
{
    public:
        unsigned int maxSize;
        std::queue<PCB> PCBqueue; // might need to change this to support sorting
        AbstractQueue();
        AbstractQueue(unsigned int);
        virtual ~AbstractQueue();
        int pushBack(PCB);
        int popFront();

    protected:
    private:
};

#endif // ABSTRACTQUEUE_H
