#ifndef FRIEND_H
#define FRIEND_H

#include <string>

class Friend
{
    private:
        std::string _first_name; 
    public:
        Friend(std::string name);
        //~Friend();
        std:: string get_name();
};

#endif