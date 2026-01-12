set(PROJECT_NAME Arguments)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "Argument.h"
    "ArgumentTable.h"
    "framework.h"
    "pch.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "ArgDate.cpp"
    "ArgDbl.cpp"
    "ArgDstr.cpp"
    "ArgEnd.cpp"
    "ArgFile.cpp"
    "ArgGetOpt.cpp"
    "ArgInt.cpp"
    "ArgLit.cpp"
    "ArgRex.cpp"
    "ArgStr.cpp"
    "Arguments.cpp"
    "pch.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Compiler projects")

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>"
)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE Arguments)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_ALL          "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEBUG        "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEFAULTBUILD "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_RELEASE      "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_ALL          "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEBUG        "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEFAULTBUILD "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_RELEASE      "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin/libraries/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_DEFAULTBUILD "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_RELEASE      "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_DEFAULTBUILD "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_RELEASE      "TRUE"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:All>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:DefaultBuild>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_WARNINGS;"
        "_LIB;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:All>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:DefaultBuild>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CRT_SECURE_NO_WARNINGS;"
        "WIN32;"
        "_LIB;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:All>:
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:DefaultBuild>:
                /Oi;
                /Gy;
                /Zi
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy;
                /Zi
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:All>:
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:DefaultBuild>:
                /Oi;
                /Gy;
                /Zi
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy;
                /Zi
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
endif()

