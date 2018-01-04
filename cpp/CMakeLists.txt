# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)



execute_process(COMMAND brew --prefix llvm  OUTPUT_VARIABLE LLVM_HOME)
string(STRIP ${LLVM_HOME} LLVM_HOME)

SET(CMAKE_C_COMPILER ${LLVM_HOME}/bin/clang)
SET(CMAKE_CXX_COMPILER ${LLVM_HOME}/bin/clang++)


project (examples)

SET(LLVM_CPPFLAGS "-I${LLVM_HOME}/include")
SET(LLVM_LDFLAGS  "-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib")

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${LLVM_CPPFLAGS} -std=c++1z" )
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LLVM_LDFLAGS}" )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


enable_testing ()
add_subdirectory (regex)
add_subdirectory (filesystem)
add_subdirectory (json)
add_subdirectory (type)
add_subdirectory (class)





