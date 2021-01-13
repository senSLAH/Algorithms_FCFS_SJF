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

    void FCFS_algorithm(std::vector<Process> &arr_of_proces);

    void FCFS_algorithm_two_measures(std::vector<std::vector<Process>> &arr_of_proces);
    //dziłanie polega na wywoławniu algorytmu FCFS(FCFS_algorithm()) dla każdego z cągu procesów

    void SJF_algorith(std::vector<Process> &arr_of_proces);

    void SJF_algorithm_two_measures(std::vector<std::vector<Process>> &arr_of_proces);
    //dziłanie polega na wywoławniu algorytmu SJF(SJF_algorith) dla każdego z cągu procesów

    void average_TAT_WT(std::vector<Process> &arr_of_proces);
    // oblicza Average turnaround time i Average waiting time

    void average_TAT_WT(std::vector<std::vector<float>> results);
    //oblicza średnią ze średnich ze stu cągów

    std::vector<std::vector<float>> get_results();

    void bubble_sort(std::vector<Process> &arr_of_proces, std::string option = "arrival");
    // funkcja bubble_sort kożysta z algorymu bubble sort przyjmuje dwa parametry:
    // *-> 'arr_of_proces' który zawiera wszystki procesy
    // *-> 'option' może przyjmować dwa parametry "arrival" lub "service"
    // sortuje elementy w 'arr_of_proces' według paramentru "arrival" lub "service"
    // w zależności od wartosci "option"
};


#endif
