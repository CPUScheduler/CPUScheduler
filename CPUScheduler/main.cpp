#include <iostream>
#include <vector>
#include "PCB.h"
#include "CSVproc.h"
//#include <direct.h>

using namespace std;

// tests file input/output
int main()
{
    std::vector<PCB> procTable; // currently this is holds each PCB with all its information, this is different than how we initially planned to implement it
    CSVproc test;
    procTable = test.input("../processes/0.txt");
    test.output("../outputs/0.csv", procTable);
    return 0;
}
