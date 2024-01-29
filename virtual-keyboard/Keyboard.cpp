#include "Keyboard.h"

void Keyboard::AddKey(Key& key) {
    this->getKeys().push_back(key.getNameOfKey());
}

void Keyboard::setKeys (std::list<std::string>& Keys) {
    this->m_Keys = Keys;
}

std::vector<std::string> Keyboard::getKeys() {
    return this->m_Keys;
}

/*void Keyboard::PressKeys (Key Key){
    this->getPressedKeys().push_back(Key);
    std::cout << Key.getKeyCommand().getNameOfCommand();
}*/

/*void Keyboard::Undo(){
    if(!this->getPressedKeys().empty()) {
        this->getPressedKeys().back().getKeyCommand().undo();
        this->getPressedKeys().pop_back();
        if(!this->getPressedKeys().empty()) {
            std::cout << "The last operation is " << this->getPressedKeys().back().getKeyCommand().execute();
        }
    }
}*/

/*void Keyboard::setPressedKeys(std::list<Key> &Keys) {

}

std::list<Key> Keyboard::getPressedKeys() {
    return std::list<Key>();
}*/


