#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>
#include <sstream>

struct Date {

    Date();
    unsigned year;
    unsigned month;
    unsigned day;

    void set_from_string(const std::string& date);
    std::string to_string();
    std::string get_current_date();
    std::string format_current_date(const std::string &format);

};
#endif