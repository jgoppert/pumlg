#-----------------------------------------------------------------------------
# Command Line Interface
#-----------------------------------------------------------------------------
add_executable(plantuml_gen
        plantuml_gen.cpp)
target_link_libraries(plantuml_gen
        plantuml_gen_compiler
        plantuml_antlr
        antlr4-runtime
        )

install(TARGETS plantuml_gen
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
