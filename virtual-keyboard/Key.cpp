#include "Key.h"

Key::Key()= default;

Key::Key(std::string_view nameOfKey){
    this->m_nameOfKey = nameOfKey;
}

void Key::setNameOfKey(std::string_view NameOfKey){
    this->m_nameOfKey = NameOfKey;
}

std::string_view Key::getNameOfKey() {
    return this->m_nameOfKey;
}

void Key::setKeyCommand(std::string& keyCommand) {
    this->m_Command = keyCommand;
}

std::string Key::getKeyCommand() {
    return this->m_Command;
}

bool Key::isPressed(){
    return this->m_Press;
}

void Key::setPress(bool press) {
    this->m_Press = press;
}



