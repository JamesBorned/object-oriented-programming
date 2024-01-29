#include <string>
#include <utility>
#include "Key.h"

#ifndef VIRTUAL_KEYBOARD_COMMAND_H
#define VIRTUAL_KEYBOARD_COMMAND_H


class ICommand {
public:
    virtual std::string execute(Key& key) = 0;
    virtual std::string undo(Key& key) = 0;
};


#endif //VIRTUAL_KEYBOARD_COMMAND_H
