
set(TARGET_NAME test_class)

add_executable (${TARGET_NAME}
    test_class.cpp
    )


target_link_libraries(${TARGET_NAME}
    libc++experimental.a
    )

add_test (${TARGET_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME} )