#include "File_operation.h"

File_operation::File_operation()
{
    input_file.open("../Test_data.txt");
    if (!input_file.is_open())
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    std::cout << "File opened successfully!";

    data_storage_two_measures.resize(100);
    for (auto & data_storage_two_measure : data_storage_two_measures)
    {
        data_storage_two_measure.resize(100);
    }

}

void File_operation::data_settings(int option)
{
    if (option == 1)
        read_file();
    if (option == 2)
        generate_100_sets_of_100_elements();

}

void File_operation::read_file()
{
    char ch;
    std::string data_form_file;
    Process temp;
    while (input_file.get(ch))
        data_form_file += ch;

    for (int i = 0; i < data_form_file.size(); ++i)
    {
        if (data_form_file[i] == 'P')
        {
            i += 1;
            temp.name = (int)data_form_file[i] - (int)'0';
        }
        if (data_form_file[i] == 's')
        {
            i += 2;
            temp.service_time = (int)data_form_file[i] - (int)'0';
        }
        if (data_form_file[i] == 'a')
        {
            i += 2;
            temp.arrival_time = (int)data_form_file[i] - (int)'0';
            data_storage.push_back(temp);
        }
    }
    draw_processes();
}

void File_operation::draw_processes()
{
    for (auto & i : data_storage)
    {
        std::cout << i.name;
        std::cout << i.service_time;
        std::cout << i.arrival_time;
        std::cout << "\n--------------------------------------\n";
    }
}

void File_operation::generate_100_sets_of_100_elements()
{
    Process temp;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            temp.name = j+1;
            temp.arrival_time = rand() % 19 + 2;
            temp.service_time = rand() % 50;
            data_storage_two_measures[i][j] = temp;
        }
    }

    for (int i = 0; i < data_storage_two_measures.size(); ++i)
    {
        for (int j = 0; j < data_storage_two_measures[i].size(); ++j)
        {
             std::cout << "Process: " << data_storage_two_measures[i][j].name << " in the first sample:" << i+1 << "\n";
             std::cout << "Service time: " << data_storage_two_measures[i][j].service_time << "\n";
             std::cout << "Arrival time: " << data_storage_two_measures[i][j].arrival_time << "\n";
             std::cout << "\n--------------------------------------\n";
        }

    }
    std::cin >> temp.name;
}



