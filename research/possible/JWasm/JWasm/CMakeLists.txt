include_directories(h)
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
LIST(REMOVE_ITEM all_c_files ${CMAKE_CURRENT_SOURCE_DIR}/trmem.c)
add_executable(JWasm ${all_c_files})
