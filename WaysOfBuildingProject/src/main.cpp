#include <iostream>
#include <string>
#include "merge_names.h"
#include "friend.h"
int main()
{
    std::string name;
    std::getline(std::cin, name);
    Friend myFriend(name);
    std::cout << mergeNames(myFriend.get_name(), "Garcia")<<std::endl;
    std::getchar();
    return 0;
}


