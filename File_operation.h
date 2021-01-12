#ifndef SO_FILE_OPERATION_H
#define SO_FILE_OPERATION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

struct Process
{
    float arrival_time;
    float service_time;
    int name;
    float waiting_time;
    float turnaround_time;
    float started;
    float completed;
};

class File_operation
{
    std::ifstream input_file;
    std::ofstream output_results_data_file;
    std::ofstream output_tested_data_file;
    std::vector<Process> data_storage;
    std::vector<std::vector<Process>> data_storage_two_measures;
    int data_option;

public:
    File_operation();
    //1)otwieramy pliki i sprawdzamy czy udało ich się otwożycz
    //dalej wypisujemy otpowidni komunikaty.
    //2)rezerwujemy mejsce na stu różnych ciągów w wektoże

    void data_settings(int option);
    //"option" moge dostacz

    void read_file();
    //odczytuje zawartość pliku


    void generate_100_sets_of_100_elements();
    std::vector<Process>& get_data_storage();
    std::vector<std::vector<Process>>& get_data_storage_two_measures();
    void draw_processes() const;
    void write_results_to_file(std::vector<std::vector<float>> res);
    void write_tested_data_to_file();

    ~File_operation();
    //zamyka pliki
};


#endif
