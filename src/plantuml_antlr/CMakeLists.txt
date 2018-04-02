#-----------------------------------------------------------------------------
# Generated Antlr Parser
#-----------------------------------------------------------------------------

# antlr
find_program(ANTLR4_JAR NAMES antlr-4.7.1-complete.jar HINTS ${PROJECT_SOURCE_DIR}/java)
if (NOT ANTLR4_JAR)
    message(FATAL_ERROR "antlr4_jar not found: ${ANTLR4_JAR}")
endif ()
find_package(Java COMPONENTS Runtime REQUIRED)

set(antlr_dir ${PROJECT_BINARY_DIR}/plantuml_antlr)
set(antlr_parser ${CMAKE_CURRENT_SOURCE_DIR}/Plantuml.g4)
set(antlr_lexer ${CMAKE_CURRENT_SOURCE_DIR}/Plantuml.g4)
file(MAKE_DIRECTORY ${antlr_dir})
set(antlr_srcs
        ${antlr_dir}/PlantumlBaseListener.cpp
        ${antlr_dir}/PlantumlLexer.cpp
        ${antlr_dir}/PlantumlListener.cpp
        ${antlr_dir}/PlantumlParser.cpp
        )
set_source_files_properties(${antlr_srcs} PROPERTIES GENERATED True)
set(antlr_hdrs
        ${antlr_dir}/PlantumlBaseListener.h
        ${antlr_dir}/PlantumlLexer.h
        ${antlr_dir}/PlantumlListener.h
        ${antlr_dir}/PlantumlParser.h
        )
set_source_files_properties(${antlr_hdrs} PROPERTIES GENERATED True)
add_custom_command(OUTPUT ${antlr_srcs} ${antlr_hdrs}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${antlr_dir}
        COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR4_JAR}" -Werror
        -Dlanguage=Cpp -listener -o "${antlr_dir}"
        -package plantuml_antlr "${antlr_lexer}" "${antlr_parser}"
        WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
        DEPENDS ${antlr_parser} ${antlr_lexer})
include_directories(${EP_PREFIX}/include/antlr4-runtime)
add_library(plantuml_antlr STATIC
        ${antlr_srcs}
        ${antlr_hdrs}
        )
add_dependencies(plantuml_antlr antlr4cpp)
target_link_libraries(plantuml_antlr antlr4-runtime)

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
