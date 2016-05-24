#include "PCB.h"

// a basic PCB implementation I needed to work on the file input/output functions
PCB::PCB(int procID, int arrival, std::vector<int> CPU_IOTimes)
{
    PID = procID;
    subTime = arrival;
    CPU_IO = CPU_IOTimes;
    execStart = complete = queueTime = execTime = IOTime = -1; // initialize all to -1 to start
}

PCB::~PCB()
{
    //dtor
}
