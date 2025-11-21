file(GLOB SOURCE_FILES "c/*.c")
add_library(lib_misc STATIC ${SOURCE_FILES})
target_include_directories(lib_misc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/h
    ${CMAKE_CURRENT_SOURCE_DIR}/../watcom/h
)
target_compile_definitions(lib_misc PUBLIC " _CRT_SECURE_NO_WARNINGS")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lib_misc PROPERTY C_STANDARD 99)
  set_property(TARGET lib_misc PROPERTY C_STANDARD_REQUIRED ON)
endif()
if (MSVC)
    string(APPEND CMAKE_C_FLAGS_DEBUG " /MTd")
    string(APPEND CMAKE_C_FLAGS_RELEASE " /MT")
endif()