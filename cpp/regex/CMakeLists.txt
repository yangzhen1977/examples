
add_executable (test_regex
    test_regex_main.cpp
    )


target_link_libraries(test_regex
    libc++experimental.a
    )

set_target_properties(test_regex PROPERTIES
            CXX_STANDARD_REQUIRED 17
            CXX_EXTENSIONS OFF
    )
