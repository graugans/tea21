#include <string>
#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "bmp.h"


auto main(int argc, char **argv) -> int
{
    std::string filename{DEFAULT_BMP_FILE};
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-f,--file",
            filename, 
            fmt::format("The filename for the Bitmap, default: {}", filename));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::println("Hello, {}!", app.get_name());
    fmt::println("The filename to use: {}",filename);

    BMP bmp;
    bmp.read(filename);

    return 0; /* exit gracefully*/
}
