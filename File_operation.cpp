#include "File_operation.h"

File_operation::File_operation()
{
    data_option = 0;
    input_file.open("../Test_data.txt");
    if (!input_file.is_open())
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    output_file.open("../Results.txt");
    if (!output_file.is_open())
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    std::cout << "File input file opened successfully!";
    std::cout << "File output file opened successfully!";

    data_storage_two_measures.resize(100);
    for (auto & data_storage_two_measure : data_storage_two_measures)
    {
        data_storage_two_measure.resize(100);
    }

}

void File_operation::data_settings(int option)
{
    data_option = option;
    if (option == 1)
        read_file();
    if (option == 2)
        generate_100_sets_of_100_elements();
}

void File_operation::read_file()
{
    char ch;
    std::string data_form_file;
    std::string save_value;
    Process temp{};
    while (input_file.get(ch))
        data_form_file += ch;

    for (int i = 0; i < data_form_file.size(); ++i)
    {
        save_value = "";
        if (data_form_file[i] == 'P')
        {
            while (true)
            {
                i += 1;
                if(data_form_file[i] == ':')
                    break;
                save_value += data_form_file[i];
            }
            temp.name = stoi(save_value);
        }
        if (data_form_file[i] == 's')
        {
            save_value = "";
            while (true)
            {
                i += 1;
                if (data_form_file[i] == '=')
                    continue;
                else if(data_form_file[i] == ' ')
                    break;
                save_value += data_form_file[i];
            }
            temp.service_time = stoi(save_value);
        }
        if (data_form_file[i] == 'a')
        {
            save_value = "";
            while (true)
            {
                i += 1;
                if (data_form_file[i] == '=')
                    continue;
                else if(data_form_file[i] == '\n' || data_form_file[i] == '\0' )
                    break;
                save_value += data_form_file[i];
            }
            temp.arrival_time = stoi(save_value);
            data_storage.push_back(temp);
        }
    }
}

void File_operation::generate_100_sets_of_100_elements()
{
    Process temp{};
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            temp.name = j+1;
            temp.arrival_time = rand() % 19 + 2;
            temp.service_time = rand() % 19 + 2;
            data_storage_two_measures[i][j] = temp;
        }
    }
}

void File_operation::draw_processes() const
{
    if (data_option == 1)
    {
        for (auto &i : data_storage)
        {
            std::cout << "Process: " << i.name << "\n";
            std::cout << "Service time: " << i.service_time << "\n";
            std::cout << "Arrival time: " << i.arrival_time << "\n";
            std::cout << "\n--------------------------------------\n";
        }
    }
    else if (data_option == 2)
    {
        for (int i = 0; i < data_storage_two_measures.size(); ++i)
        {
            for (int j = 0; j < data_storage_two_measures[i].size(); ++j)
            {
                std::cout << "Process: " << data_storage_two_measures[i][j].name << " in the first sample:" << i + 1
                          << "\n";
                std::cout << "Service time: " << data_storage_two_measures[i][j].service_time << "\n";
                std::cout << "Arrival time: " << data_storage_two_measures[i][j].arrival_time << "\n";
                std::cout << "\n--------------------------------------\n";
            }
        }
    }
}

std::vector<Process>& File_operation::get_data_storage()
{
    return data_storage;
}

std::vector<std::vector<Process>>& File_operation::get_data_storage_two_measures()
{
    return data_storage_two_measures;
}

void File_operation::write_to_file(std::vector<std::vector<float>> res)
{
    for (int i = 0; i < res.size(); ++i)
    {
        output_file << "Process: " << 1+i;
        output_file << "\nAverage waiting time: " << res[i][0];
        output_file << "\nAverage turnaround time: " << res[i][1] << "\n\n";
    }
}

File_operation::~File_operation()
{
    input_file.close();
    output_file.close();
    std::cout << "Files successfully closed!\n";
}



