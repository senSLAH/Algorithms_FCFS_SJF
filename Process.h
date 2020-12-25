#ifndef SO_PROCESS_H
#define SO_PROCESS_H

class Process
{
    int arrival_time;
    int service_time;
    int waiting_time;
public:
    Process();
    void set_arrival_time(int time);
    void set_service_time(int time);
    void set_waiting_time(int time);
};











#endif
