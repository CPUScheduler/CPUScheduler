#include "PCB.h"

PCB::PCB(int procID, int arrival, std::vector<int> CPU_IOTimes)
{
    PID = procID;
    subTime = arrival;
    CPU_IO = CPU_IOTimes;
    execStart = complete = queueTime = execTime = IOTime = -1;
}

PCB::~PCB()
{
    //dtor
}
