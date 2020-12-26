#ifndef SO_CONTROLLER_H
#define SO_CONTROLLER_H

#include "vector"
#include "Algorithms.h"
#include "File_operation.h"


enum State : int {MENU = 0 , FCFS = 1, SJF, RUN, STOP};
enum Data_option : int {NOT_CHOSEN = 0, FROM_FILE = 1, GENERATE_100 = 2 };


class Controller
{
    Algorithms &algorithms;
    File_operation &file;
    State current_state;
    State last_state;
    Data_option data_option;
public:
    Controller(Algorithms &a, File_operation &f);
    std::vector<Process> make_100_random_elemts();
    void set_state(State s);
    State get_state();
    void draw();
};


#endif
