cmake_minimum_required(VERSION 3.10)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

# ---------------------------------
# Compiler flags
# ---------------------------------
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# ---------------------------------
# Mandatory library sources
# ---------------------------------
set(MANDATORY_SOURCES
        get_next_line.c
        get_next_line_utils.c
)

add_library(gnl ${MANDATORY_SOURCES})
target_include_directories(gnl PUBLIC ${CMAKE_SOURCE_DIR})

# ---------------------------------
# Bonus library sources
# ---------------------------------
set(BONUS_SOURCES
        get_next_line_bonus.c
        get_next_line_utils_bonus.c
)

add_library(gnl_bonus ${BONUS_SOURCES})
target_include_directories(gnl_bonus PUBLIC ${CMAKE_SOURCE_DIR})

# ---------------------------------
# Norminette check (optional)
# ---------------------------------
find_program(NORMINETTE_EXECUTABLE norminette)

if(NORMINETTE_EXECUTABLE)
    file(GLOB FT_FILES
            "${CMAKE_SOURCE_DIR}/get_*.c"
            "${CMAKE_SOURCE_DIR}/*.h"
    )
    if(FT_FILES)
        add_custom_command(TARGET gnl PRE_BUILD
                COMMAND ${NORMINETTE_EXECUTABLE} -R CheckForbiddenSourceHeader -R CheckDefine ${FT_FILES}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Running Norminette on project files..."
        )
    endif()
endif()

# ---------------------------------
# Mandatory executable
# ---------------------------------
add_executable(test_get_next_line test_get_next_line.c)
target_link_libraries(test_get_next_line PRIVATE gnl)
target_include_directories(test_get_next_line PRIVATE ${CMAKE_SOURCE_DIR})

# ---------------------------------
# Bonus executable
# ---------------------------------
add_executable(test_get_next_line_bonus test_get_next_line_bonus.c)
target_link_libraries(test_get_next_line_bonus PRIVATE gnl_bonus)
target_include_directories(test_get_next_line_bonus PRIVATE ${CMAKE_SOURCE_DIR})
