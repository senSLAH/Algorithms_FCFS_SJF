#include "Process.h"

Process::Process()
{
}

void Process::set_arrival_time(int time)
{
    arrival_time = time;
}

void Process::set_service_time(int time)
{
    service_time = time;
}

void Process::set_waiting_time(int time)
{
    waiting_time = time;
}

