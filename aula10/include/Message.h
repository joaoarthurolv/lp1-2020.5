#ifndef MESSAGE_H
#define MESSAGE_H

#include "Date.h"
#include "Time.h"

#include <string>

struct Message {
    std::string content;
    Date date;
    Time time;
    bool alreadyOnFile;
};
#endif