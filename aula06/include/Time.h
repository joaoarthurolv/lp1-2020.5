#ifndef TIME_H
#define TIME_H

#include <string>

struct Time{
    unsigned hour;
    unsigned minute;
    unsigned second;

    void set_from_string(const std::string& time);
};
#endif