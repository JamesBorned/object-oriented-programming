cmake_minimum_required(VERSION 3.21)
project(virtual_keyboard)

set(CMAKE_CXX_STANDARD 20)

add_executable(virtual_keyboard main.cpp Keyboard.cpp Keyboard.h Workflow.cpp Workflow.h ICommand.h Key.cpp Key.h Increase_volume_Command.cpp Increase_volume_Command.h Volume_down_command.cpp Volume_down_command.h Print_char_command.cpp Print_char_command.h)
