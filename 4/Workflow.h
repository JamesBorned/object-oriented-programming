#pragma once

#include "Keyboard.h"

class Workflow
{
public:
    explicit Workflow(Keyboard& keyboard) : keyboard(keyboard) {}

    // ��������� ������ � ������� ������� ������� � ������ � ��������� �������� �������� (workflow)
    void keypress(const std::string& key);

    void undo();

    // ��������� ��� �������� � ������� �������� (workflow)
    void perform();

    // ��������� �������� � ������� ������� (workflow)
    void addAction(const Action& action);

private:
    Keyboard& keyboard;
    std::vector<Action> actions; // ������ �������� ��� ���������� � ������� �������� (workflow)
};