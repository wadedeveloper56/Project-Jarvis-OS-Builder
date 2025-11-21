# CMakeList.txt : CMake project for yacc, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable(yacc
    c/bitsets.c
    c/buildpro.c
    c/default.c
    c/defshift.c
    c/dont_opt.c
    c/elimunit.c
    c/fpopen.c
    c/genfast.c
    c/gensupp.c
    c/gentable.c
    c/getname.c
    c/lalr1.c
    c/lr0.c
    c/parse.c
    c/sentence.c
    c/used.c
    c/writeobj.c
    c/yacc.c
)
target_include_directories(yacc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/h
    ${CMAKE_CURRENT_SOURCE_DIR}/../watcom/h
)
target_compile_definitions(yacc PUBLIC " _CRT_SECURE_NO_WARNINGS")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET yacc PROPERTY C_STANDARD 99)
  set_property(TARGET yacc PROPERTY C_STANDARD_REQUIRED ON)
endif()
if (MSVC)
    string(APPEND CMAKE_C_FLAGS_DEBUG " /MTd")
    string(APPEND CMAKE_C_FLAGS_RELEASE " /MT")
endif()
# TODO: Add tests and install targets if needed.
