include(jsoncpp.cmake)

set(TARGET_NAME test_json)

add_executable (${TARGET_NAME}
    test_json.cpp
    )


set(JSONCPP_WITH_CMAKE_PACKAGE ON)
set(CMAKE_INSTALL_LIBDIR lib)
target_link_libraries(${TARGET_NAME}
    libc++experimental.a
    jsoncpp
    )

#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

add_test (${TARGET_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME} )