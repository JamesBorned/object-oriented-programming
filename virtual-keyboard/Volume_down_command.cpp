#include <iostream>
#include "Volume_down_command.h"

std::string Volume_down_command::execute(Key& key) {
    return "Turn down the volume by 10 percent";
}

std::string Volume_down_command::undo(Key& key) {
     return "Increase the volume by 10 percent";
}
