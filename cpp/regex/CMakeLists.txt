
set(TARGET_NAME test_regex)

add_executable (${TARGET_NAME}
    test_regex.cpp
    )


target_link_libraries(${TARGET_NAME}
    libc++experimental.a
    )

set_target_properties(${TARGET_NAME} PROPERTIES
            CXX_STANDARD_REQUIRED 17
            CXX_EXTENSIONS OFF
    )

add_test (test_filesystem ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME} )