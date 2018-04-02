#-----------------------------------------------------------------------------
# Command Line Interface
#-----------------------------------------------------------------------------
add_executable(pumlg_cli
        pumlg_cli.cpp)

target_link_libraries(pumlg_cli
        pumlg_compiler
        pumlg_parser
        pumlg_generator_json
        antlr4-runtime
        )

install(TARGETS pumlg_cli
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

# vim: set et fenc=utf-8 ff=unix ft=cmake sts=0 sw=4 ts=4 :
