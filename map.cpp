#include <iostream>
#include "map.h"

int main(int argc, char const *argv[])
{
    Map<int> map;
    map.add(7);
    map.add(5);
    map.add(10);
    map.add(12);
    map.add(6);
    map.add(20);
    map.add(15);
    map.add(1);

    Map<int> map2(map);

    map.add(26);

    map2.print();
    std::cout << std::endl << "Map1" << std::endl;
    map.print();

    return 0;
}
