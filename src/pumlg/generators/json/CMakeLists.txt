#-----------------------------------------------------------------------------
# Compiler
#-----------------------------------------------------------------------------
add_library(pumlg_generator_json STATIC
        Generator.cpp Generator.h)

add_dependencies(pumlg_generator_json json)

target_link_libraries(pumlg_generator_json
        antlr4-runtime
        pumlg_compiler
        )

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
