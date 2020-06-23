#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {
    unsigned year;
    unsigned month;
    unsigned day;

    void set_from_string(const std::string& date);
};
#endif