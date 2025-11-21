#file(GLOB SOURCE_FILES_1 "dr/c/*.c")
file(GLOB SOURCE_FILES_2 "dw/c/*.c")
#file(GLOB SOURCE_FILES_3 "util/c/*.c")
add_library(dwarf STATIC ${SOURCE_FILES_2})
target_include_directories(dwarf PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/dr/h
    ${CMAKE_CURRENT_SOURCE_DIR}/dw/h
    ${CMAKE_CURRENT_SOURCE_DIR}/dw/nt386
    ${CMAKE_CURRENT_SOURCE_DIR}/util/h
    ${CMAKE_CURRENT_SOURCE_DIR}/../watcom/h
)
target_compile_definitions(dwarf PUBLIC " _CRT_SECURE_NO_WARNINGS")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET dwarf PROPERTY C_STANDARD 99)
  set_property(TARGET dwarf PROPERTY C_STANDARD_REQUIRED ON)
endif()
if (MSVC)
    string(APPEND CMAKE_C_FLAGS_DEBUG " /MTd")
    string(APPEND CMAKE_C_FLAGS_RELEASE " /MT")
endif()
