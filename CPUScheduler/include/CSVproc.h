#ifndef CSVPROC_H
#define CSVPROC_H

#include "PCB.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

class CSVproc
{
    public:
        CSVproc();
        virtual ~CSVproc();
        std::vector<PCB> input(std::string);
        void output(std::string, std::vector<PCB>);
    protected:
    private:
};

#endif // CSVPROC_H
