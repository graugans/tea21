#include <fmt/format.h>
#include <vector>

auto main(int argc, char** argv) -> int
{
    char data[] = "None terminated string!!";
    std::vector<int> vec(100);
    int* pInt;
    fmt::println("The size of data[] {}",sizeof(data));
    fmt::println("The size of argv[0] {}",sizeof(argv[0]));
    fmt::println("The strlen of argv[0] {}",strlen(argv[0]));
    fmt::println("The sizeof(vec): {}",sizeof(vec));
    fmt::println("The vec.size(): {}",vec.size());
    fmt::println("The sizeof(pInt): {}",sizeof(pInt));
    return 0;
}
