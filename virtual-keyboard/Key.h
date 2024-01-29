#include <string>

#ifndef VIRTUAL_KEYBOARD_KEY_H
#define VIRTUAL_KEYBOARD_KEY_H

class Key {
public:
    Key();
    explicit Key(std::string_view nameOfKey);

    void setNameOfKey(std::string_view NameOfKey);
    std::string_view getNameOfKey();

    void setKeyCommand(std::string& keyCommand);
    std::string getKeyCommand();

    bool isPressed();

    void setPress(bool press);

private:
    std::string_view m_nameOfKey;
    std::string m_Command;
    bool m_Press = false;
};


#endif //VIRTUAL_KEYBOARD_KEY_H
