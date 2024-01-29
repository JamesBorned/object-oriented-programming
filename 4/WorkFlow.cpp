#include "Workflow.h"// �������� ���� "Workflow.h"

// ���������� ������� "keypress", ������� ��������� ������ "key" � �������� ���������. 
// ������ ������� ���������� ����� "pressKey" ������� "keyboard"
// ����� ������ �������. ����� ����������� �������� � 1 ������� � �������������� ������� "sleep_for" �� ���������� "chrono".
void Workflow::keypress(const std::string& key)
{
    keyboard.pressKey(key);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // ��������� ��������, ����� �������� ���� �������
}

//���������� ������� "undo", ������� �� ��������� ���������.
// ������ ������� ���������� ����� "undo" ������� "keyboard", 
// ����� �������� ���������� �������� ������� �������. 
// ����� ����������� �������� � 1 �������.
void Workflow::undo()
{
    keyboard.undo();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// ���������� ������� "perform", ������� ��������� ��� �������� � ������� �������� 
//  ������ ����� ������������ ��� �������� ������� "actions"
//  � ����������� ������ �������-��������. ����� ����������� �������� � 1 �������.
void Workflow::perform()
{
    for (const auto& action : actions)
    {
        action();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// ���������� ������� "addAction",
//  ������� ��������� �������� "action" ���� Action 
//  ������ ������� ��������� "action" � ����� ������� "actions".
void Workflow::addAction(const Action& action)
{
    actions.push_back(action);
}