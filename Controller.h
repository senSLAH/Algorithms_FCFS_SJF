#ifndef SO_CONTROLLER_H
#define SO_CONTROLLER_H


#include "Algorithms.h"
#include "vector"

enum State : int {MENU = 0 , FCFS = 1, SJF, RUN, STOP};
enum Data_option : int {FROM_FILE = 0, GENERATE_100 = 1 };

struct Process
{
    int arrival_time;
    int service_time;
    int waiting_time;
};

class Controller
{
    Algorithms & algorithms;
    State current_state;
    State last_state;
    Data_option data_option;
public:
    Controller(Algorithms &a);
    std::vector<Process> make_100_random_elemts();
    void set_state(State s);
    State get_state();
    void draw();
};


#endif
