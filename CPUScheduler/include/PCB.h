#ifndef PCB_H
#define PCB_H

#include <vector>
class PCB
{
    public:
        int PID;
        std::vector<int> CPU_IO;
        int subTime;
        int execStart;
        int complete;
        int queueTime;
        int execTime;
        int IOTime;

        PCB(int, int, std::vector<int>);
        virtual ~PCB();
    protected:
    private:
};

#endif // PCB_H
