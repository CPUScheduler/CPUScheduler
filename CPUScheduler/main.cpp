#include <iostream>
#include <vector>
#include "PCB.h"
#include "CSVproc.h"
#include "AbstractQueue.h"

using namespace std;

// tests file input/output
int main()
{
    AbstractQueue testQ = AbstractQueue(1);
    std::vector<PCB> procTable; // currently this is holds each PCB with all its information, this is different than how we initially planned to implement it
    CSVproc test;
    procTable = test.input("../processes/0.txt");
    PCB testProc = PCB(procTable[0].PID, procTable[0].subTime, procTable[0].CPU_IO);
    std::cout << testQ.pushBack(testProc) << std::endl;
    std::cout << testQ.popFront() << std::endl;
    test.output("../outputs/0.csv", procTable);
    return 0;
}
