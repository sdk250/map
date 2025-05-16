#include <iostream>
#include <cstdint>
#include <string>

#include "map.hpp"

#define DECL(X) map[X] = #X;

int main(void)
{
    // sdk250::Map<Key, Value> { /* Compare function */ };
    // map[Key] = Value;
    auto map = sdk250::Map<uint32_t, std::string> (std::less<uint32_t>());
    map[0] = "Apple";
    DECL(4)
    DECL(2)
    DECL(5)
    DECL(3)
    map[1] = "Orange";

    for (uint32_t i = 0; i < 6; i++)
        std::cout << map[i] << std::endl;

    return 0;
}

