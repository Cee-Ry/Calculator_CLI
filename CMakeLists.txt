cmake_minimum_required(VERSION 3.10) 
project(Calculator_CLI)

add_executable(calc
    main.cpp
)

install(TARGETS calc
    DESTINATION $ENV{HOME}/.local/bin
)
