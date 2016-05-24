#include <iostream>
#include <vector>
#include "PCB.h"
#include "CSVproc.h"
#include <direct.h>

using namespace std;

int main()
{
    std::vector<PCB> procTable;
    CSVproc test;
    procTable = test.input("../processes/0.txt");
    test.output("../outputs/0.csv", procTable);
    return 0;
}
