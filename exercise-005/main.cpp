#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <chrono>
#include <thread>

void sleep_100_ms() {
    std::chrono::milliseconds duration(100);
    std::this_thread::sleep_for(duration);
};


int getInput(void)
{
    int number;
    std::cout << "Geben Sie eine Zahl ein: ";
    std::cin >> number;
    std::cout << number << std::endl;
    return number;
};

typedef enum {
    STATE_Up = 1,
    STATE_Down = 2,
    STATE_Off = 0,
} GarageState;

GarageState state = STATE_Off;

void stateMachine()
{
    int input = getInput();
    switch(state)
    {
        case STATE_Off:
            if(6 == input)
            {
                state = STATE_Up;
                std::cout << state << std::endl;
            }
            else if (5 == input)
            {
                state = STATE_Down;
                std::cout << state << std::endl;
            }
        break;
        case STATE_Up:
            if (4 == input)
            {
                state = STATE_Off;
                std::cout << state << std::endl;
            }
            else if (7 == input)
            {
                state = STATE_Down;
                std::cout << state << std::endl;
            }
        break;
        case STATE_Down:
            if (3 == input)
            {
                state = STATE_Off;
                std::cout << state << std::endl;
            }
            else if (7 == input)
            {
                state = STATE_Down;
                std::cout << state << std::endl;
            }
        break;
    }
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    while (true)
    {
        stateMachine();
        sleep_100_ms();
    }

    return 0; /* exit gracefully*/
}
