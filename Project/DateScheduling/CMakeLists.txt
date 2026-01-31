cmake_minimum_required(VERSION 3.16)

# 1. 統一專案名稱為 DateScheduling
project(DateScheduling LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_add_resources(MY_RESOURCES resources.qrc)
# 2. 這裡建立執行檔，名字必須是 DateScheduling
add_executable(DateScheduling
	WIN32
        ${MY_RESOURCES}
        logo.rc
        main.cpp

        CalendarWindow.cpp
        CalendarWindow.h

        ShiftData.cpp
        ShiftData.h

        EmployeeManager.cpp
        EmployeeManager.h

        ScheduleDelegate.cpp
        ScheduleDelegate.h

        DayEditorDialog.cpp
        DayEditorDialog.h
)

target_link_libraries(DateScheduling PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)