#ifndef SO_CONTROLLER_H
#define SO_CONTROLLER_H

#include "Process.h"
#include "Algorithms.h"
#include "vector"

enum State : int {Menu = 0 , FCFS = 1, SJF, RUN, STOP};

class Controller
{
    Process & process;
    Algorithms & algorithms;
    State state;
public:
    Controller(Process &p, Algorithms &a);
    std::vector<Process> make_100_random_elemts();
    void set_state(State s);
    State get_state();
    void draw();
};


#endif
