cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr)
project(kinematics)

target_sources(app PRIVATE src/main.c)
