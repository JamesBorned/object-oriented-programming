
#include <string>
#include "ICommand.h"

#ifndef VIRTUAL_KEYBOARD_PRINT_CHAR_COMMAND_H
#define VIRTUAL_KEYBOARD_PRINT_CHAR_COMMAND_H


class Print_char_command : public ICommand{
        std::string execute(Key& key) override;
        std::string undo(Key& key) override;
};


#endif //VIRTUAL_KEYBOARD_PRINT_CHAR_COMMAND_H
