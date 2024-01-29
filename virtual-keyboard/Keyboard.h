#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include "Key.h"

#ifndef VIRTUAL_KEYBOARD_KEYBOARD_H
#define VIRTUAL_KEYBOARD_KEYBOARD_H

class Keyboard {
    public:
        Keyboard() = default;

        void setKeys(std::list<Key>& Keys);
        std::vector<std::string> getKeys();

        //void setPressedKeys(std::list<Key>& Keys);
        //std::list<Key> getPressedKeys();

        //void PressKeys(Key Key);
        void AddKey(Key& Key);

    private:
        std::vector<std::string> m_Keys;
        //std::list <Key> m_PressedKeys;
};

#endif //VIRTUAL_KEYBOARD_KEYBOARD_H
