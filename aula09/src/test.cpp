#include <iostream>
#include <sstream>

#include <string>

#include "../include/Message.h"
#include "../include/Diary.h"
#include "../include/Date.h"

int main(int argc, char* argv[])
{
    Message m;
    Date d;
    Time t; 
    
    d.set_from_string("25/06/2020");

    t.set_from_string("11:41:20");
    
    m.content = "aaa";
    m.date = d;
    m.time = t;

    std::cout << m.content << std::endl;

    std::cout << m.date.day << std::endl;
    std::cout << m.date.month << std::endl;
    std::cout << m.date.year << std::endl;

    std::cout << m.time.hour << std::endl;
    std::cout << m.time.minute << std::endl;
    std::cout << m.time.second << std::endl;

    return 0;
}