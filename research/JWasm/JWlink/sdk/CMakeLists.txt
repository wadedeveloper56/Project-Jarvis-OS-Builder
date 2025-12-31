include_directories(rc/wres/h)
include_directories(rc/rc/h)
include_directories(../h)
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
add_definitions(-D__NT__ -DNDEBUG -DDEBUG_OUT -D_CRT_SECURE_NO_WARNINGS -DINSIDE_WLINK)
FILE(GLOB all_c_files rc/wres/c/*.c rc/rc/c/*.c)
add_library(sdk ${all_c_files})
