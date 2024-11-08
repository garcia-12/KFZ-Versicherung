cmake_minimum_required(VERSION 3.5)

project(KFZ-Versicherung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KFZ-Versicherung main.cpp
    Versicherer.h Versicherer.cpp
    KFZSchein.h KFZSchein.cpp
    LVSchein.h LVSchein.cpp
    VSchein.h VSchein.cpp)

include(GNUInstallDirs)
install(TARGETS KFZ-Versicherung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
