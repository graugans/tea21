#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    std::srand(std::time(nullptr));
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     * Test commit and push No.2
     */
    CLI::App app{PROJECT_NAME};
    auto count = 20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, fmt::format("Die Variable count: {}", count));          
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);
    fmt::print("Created a vector with {} elements\n", data.size());

    for(int i = 0; i< count; i++)
    {
        data[i] = rand()%100;
    }

    std::cout << "Vector data: \n";
    for (int q = 0; q < count; q++) {
        std::cout << "Nr. " << q+1 << ":\t" << data[q] << " " << "\n";
    }
    
    std::sort(data.begin(),data.end());
    fmt::print("sortierte Zahlen:\n");
    for (int q = 0; q < count; q++) {
        std::cout << "Nr. " << q+1 << ":\t" << data[q] << " " << "\n";
    }
    printf("Die Variable count: %d \n",count);

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
