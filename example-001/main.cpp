#include <fmt/format.h>
#include <ranges> // requires C++ 20 support!

auto main(int argc, char **argv) -> int
{
    fmt::println("Amount of parameters provided: {}",argc);
    for (auto i : std::views::iota(0, argc)) {
        fmt::println("argv[{}][{}\\0]",i,argv[i]);
    }
    return 0;
}
