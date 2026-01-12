set(PROJECT_NAME yacc) 

################################################################################
# Source groups
################################################################################
set(Header_Files
    "h/alloc.h"
    "h/yacc.h"
    "h/yaccins.h"
    "h/ytabmac.inc"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "c/bitsets.c"
    "c/buildpro.c"
    "c/default.c" 
    "c/defshift.c"
    "c/dont_opt.c"
    "c/elimunit.c"
    "c/fpopen.c"
    "c/genfast.c"
    "c/gensupp.c"
    "c/gentable.c"
    "c/getname.c"
    "c/lalr1.c"
    "c/lr0.c"
    "c/parse.c"
    "c/sentence.c"
    "c/used.c"
    "c/writeobj.c"
    "c/yacc.c"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Compiler projects")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE yacc)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_ALL          "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEBUG        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEFAULTBUILD "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_RELEASE      "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_ALL          "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEBUG        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_DEFAULTBUILD "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
        OUTPUT_DIRECTORY_RELEASE      "${CMAKE_CURRENT_SOURCE_DIR}/../../../../bin/tools/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
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
# MSVC runtime library
################################################################################
get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        $<$<CONFIG:All>:
            MultiThreadedDebug
        >
        $<$<CONFIG:Debug>:
            MultiThreadedDebug
        >
        $<$<CONFIG:DefaultBuild>:
            MultiThreaded
        >
        $<$<CONFIG:Release>:
            MultiThreaded
        >
        $<$<NOT:$<OR:$<CONFIG:All>,$<CONFIG:Debug>,$<CONFIG:DefaultBuild>,$<CONFIG:Release>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        $<$<CONFIG:All>:
            MultiThreadedDebug
        >
        $<$<CONFIG:Debug>:
            MultiThreadedDebug
        >
        $<$<CONFIG:DefaultBuild>:
            MultiThreaded
        >
        $<$<CONFIG:Release>:
            MultiThreaded
        >
        $<$<NOT:$<OR:$<CONFIG:All>,$<CONFIG:Debug>,$<CONFIG:DefaultBuild>,$<CONFIG:Release>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

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
        "_CONSOLE;"
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
        "_CONSOLE;"
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
            $<$<CONFIG:DefaultBuild>:
                /Oi;
                /Gy
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DefaultBuild>:
                /Oi;
                /Gy
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

