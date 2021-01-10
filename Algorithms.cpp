#include "Algorithms.h"

Algorithms::Algorithms()
{
}

void Algorithms::FCFS_algorithm(std::vector<Process> &arr_of_proces)
{
    //Korzystamy z babble sort żeby  wysortować procesy
    // w kolejności od najmnejszego czasu przybycia
    bubble_sort(arr_of_proces);

    int current_time = 0;
    for (int i = 0; i < arr_of_proces.size(); ++i)//Iterujemy się po wszystkim processam
    {
        if (current_time < arr_of_proces[i].arrival_time)//jeżeli żaden process jeszcze nie czeka na wywołanie
        {                                                //to znaczy że process zaczyna się w czsie przybyczia
            arr_of_proces[i].started = arr_of_proces[i].arrival_time;
            current_time = arr_of_proces[i].service_time + arr_of_proces[i].started;
        }
        else//Jeżeli process już czeka w kolejce. Zaczyna się w momencie, gdy kończy się ostatni.
        {
            arr_of_proces[i].started = current_time;
            current_time = arr_of_proces[i].service_time + current_time;//liczymy w jakiem czasie process sie skończy
        }
        arr_of_proces[i].completed = current_time;
        arr_of_proces[i].turnaround_time = arr_of_proces.at(i).completed - arr_of_proces.at(i).arrival_time;
        arr_of_proces[i].waiting_time = arr_of_proces.at(i).turnaround_time - arr_of_proces.at(i).service_time;
    }

    average_TAT_WT(arr_of_proces);//
}

void Algorithms::SJF_algorith(std::vector<Process> &arr_of_proces)
{
    std::vector<Process> correct_sequence;
    std::vector<Process> temp_queue;//kolejka

    bubble_sort(arr_of_proces);//Korzystamy z babble sort żeby  posortować procesy
                                  // w kolejności od najmnejszego czasu przybycia

    int current_time = 0;
    int arr_size = arr_of_proces.size();
    bool first_iteration = true;
    for (int i = 0; i < arr_size; ++i)
    {
        //zapisujemy do kolejki wszyski elementy które już czekają na wywołanie
        for (int j = 0; j < arr_of_proces.size(); ++j)//iterujemy sie po wszystkim procesam
        {
            if (current_time >= arr_of_proces[j].arrival_time || first_iteration)//jeżeli current_time >= czasu przybycia to znaczy że proces
            {                                                                    //proces już czeka na wywołanie
                temp_queue.push_back(arr_of_proces[j]);
                arr_of_proces.erase(arr_of_proces.begin() + j);//zmniejszamy vectotr
                j = -1;// zmnięszamy j dlatego że zmniejszyliśmy vectotr
                first_iteration = false;
            }
        }

        if (temp_queue.size() != 0)
        {
            bubble_sort(temp_queue, "service");//sortujemy procesy według service_time
            correct_sequence.push_back(temp_queue[0]);
            temp_queue.erase(temp_queue.begin());
        }
        else//w tym momencice czasu żaden z procesow nie czeka na wywołanie
        {
            --i;
            current_time = arr_of_proces[0].arrival_time;//zwiększamy current_time
            continue;
        }


        if (current_time < correct_sequence[i].arrival_time)
        {
            correct_sequence[i].started = correct_sequence[i].arrival_time;
            current_time = correct_sequence[i].service_time + correct_sequence[i].started;
        }
        else
        {
            correct_sequence[i].started = current_time;
            current_time = correct_sequence[i].service_time + current_time;
        }
        correct_sequence[i].completed = current_time;
        correct_sequence[i].turnaround_time = correct_sequence.at(i).completed - correct_sequence.at(i).arrival_time;
        correct_sequence[i].waiting_time = correct_sequence.at(i).turnaround_time - correct_sequence.at(i).service_time;
    }
    average_TAT_WT(correct_sequence);
}

void Algorithms::bubble_sort(std::vector<Process> &arr_of_proces, std::string option)
{
    bool swapped;
    for (int i = 0; i < arr_of_proces.size()-1; ++i)
    {
        swapped = false;
        for (int j = 0; j < arr_of_proces.size()-i-1; ++j)
        {
            if (arr_of_proces[j].arrival_time > arr_of_proces[j+1].arrival_time && option == "arrival")
            {
                std::swap(arr_of_proces[j],arr_of_proces[j+1]);
                swapped = true;
            }
            if (arr_of_proces[j].service_time > arr_of_proces.at(j+1).service_time && option == "service")
            {
                std::swap(arr_of_proces[j],arr_of_proces[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// liczy Average turnaround time i Average waiting time
void Algorithms::average_TAT_WT(std::vector<Process> &arr_of_proces)
{
    float avg_turnaround = 0;
    float avg_waiting = 0;

    for (int i = 0; i < arr_of_proces.size(); ++i)
    {
        avg_turnaround += arr_of_proces[i].turnaround_time;
        avg_waiting += arr_of_proces[i].waiting_time;
    }

    avg_turnaround = avg_turnaround / arr_of_proces.size();
    avg_waiting = avg_waiting / arr_of_proces.size();

    std::vector<float> res;
    res.push_back(avg_waiting);
    res.push_back(avg_turnaround);
    results.push_back(res);
    std::cout << "Average waiting time: " << avg_waiting << "\n";
    std::cout << "Average turnaround time: " << avg_turnaround << "\n";
}

std::vector<std::vector<float>> Algorithms::get_results()
{
    return results;
}

void Algorithms::FCFS_algorithm_two_measures(std::vector<std::vector<Process>> &arr_of_proces)
{
    for (int i = 0; i < arr_of_proces.size(); ++i)
    {
        FCFS_algorithm(arr_of_proces[i]);
    }
}



