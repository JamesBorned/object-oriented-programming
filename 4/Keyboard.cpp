#include "Keyboard.h"

// ���������� ����� "pressKey", ������� ��������� ������ "key" � �������� ���������.
//  ������ ������ �� ���������, ���������������� �� ������� "key" � ������� "keymap" � ������� ������� "count".
//  ���� ������� �� �������, ������������ ���������� � ������� "Unknown key pressed".
//  ����� ��� ������� ����������� � ����� ������� "history".
//  � ����� ���������� �������-��������, ��������� � ���� ��������.
void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "Unknown key pressed");
    history.push_back(key);
    keymap[key].first();
}

//���������� ����� "undo". ���� ������� �� �����, ��������� �������� ����������� �� ������� "history".
//  ����� "Undo action for key: ..." 
// ��������� � �������, � ����� ���������� �������-��������, 
//��������� � ���� ��������. ����� ����� ������� ��������� �� ������� "history".
void Keyboard::undo()
{
    if (!history.empty())
    {
        std::cout << "Undo action for key: " << history.back() << "\n";
        keymap[history.back()].second();
        history.pop_back();
    }
}

// ���������� ����� "isKeyRegistered", ������� ��������� ������ "key" � �������� ���������.
//  ����� ���������� �������� true, ���� ������� "key" ���� � ������� "keymap", � false � ��������� ������.
//  ������� "count" ���������� ���������� ��������� � �������� ������, 
// ������� ���� ��������� ������� ������ 0, ������, ������� ����������������.
bool Keyboard::isKeyRegistered(const std::string& key) const
{
    return keymap.count(key) > 0;
}