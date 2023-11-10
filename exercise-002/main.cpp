#include <fmt/chrono.h>
#include <fmt/format.h>
# include <vector>
#include "CLI/CLI.hpp"
#include "config.h"


auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    int count = 20;
    try
    {

        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Variable count als Integer");
        app.parse(argc, argv);

    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);
    fmt::print("Created a vector with {} elements\n", data.size());
    

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", count, app.get_name());

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < count; i++)
    {
        data[i] = rand()%100 + 1;
        fmt::print("{} ", data[i]);
    }
    fmt::print("\n");

    auto start = std::chrono::system_clock::now();

    std::sort(data.begin(),data.end());
    
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    /*
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    */
    for (int i = 0; i < count; i++)
    {
        fmt::print("{} ", data[i]);
    }
    /* INSERT YOUR CODE HERE */

    fmt::print("\n Elapsed Time for sorting: {}", elapsed);
    
    return 0; 
    
    /* exit gracefully*/
}
