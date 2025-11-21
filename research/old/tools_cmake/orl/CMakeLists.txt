file(GLOB SOURCE_FILES_1 "c/*.c")
file(GLOB SOURCE_FILES_2 "coff/c/*.c")
file(GLOB SOURCE_FILES_3 "elf/c/*.c")
file(GLOB SOURCE_FILES_4 "omf/c/*.c")
add_library(orl STATIC  ${SOURCE_FILES_1} ${SOURCE_FILES_2} ${SOURCE_FILES_3} ${SOURCE_FILES_4})
target_include_directories(orl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/h
    ${CMAKE_CURRENT_SOURCE_DIR}/coff/h
    ${CMAKE_CURRENT_SOURCE_DIR}/elf/h
    ${CMAKE_CURRENT_SOURCE_DIR}/omf/h
    ${CMAKE_CURRENT_SOURCE_DIR}/../watcom/h
)
target_compile_definitions(orl PUBLIC " _CRT_SECURE_NO_WARNINGS")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET orl PROPERTY C_STANDARD 99)
  set_property(TARGET orl PROPERTY C_STANDARD_REQUIRED ON)
endif()
if (MSVC)
    string(APPEND CMAKE_C_FLAGS_DEBUG " /MTd")
    string(APPEND CMAKE_C_FLAGS_RELEASE " /MT")
endif()
