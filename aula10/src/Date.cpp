#include "../include/Date.h"

#include <sstream>

Date::Date(): year(0), month(0), day(0)
{
    
}

std::string Date::to_string(){
    std::stringstream stream;

    if (day < 10) {
        stream << '0';
    }

    stream << day;
    stream << '/';

    if (month < 10) {
        stream << '0';
    }

    stream << month;
    stream << '/';

    stream << year;

    return stream.str();
}

void Date::set_from_string(const std::string& date){
    std::stringstream stream(date);
    char discard;

    stream >> day;
    stream >> discard;
    stream >> month;
    stream >> discard;
    stream >> year;
    stream >> discard;
}

std::string Date::format_current_date(const std::string &format) {
    std::time_t time = std::time(nullptr);
    char result[1024];

    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

    return std::string(result);
}

std::string Date::get_current_date() 
{
    return format_current_date("%d/%m/%Y");
}