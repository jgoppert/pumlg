#-----------------------------------------------------------------------------
# Generated Antlr Parser
#-----------------------------------------------------------------------------

# parser
find_program(ANTLR4_JAR NAMES antlr-4.7.1-complete.jar HINTS ${PROJECT_SOURCE_DIR}/java)
if (NOT ANTLR4_JAR)
    message(FATAL_ERROR "antlr4_jar not found: ${ANTLR4_JAR}")
endif ()
find_package(Java COMPONENTS Runtime REQUIRED)

set(antlr_parser Pumlg.g4)
set(antlr_lexer Pumlg.g4)
set(antlr_srcs
        PumlgBaseListener.cpp
        PumlgLexer.cpp
        PumlgListener.cpp
        PumlgParser.cpp
        )
set_source_files_properties(${antlr_srcs} PROPERTIES GENERATED True)
set(antlr_hdrs
        PumlgBaseListener.h
        PumlgLexer.h
        PumlgListener.h
        PumlgParser.h
        )
set_source_files_properties(${antlr_hdrs} PROPERTIES GENERATED True)
add_custom_command(OUTPUT ${antlr_srcs} ${antlr_hdrs}
        COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR4_JAR}" -Werror
        -Dlanguage=Cpp -listener -o "${CMAKE_CURRENT_BINARY_DIR}"
        -package pumlg_antlr "${antlr_lexer}" "${antlr_parser}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        DEPENDS ${antlr_parser} ${antlr_lexer})
include_directories(${EP_PREFIX}/include/antlr4-runtime)
add_library(pumlg_parser STATIC
        ${antlr_srcs}
        ${antlr_hdrs}
        )
add_dependencies(pumlg_parser antlr4cpp)
target_link_libraries(pumlg_parser antlr4-runtime)

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
