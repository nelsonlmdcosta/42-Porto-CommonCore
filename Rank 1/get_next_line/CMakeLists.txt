cmake_minimum_required(VERSION 3.10)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

# ---------------------------------
# Compiler flags
# ---------------------------------
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# ---------------------------------
# Core library sources
# ---------------------------------
file(GLOB SRC_FILES
        "${CMAKE_SOURCE_DIR}/*.c"
)

# Exclude all test_*.c files from the library
list(FILTER SRC_FILES EXCLUDE REGEX ".*/test_.*\\.c$")

# Create the library (static by default)
add_library(libft ${SRC_FILES})

# Optional: set include directories (if you have headers in root)
target_include_directories(libft PUBLIC ${CMAKE_SOURCE_DIR})

# ---------------------------------
# Norminette check
# ---------------------------------
find_program(NORMINETTE_EXECUTABLE norminette)

if(NORMINETTE_EXECUTABLE)
    file(GLOB FT_FILES
            "${CMAKE_SOURCE_DIR}/ft_*.c"
            "${CMAKE_SOURCE_DIR}/*.h"
    )
    if(FT_FILES)
        add_custom_command(TARGET libft PRE_BUILD
                COMMAND ${NORMINETTE_EXECUTABLE} -R CheckForbiddenSourceHeader -R CheckDefine ${FT_FILES}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Running Norminette on project files..."
        )
    endif()
endif()

# ---------------------------------
# Create separate executables for each test_*.c file
# ---------------------------------
file(GLOB TEST_FILES
        "${CMAKE_SOURCE_DIR}/test_*.c"
)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE libft)
    target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
endforeach()
