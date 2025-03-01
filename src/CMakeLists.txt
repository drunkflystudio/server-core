
enable_warnings()

fly_module(ServerCore
    USES
        FlyRuntime
    SOURCES
        main.fly
    )

set_target_properties(ServerCore PROPERTIES FOLDER "Server")

######################################################################################################################

set(src
    main.c
    )

source_group("Source Files" FILES ${src})

add_executable(StudioServer ${src})
target_link_libraries(StudioServer PUBLIC ServerCore)
set_target_properties(StudioServer PROPERTIES
    OUTPUT_NAME "server"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
    )
