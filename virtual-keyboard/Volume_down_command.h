#include "ICommand.h"

#ifndef VIRTUAL_KEYBOARD_VOLUME_DOWN_COMMAND_H
#define VIRTUAL_KEYBOARD_VOLUME_DOWN_COMMAND_H


class Volume_down_command : public ICommand {
    std::string execute(Key& key) override;
    std::string undo(Key& key) override;
};


#endif //VIRTUAL_KEYBOARD_VOLUME_DOWN_COMMAND_H
