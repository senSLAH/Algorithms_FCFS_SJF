#include "Algorithms.h"

Algorithms::Algorithms()
{
}

//void Algorithms::run_algorithm(State algorithm_type, Data_option option)
//{
//    if (algorithm_type == FCFS)
//    {
//        if (option == FROM_FILE)
//        {
//            FCFS_algorithm()
//        }
//        if (option == _100_sets_of_100_elements){}
//    }
//    if (algorithm_type == SJF)
//    {
//        if (option == FROM_FILE){}
//        if (option == _100_sets_of_100_elements){}
//    }
//}

void Algorithms::FCFS_algorithm(std::vector<Process> &arr_of_proces)
{
    //bable sort. FCFS
    bool swapped;
    for (int i = 0; i < arr_of_proces.size()-1; ++i)
    {
        swapped = false;
        for (int j = 0; j < arr_of_proces.size()-i-1; ++j)
        {
            if (arr_of_proces[j].arrival_time > arr_of_proces[j+1].arrival_time)
            {
                std::swap(arr_of_proces[j],arr_of_proces[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    //liczimy started time

    int current_time = 0;
    float avg_turnaround = 0;
    float avg_waiting = 0;
    for (int i = 0; i < arr_of_proces.size(); ++i)
    {
        if (current_time < arr_of_proces[i].arrival_time)
        {
            arr_of_proces[i].started = arr_of_proces[i].arrival_time;
            current_time = arr_of_proces[i].service_time + arr_of_proces[i].started;
        }
        else
        {
            arr_of_proces[i].started = current_time;
            current_time = arr_of_proces[i].service_time + current_time;
        }


        arr_of_proces[i].completed = current_time;

        arr_of_proces[i].turnaround_time = arr_of_proces.at(i).completed - arr_of_proces.at(i).arrival_time;
        arr_of_proces[i].waiting_time = arr_of_proces.at(i).turnaround_time - arr_of_proces.at(i).service_time;

    }


    for (int i = 0; i < arr_of_proces.size(); ++i)
    {
        avg_turnaround += arr_of_proces[i].turnaround_time;
        avg_waiting += arr_of_proces[i].waiting_time;
    }

    avg_turnaround = avg_turnaround / arr_of_proces.size();
    avg_waiting = avg_waiting / arr_of_proces.size();

    std::cout << "Average waiting time: " << avg_waiting << "\n";
    std::cout << "Average turnaround time: " << avg_turnaround << "\n";
}

void Algorithms::SJF_algorith(std::vector<Process> &arr_of_proces)
{

    bool swapped;
    for (int i = 0; i < arr_of_proces.size()-1; ++i)
    {
        swapped = false;
        for (int j = 0; j < arr_of_proces.size()-i-1; ++j)
        {
            if (arr_of_proces[j].arrival_time > arr_of_proces[j+1].arrival_time)
            {
                std::swap(arr_of_proces[j],arr_of_proces[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }


//  
}



