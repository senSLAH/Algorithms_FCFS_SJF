#include <iostream>
#include "Controller.h"


Controller::Controller(Algorithms &a, File_operation &f):algorithms(a), file(f)
{
    last_state = current_state = MENU;
    data_option = NOT_CHOSEN;
}


State Controller::get_state()
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

        while (true)
        {
            std::cout << "\nYour choice:\n";
            std::cin >> temp;
            if (temp < 3 && temp > 0)
            {
                last_state = current_state;
                current_state = static_cast<State>(temp);
                break;
            }
            else
                std::cout << "Plese chose 1 or 2";
        }
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
}

void Controller::set_state(State s)
{
    current_state = s;
}
