#include "utils/CsvFileHandler.hpp"
#include "utils/Timer.hpp"

#include <iostream>

void load_training_dataset(const std::string& training_dataset_path, std::vector<std::vector<std::string>>& training_data)
{
    std::cout << "Loading training dataset...";

    try
    {
        Timer timer;
        timer.start();

        training_data = CsvFileHandler::read_data(training_dataset_path);

        timer.stop();

        std::cout << " [DONE] [" << std::fixed << std::setprecision(4) << timer.elapsed_time() << " ms]" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << " [FAIL]" << std::endl;
        std::cerr << e.what() << std::endl;
    }
}

int main(const int argc, char const* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <training_dataset> <test_dataset> <output>" << std::endl;
    }

    const std::string training_dataset_path = argv[1];

    std::vector<std::vector<std::string>> training_data;

    load_training_dataset(training_dataset_path, training_data);

    return 0;
}
