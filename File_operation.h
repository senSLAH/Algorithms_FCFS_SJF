#ifndef SO_FILE_OPERATION_H
#define SO_FILE_OPERATION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

#include "Algorithms.h"

struct Process
{
    float arrival_time;
    float service_time;
    int name;
    int waiting_time;
    int turnaround_time;
    int started;
    int completed;
};

class File_operation
{
    std::ifstream input_file;
    std::ofstream output_file;
    std::vector<Process> data_storage;
    std::vector<std::vector<Process>> data_storage_two_measures;
    int data_option;

public:
    File_operation();
    void data_settings(int option);
    void read_file();
//    void write_to_file(std::vector<Results> results);
    void generate_100_sets_of_100_elements();
    std::vector<Process>& get_data_storage();
    std::vector<std::vector<Process>> get_data_storage_two_measures() const;
    void draw_processes() const;
    ~File_operation();
};


#endif
