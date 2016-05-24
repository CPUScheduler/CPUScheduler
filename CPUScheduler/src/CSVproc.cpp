#include "CSVproc.h"

//taken from http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
void Tokenize(const std::string& str,
                      std::vector<std::string>& tokens,
                      const std::string& delimiters = " ")
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

CSVproc::CSVproc()
{
    //ctor
}

CSVproc::~CSVproc()
{
    //dtor
}

std::vector<PCB> CSVproc::input(std::string filename)
{
    int pid, arrival;
    std::vector<PCB> procTable;
    std::string line;
    std::ifstream file(filename.c_str());
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<int> bursts;
            std::vector<std::string> temp;
            //std::cout << line << std::endl;
            Tokenize(line, temp, ",");

            pid = atoi(temp[0].c_str());
            arrival = atoi(temp[1].c_str());
            for(int i = 2; i < temp.size(); i++)
            {
                bursts.push_back(atoi(temp[i].c_str()));
            }
            procTable.push_back(PCB(pid, arrival, bursts));
        }
        file.close();
    }
    return procTable;
}

std::string CSVproc::output(std::vector<PCB> procTable)
{
    return "PLACE HOLDER";
}
