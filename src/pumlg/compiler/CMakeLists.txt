#-----------------------------------------------------------------------------
# Compiler
#-----------------------------------------------------------------------------
add_library(pumlg_compiler STATIC
        ${PROJECT_BINARY_DIR}/version.cpp
        version.h
        Compiler.cpp Compiler.h Ast.cpp Ast.h)

target_link_libraries(pumlg_compiler
        antlr4-runtime
        pumlg_parser
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
