# include <string>
# include "friend.h"
Friend::Friend(std::string name)
{
    _first_name = name;
}
std::string Friend::get_name()
{
    return _first_name;
}
