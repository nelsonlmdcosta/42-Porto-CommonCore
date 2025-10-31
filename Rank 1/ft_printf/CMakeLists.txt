cmake_minimum_required(VERSION 3.10)
project(ft_printf C)

# -------------------------------
# Compiler settings
# -------------------------------
set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# -------------------------------
# Collect all sources recursively (exclude test_*.c)
# -------------------------------
file(GLOB_RECURSE ALL_C_SOURCES "${CMAKE_SOURCE_DIR}/*.c")
list(FILTER ALL_C_SOURCES EXCLUDE REGEX ".*/test_.*\\.c$")

# Build static library
add_library(ftprintf STATIC ${ALL_C_SOURCES})

target_include_directories(ftprintf PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/libft
        ${CMAKE_SOURCE_DIR}/helpers
)

# -------------------------------
# Norminette setup
# -------------------------------
find_program(NORMINETTE_EXECUTABLE norminette)
if(NORMINETTE_EXECUTABLE)
    message(STATUS "Norminette found: ${NORMINETTE_EXECUTABLE}")

    # Collect sources & headers relative to source dir
    file(GLOB_RECURSE NORM_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/*.c")
    file(GLOB_RECURSE NORM_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/*.h")

    # Exclude build directories (any folder containing "cmake-") and test mains
    list(FILTER NORM_SOURCES EXCLUDE REGEX "^(cmake-.*|.*/cmake-.*|test_.*\\.c$)")
    list(FILTER NORM_HEADERS EXCLUDE REGEX "^(cmake-.*|.*/cmake-.*)")

    # Dummy target for Norminette
    add_custom_target(norminette_dummy
            COMMENT "Running Norminette on all sources and headers..."
    )

    # Attach Norminette command as POST_BUILD
    add_custom_command(TARGET norminette_dummy POST_BUILD
            COMMAND ${NORMINETTE_EXECUTABLE} -R CheckForbiddenSourceHeader -R CheckDefine
            ${NORM_SOURCES} ${NORM_HEADERS}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )

    # Make library depend on Norminette
    add_dependencies(ftprintf norminette_dummy)
endif()

# -------------------------------
# Build executables for each test_*.c
# -------------------------------
file(GLOB TEST_MAINS "${CMAKE_SOURCE_DIR}/test_*.c")
foreach(MAIN_SRC ${TEST_MAINS})
    get_filename_component(MAIN_NAME ${MAIN_SRC} NAME_WE)
    add_executable(${MAIN_NAME} ${MAIN_SRC})
    target_link_libraries(${MAIN_NAME} PRIVATE ftprintf)
    target_include_directories(${MAIN_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/libft
            ${CMAKE_SOURCE_DIR}/helpers
    )

    # Make test executables depend on Norminette
    if(NORMINETTE_EXECUTABLE)
        add_dependencies(${MAIN_NAME} norminette_dummy)
    endif()
endforeach()

