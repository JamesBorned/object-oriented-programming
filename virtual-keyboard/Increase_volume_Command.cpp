#include "Increase_volume_Command.h"
#include <iostream>

std::string Increase_volume_Command::execute(Key& key) {
    return "Increase the volume by 10 percent";
}

std::string Increase_volume_Command::undo(Key& key) {
    return "Turn down the volume by 10 percent";
}