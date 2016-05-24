#include "CSVproc.h"

/*
 * A nice function I found online for splitting a string based on a character, used in file reading
 * taken from http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
 */
void Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ")
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

// might not need these
CSVproc::CSVproc()
{
    //ctor
}

CSVproc::~CSVproc()
{
    //dtor
}

// reads a process file and creates a process table based off of it
std::vector<PCB> CSVproc::input(std::string filename)
{
    int pid, arrival; // containers used in creation
    std::vector<PCB> procTable; // the object to return
    std::string line; // holds individual lines of the file
    std::ifstream file(filename.c_str()); // give the file
    if(file.is_open())
    {
        // read the file line by line
        while(getline(file,line))
        {
            std::vector<int> bursts;
            std::vector<std::string> temp;
            Tokenize(line, temp, ","); // split the line into a vector of strings

            pid = atoi(temp[0].c_str()); // the first entry is the PID
            arrival = atoi(temp[1].c_str()); // the second entry is the arrival time
            // all following entries are a part of the CPU/IO burst vector
            for(unsigned int i = 2; i < temp.size(); i++)
            {
                bursts.push_back(atoi(temp[i].c_str()));
            }
            procTable.push_back(PCB(pid, arrival, bursts)); // add the new process to the table
        }
        file.close();
    }
    return procTable; // return the table
}

// produces a file from a process table
void CSVproc::output(std::string filename, std::vector<PCB> procTable)
{
    std::ofstream file;
    file.open(filename.c_str()); // create the file
    file << "PID,Submitted,Started,Completed,Queues,Executing,IO\n"; // print the heading
    // add one line at a time
    for(unsigned int i = 0; i < procTable.size(); i++)
    {
        // write the entire line to the file
        file << procTable[i].PID << "," << procTable[i].subTime << "," << procTable[i].execStart << ","
             << procTable[i].complete << "," << procTable[i].queueTime << "," << procTable[i].execTime << ","
             << procTable[i].IOTime << "\n";
    }
    file.close();
}
