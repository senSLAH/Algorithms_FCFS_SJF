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
    output_tested_data_file.open("../Tested_data.txt");
    if (!output_tested_data_file.is_open())
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    output_results_data_file.open("../Results.txt");
    if (!output_results_data_file.is_open())
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    std::cout << "File input file opened successfully!";
    std::cout << "File output file opened successfully!";

//    Rezerwujemy mejsce na stu różnych ciągów ze 100 procesami
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

    //jeżeli rozmiar jest równy 10 000, to znaczy że chcę zbadacz
    //algorytm na na stu różnych ciągach(każdy z ciągów zawiera 100 procesów).
    //w takiem razie potzebujemy dwuwymiarowego wektora
    if (data_storage.size() == 10000)
    {
        int element = 0;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                data_storage_two_measures[i][j] = data_storage[element];
                ++element;
            }
        }
        data_option = 2;//przypisujemy wartość dwa, bo będziemy stosować dwuwymiarowy vector
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
                std::cout << "Process: " << data_storage_two_measures[i][j].name << " in the set: " << i + 1
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

void File_operation::write_results_to_file(std::vector<std::vector<float>> res)
{
    for (int i = 0; i < res.size(); ++i)
    {
        output_results_data_file << "Set: " << 1 + i;
        output_results_data_file << "\nAverage waiting time: " << res[i][0];
        output_results_data_file << "\nAverage turnaround time: " << res[i][1] << "\n\n";
    }
}

void File_operation::write_tested_data_to_file()
{
    if (data_option == 1)
    {
        for (auto &i : data_storage)
        {
            output_tested_data_file << "P: " << i.name << "\n";
            output_tested_data_file << "Service time: " << i.service_time << "\n";
            output_tested_data_file << "Arrival time: " << i.arrival_time << "\n";
            output_tested_data_file << "\n--------------------------------------\n";
        }
    }
    else if (data_option == 2)
    {
        for (int i = 0; i < data_storage_two_measures.size(); ++i)
        {
            for (int j = 0; j < data_storage_two_measures[i].size(); ++j)
            {
                output_tested_data_file << "P" << j+1 << ": s=" << data_storage_two_measures[i][j].service_time
                << " a=" << data_storage_two_measures[i][j].arrival_time << "\n";
            }
        }
    }
}

int File_operation::get_data_option()
{
    return data_option;
}


File_operation::~File_operation()
{
    input_file.close();
    output_results_data_file.close();
    output_tested_data_file.close();
    std::cout << "Files successfully closed!\n";
}






