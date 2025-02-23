
enable_warnings()

set(src
    main.c
    )

compile_fly(
    main.fly
    )

source_group("Source Files" FILES ${src})

add_executable(ServerCore ${src} ${src_fly} ${gen})
target_link_libraries(ServerCore PUBLIC FlyCommon)
set_target_properties(ServerCore PROPERTIES
    OUTPUT_NAME "server"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
    )
