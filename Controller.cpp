#include <iostream>
#include "Controller.h"


Controller::Controller(Algorithms &a):algorithms(a)
{
    current_state = MENU;
}

std::vector<Process> Controller::make_100_random_elemts()
{
    std::vector<Process> temp;
    for (int i = 0; i < 100; ++i)
    {
        Process process;
        process.arrival_time = rand() % 50;
        process.service_time = rand() % 50;
        temp.push_back(process);
    }
    return temp;
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
                current_state = static_cast<State>(temp);
                break;
            }
            else
                std::cout << "Plese chose 1 or 2";
        }
    }
    if (current_state == FCFS || current_state == SJF)
    {
        temp = 0;
        std::cout << "\n1) Use data from file\n";
        std::cout << "2) Use 100 randomly generated values\n";
        std::cout << "3) Use 1000 randomly generated values\n";
        std::cout << "Chose option:\n";
        std::cin >> temp;
    }
}

void Controller::set_state(State s)
{
    current_state = s;
}
