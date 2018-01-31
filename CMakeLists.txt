cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_TIME "Build time" OFF)


#------------------------------------------------------------
# ПОДКЛЮЧЕНИЕ ПАКЕТНОГО МЕНЕДЖЕРА HUNTER
#------------------------------------------------------------

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/SimonRussia/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "ef53eaa092c18d1ae26299daa4ea84d0f1d979ef"
)


#------------------------------------------------------------
# ИМЯ ПАКЕТА
#------------------------------------------------------------

project(sort)


#------------------------------------------------------------
# ПОИСК ПАКЕТОВ
#------------------------------------------------------------

find_package(codecov)

hunter_add_package(Catch)
find_package(Catch CONFIG REQUIRED)


#------------------------------------------------------------
# СОБИРАЕМЫЕ БИБЛИОТЕКИ И МОДУЛИ
#------------------------------------------------------------

add_library(sort INTERFACE)

target_include_directories(sort INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)


#------------------------------------------------------------
# СОБИРАЕМЫЕ ПРИМЕРЫ
#------------------------------------------------------------

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} sort)
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()


#------------------------------------------------------------
# СОБИРАЕМЫЕ ТЕСТЫ ПО ВРЕМЕНИ
#------------------------------------------------------------

if(BUILD_TIME)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/time/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} sort)
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()


#------------------------------------------------------------
# СОБИРАЕМЫЕ ТЕСТЫ
#------------------------------------------------------------

if(BUILD_TESTS)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} Catch::Catch)
  add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
  add_coverage(check)
endif()
