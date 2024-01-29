#include "ICommand.h"

#ifndef VIRTUAL_KEYBOARD_INCREASE_VOLUME_COMMAND_H
#define VIRTUAL_KEYBOARD_INCREASE_VOLUME_COMMAND_H


class Increase_volume_Command : public ICommand{
public:
    std::string execute(Key& key) override;
    std::string undo(Key& key) override;
};

#endif //VIRTUAL_KEYBOARD_INCREASE_VOLUME_COMMAND_H
