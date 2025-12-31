include_directories(h)
include_directories(jarvis/h)
include_directories(dwarf/h)
include_directories(../orl/coff/h)
include_directories(../orl/elf/h)
include_directories(../orl/omf/h)
include_directories(lib_misc/h)
include_directories(dwarf/h)
include_directories(rc/rc/h)
include_directories(rc/wres/h)
set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()
add_definitions(-D__NT__ -DNDEBUG -DDEBUG_OUT -D_CRT_SECURE_NO_WARNINGS)
FILE(GLOB all_c_files c/*.c)
add_executable(JWlink ${all_c_files})
target_link_libraries(JWlink PRIVATE dwarf)
target_link_libraries(JWlink PRIVATE lib_misc)
target_link_libraries(JWlink PRIVATE orl)
target_link_libraries(JWlink PRIVATE sdk)
