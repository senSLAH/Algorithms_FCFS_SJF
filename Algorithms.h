#ifndef SO_ALGORITHMS_H
#define SO_ALGORITHMS_H
#include "vector"
#include "File_operation.h"

enum State : int {MENU = 0 , FCFS = 1, SJF, WRITE ,STOP};
enum Data_option : int {NOT_CHOSEN = 0, FROM_FILE = 1, _100_sets_of_100_elements = 2 };


class Algorithms
{
    std::vector<std::vector<float>> results;
public:
    Algorithms();
    void run_algorithm(State algorithm_type, Data_option option);
    void FCFS_algorithm(std::vector<Process> &arr_of_proces);
    void FCFS_algorithm_two_measures(std::vector<std::vector<Process>> &arr_of_proces);
    void SJF_algorith(std::vector<Process> &arr_of_proces);
    void average_TAT_WT(std::vector<Process> &arr_of_proces);
    std::vector<std::vector<float>> get_results();
    void bubble_sort(std::vector<Process> &arr_of_proces, std::string str = "arrival");
};


#endif
