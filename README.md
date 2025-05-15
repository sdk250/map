# Map for Cache Affinity

The ordered container implemented based on std::vector.

Note: Use it when the elements is less than 100.

# Usage

```c++
#include "map.hpp"

int main(void)
{
    // sdk250::Map<Key, Value> { /* Compare function */ };
    // map[Key] = Value;
    auto map = sdk250::Map<uint32_t, std::string> (std::less<uint32_t>());
    map[0] = "Apple";
    map[1] = "Orange";

    return 0;
}

```
