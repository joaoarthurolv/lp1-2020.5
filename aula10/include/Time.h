#ifndef TIME_H
#define TIME_H

#include <string>
#include <ctime>

struct Time{
    Time();

    unsigned hour;
    unsigned minute;
    unsigned second;

    void set_from_string(const std::string& time);
    std::string to_string();
    std::string get_current_time();
    std::string format_current_date(const std::string &format);
};
#endif