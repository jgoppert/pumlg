#-----------------------------------------------------------------------------
# Compiler
#-----------------------------------------------------------------------------
add_library(plantuml_gen_compiler STATIC
        ${PROJECT_BINARY_DIR}/version.cpp
        version.h
        )
target_link_libraries(plantuml_gen_compiler
        antlr4-runtime
        plantuml_antlr
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
