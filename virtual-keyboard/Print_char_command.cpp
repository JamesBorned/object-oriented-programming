#include <iostream>
#include "Print_char_command.h"
#include "Key.h"

std::string Print_char_command::execute(Key& key) {
    return std::string{key.getNameOfKey()};
}

std::string Print_char_command::undo(Key& key) {
    return "";
}