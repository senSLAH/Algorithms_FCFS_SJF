#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Process.h"
#include "Algorithms.h"
#include "Controller.h"


int main()
{
    srand(time(0));
    std::cout << "Start...\n";
    std::string path = "../Test_data.txt";
    std::ifstream input_file;


    Process p{};
    Algorithms a;
    Controller ctrl(p,a);
    input_file.open(path);
    if (!input_file.is_open())
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    std::cout << "File opened successfully!";

    while (ctrl.get_state() != STOP)
    {
        ctrl.draw();
    }




    input_file.close();

    return 0;
}
