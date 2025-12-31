include_directories(h)
include_directories(../h)
include_directories(coff/h)
include_directories(elf/h)
include_directories(omf/h)
include_directories(../watcom/h)
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
FILE(GLOB all_c_files c/*.c coff/c/*.c elf/c/*.c omf/c/*.c)
add_library(orl ${all_c_files})
