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
    //cout << "Hello world!" << endl;
    cout<< procTable[1999].subTime<<endl;
    return 0;
}
