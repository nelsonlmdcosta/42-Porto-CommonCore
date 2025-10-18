cmake_minimum_required(VERSION 3.10)
project(ft_printf C)

# -------------------------------
# C standard and compiler flags
# -------------------------------
set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# -------------------------------
# ft_printf sources
# -------------------------------
file(GLOB_RECURSE FT_PRINTF_SRC
        "${CMAKE_SOURCE_DIR}/ft_*.c"
)

# -------------------------------
# libft sources
# -------------------------------
file(GLOB_RECURSE LIBFT_SRC
        "${CMAKE_SOURCE_DIR}/libft/*.c"
)

# -------------------------------
# Build static library ftprintf
# -------------------------------
add_library(ftprintf STATIC ${FT_PRINTF_SRC} ${LIBFT_SRC})

# Include directories
target_include_directories(ftprintf PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/libft
)

# -------------------------------
# Norminette check (only ft_*.c and .h)
# -------------------------------
find_program(NORMINETTE_EXECUTABLE norminette)
if(NORMINETTE_EXECUTABLE)
    file(GLOB_RECURSE FT_FILES
            "${CMAKE_SOURCE_DIR}/ft_*.c"
            "${CMAKE_SOURCE_DIR}/*.h"
    )

    # Exclude libft and build directories
    list(FILTER FT_FILES EXCLUDE REGEX ".*/libft/.*")
    list(FILTER FT_FILES EXCLUDE REGEX ".*/cmake-build-.*")

    if(FT_FILES)
        add_custom_command(TARGET ftprintf PRE_BUILD
                COMMAND ${NORMINETTE_EXECUTABLE} -R CheckForbiddenSourceHeader -R CheckDefine ${FT_FILES}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Running Norminette on ft_*.c and headers..."
        )
    endif()
endif()

# -------------------------------
# Executables for test_*.c files
# -------------------------------
file(GLOB TEST_FILES
        "${CMAKE_SOURCE_DIR}/test_*.c"
)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE ftprintf)
    target_include_directories(${TEST_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/libft
    )
endforeach()

# -------------------------------
# Optional: main demo executable
# -------------------------------
# Uncomment if you have a main.c or demo.c
# add_executable(ft_demo main.c)
# target_link_libraries(ft_demo PRIVATE ftprintf)
# target_include_directories(ft_demo PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/libft)
