
set(TARGET_NAME test_filesystem)

set(SRCS
    test_filesystem.cpp
    )

add_executable(${TARGET_NAME}
    ${SRCS}
    )


target_link_libraries(${TARGET_NAME}
    libc++experimental.a
    )


add_test (${TARGET_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME})