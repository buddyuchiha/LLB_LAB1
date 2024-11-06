cmake_minimum_required(VERSION 3.11)

project(sets CXX)

set(CMAKE_CXX_STANDARD 23)

# —пецифичные настройки дл€ компил€тора Visual Studio
if(MSVC)
    # √енерируем статическую заглушку дл€ динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # ¬ключаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# ќбъ€вл€ем тесты
add_executable(shaker_sort "part1.cpp")
add_executable(easy_shaker_sort "part2.cpp")