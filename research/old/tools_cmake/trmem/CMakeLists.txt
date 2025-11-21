add_library(trmem STATIC "trmem.c" )
target_compile_definitions(trmem PUBLIC " _CRT_SECURE_NO_WARNINGS")
target_include_directories(trmem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../watcom/h
    ${CMAKE_CURRENT_SOURCE_DIR}/../rel/h
)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET trmem PROPERTY C_STANDARD 99)
  set_property(TARGET trmem PROPERTY C_STANDARD_REQUIRED ON)
endif()
if (MSVC)
    string(APPEND CMAKE_C_FLAGS_DEBUG " /MTd")
    string(APPEND CMAKE_C_FLAGS_RELEASE " /MT")
endif()
