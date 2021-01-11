#ifndef SO_CONTROLLER_H
#define SO_CONTROLLER_H

#include "vector"
#include "Algorithms.h"
#include "File_operation.h"




class Controller
{
    Algorithms &algorithms;
    File_operation &file;
    State current_state;
    Data_option data_option;

public:
    Controller(Algorithms &a, File_operation &f);
    State get_state() const;
    void draw();
};


#endif
