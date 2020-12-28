#include <iostream>
#include "Controller.h"


Controller::Controller(Algorithms &a, File_operation &f):algorithms(a), file(f)
{
    last_state = current_state = MENU;
    data_option = NOT_CHOSEN;
}


State Controller::get_state() const
{
    return current_state;
}

void Controller::draw()
{
    int temp;
    if (current_state == MENU)
    {
        temp = 0;
        std::cout << "\nAlgoritms:\n";
        std::cout << "1) FCFS\n";
        std::cout << "2) SJF\n";
        std::cout << "\nYour choice:\n";

        std::cin >> temp;
        if (temp < 3 && temp > 0)
        {
            last_state = current_state;
            current_state = static_cast<State>(temp);
        }
        else
            std::cout << "Plese chose 1 or 2";
    }

    if ((current_state == FCFS || current_state == SJF) && data_option == NOT_CHOSEN)
    {
        temp = 0;
        std::cout << "\n1) Use data from file\n";
        std::cout << "2) Generate 100 sets of 100 elements each\n";
        std::cout << "Chose option:\n";

        std::cin >> temp;
        data_option = static_cast<Data_option>(temp);
        file.data_settings(temp);
    }

    if ((current_state == FCFS || current_state == SJF) && data_option != NOT_CHOSEN)
    {
        std::cout << "\n1) Show data\n";
        std::cout << "2) Run algorithm" << "\n";
        std::cout << "Chose option:\n";
        std::cin >> temp;
        if (temp == 1)
            file.draw_processes();
        if (temp == 2 && current_state == FCFS && data_option == FROM_FILE)
        {
            algorithms.FCFS_algorithm(file.get_data_storage());
            current_state = WRITE;
        }
        if (temp == 2 && current_state == SJF && data_option == FROM_FILE)
        {
            algorithms.SJF_algorith(file.get_data_storage());
            current_state = WRITE;
        }
        if (current_state == WRITE)
        {
            // функция для записи в файл результатов
            file.write_to_file(algorithms.get_results());
            current_state = STOP;
        }
    }
}

void Controller::set_state(State s)
{
    current_state = s;
}
