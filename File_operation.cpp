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
}

void File_operation::data_settings(int option)
{
    if (option == 1)
        read_file();
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
            temp.name = data_form_file[i];
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



