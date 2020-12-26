#include <string>

#include "Algorithms.h"
#include "Controller.h"
#include "File_operation.h"


int main()
{
    srand(time(0));
    Algorithms a;
    File_operation file;
    Controller ctrl(a,file);


    while (ctrl.get_state() != STOP)
    {
        ctrl.draw();
    }

    return 0;
}
