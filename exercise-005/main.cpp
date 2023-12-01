#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <chrono>
#include <thread>

#include "CLI/CLI.hpp"
#include "config.h"

typedef enum{
    db_state_open = 0,
    db_state_closed = 1,
    db_state_opening = 2,
    db_state_closing = 3,
    db_state_max
} GarageState_t;

GarageState_t state = db_state_closed;

void stateMachine(){
    int input;
    std::cin >> input;
    switch(state)
    {
        case db_state_open:
            if(1 == input)
            {
                state = db_state_closing;
            }
        break;

        case db_state_closed:
            if(1 == input)
            {
                state = db_state_opening;
            }
        break;

        case db_state_opening:
            if(1 == input)
            {
                state = db_state_closing;
            }
            else if(2 == input)
            {
                state = db_state_open;
            }
        break;

        case db_state_closing:
            if(1 == input)
            {
                state = db_state_opening;
            }
            else if(2 == input)
            {
                state = db_state_closed;
            }
        break;
    }
    std::cout << state << std::endl;
}

void sleep_ms(int millisekunden) {
    std::this_thread::sleep_for(std::chrono::milliseconds(millisekunden));
}

auto main(int argc, char **argv) -> int
{
    while( 1==1 )
    {
    stateMachine();
    sleep_ms(100);
    }
    return 0; /* exit gracefully*/
}
