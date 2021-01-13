#ifndef SO_CONTROLLER_H
#define SO_CONTROLLER_H

#include "vector"
#include "Algorithms.h"
#include "File_operation.h"



class Controller
{
    Algorithms &algorithms;
    File_operation &file;
    State current_state;//stan programu
    Data_option data_option;//zawiera dane czy będziemy kożystać z odczytu plika lub generacji procesów

public:
    Controller(Algorithms &a, File_operation &f);
    //wartości domyślne dla current_state data_option

    State get_state() const;
    //zwraca stan programu

    void draw();
    //wyświetla Menu i zarządza stanem programu(current_state)

};


#endif
