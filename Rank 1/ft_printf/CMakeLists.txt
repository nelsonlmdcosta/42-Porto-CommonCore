cmake_minimum_required(VERSION 3.10)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# -------------------------------
# Collect all sources recursively
# -------------------------------
file(GLOB_RECURSE ALL_C_SOURCES "${CMAKE_SOURCE_DIR}/*.c")

# Build static library
add_library(ftprintf STATIC ${ALL_C_SOURCES})

# Include all necessary directories
target_include_directories(ftprintf PUBLIC
        ${CMAKE_SOURCE_DIR}        # root headers
        ${CMAKE_SOURCE_DIR}/libft  # libft headers
        ${CMAKE_SOURCE_DIR}/helpers # helpers headers
)

# -------------------------------
# Norminette
# -------------------------------
find_program(NORMINETTE_EXECUTABLE norminette)
if(NORMINETTE_EXECUTABLE)
    file(GLOB_RECURSE ALL_HEADERS "${CMAKE_SOURCE_DIR}/*.h")
    list(FILTER ALL_HEADERS EXCLUDE REGEX ".*/cmake-build-.*")
    add_custom_target(norminette
            COMMAND ${NORMINETTE_EXECUTABLE} -R CheckForbiddenSourceHeader -R CheckDefine ${ALL_C_SOURCES} ${ALL_HEADERS}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running Norminette on all sources and headers..."
    )
endif()

# -------------------------------
# Build an executable for each test_*.c main
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
endforeach()
