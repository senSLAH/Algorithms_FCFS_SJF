#include <iostream>
#include "Controller.h"


Controller::Controller(Process &p, Algorithms &a):process(p),algorithms(a)
{
    state = Menu;
}

std::vector<Process> Controller::make_100_random_elemts()
{
    std::vector<Process> temp;
    for (int i = 0; i < 100; ++i)
    {
        Process process;
        process.set_arrival_time(rand() % 50);
        process.set_service_time(rand() % 50);
        temp.push_back(process);
    }
    return temp;
}

State Controller::get_state()
{
    return state;
}

void Controller::draw()
{
    int temp = 0;
    if (state == Menu)
    {
        std::cout << "\nAlgoritms:\n";
        std::cout << "1) FCFS\n";
        std::cout << "2) SJF\n";

        while (temp != 1 && temp != 2)
        {
            std::cout << "\nYour choice:\n";
            std::cin >> temp;
            if (temp > 2 || temp < 1)
                std::cout << "Plese chose 1 or 2";
            else
                state = static_cast<State>(temp);
        }

    }
}

void Controller::set_state(State s)
{
    state = s;
}
