
function( AddTestWithSameCppFile test_name)
    set(TARGET_NAME ${test_name})
    set(SRCS ${TARGET_NAME}.cpp )
    add_executable(${TARGET_NAME} ${SRCS} )
    target_link_libraries(${TARGET_NAME} libc++experimental.a )
    add_test (${TARGET_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME})
endfunction(AddTestWithSammeCppFile)

AddTestWithSameCppFile(test_filesystem)
AddTestWithSameCppFile(test_filesystem_loop_each_dir_item)
AddTestWithSameCppFile(test_filesystem_to_string)

