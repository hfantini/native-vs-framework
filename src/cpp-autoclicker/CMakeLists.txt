cmake_minimum_required(VERSION 3.22)

project(cpp_autoclicker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(GUI_TYPE WIN32)

add_executable(cpp_autoclicker WIN32 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp "src/view/view.h" "src/view/view.cpp" "src/view/wndMain.h" "src/view/wndMain.cpp" "src/helpers/Win32Helpers.h" "src/helpers/Win32Helpers.cpp" "src/controler/AutoClickController.h" "src/controler/AutoClickController.cpp" "src/structs/AutoClickControllerConfig.h")
