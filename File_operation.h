#ifndef SO_FILE_OPERATION_H
#define SO_FILE_OPERATION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

struct Process
{
    int arrival_time;
    int service_time;
    std::string name;
    int waiting_time;
};

class File_operation
{
    std::ifstream input_file;
    std::vector<Process> data_storage;

public:
    File_operation();
    void data_settings(int option);
    void read_file();
    void draw_processes();
};


#endif
