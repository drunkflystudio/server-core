
enable_warnings()

set(src
    main.c
    )

set(compiled_c "${CMAKE_CURRENT_BINARY_DIR}/compiled.c")

set(src_fly
    "${CMAKE_CURRENT_SOURCE_DIR}/main.fly"
    )

set(gen
    "${compiled_c}"
    )

source_group("Source Files" FILES ${src} ${src_fly})
source_group("Generated Files" FILES ${gen})

add_custom_command(OUTPUT ${gen}
    COMMAND FlyCompiler -bootstrap -o "${compiled_c}" ${src_fly}
    DEPENDS ${src_fly} FlyCompiler
    )

add_executable(ServerCore ${src} ${src_fly} ${gen})
target_link_libraries(ServerCore PUBLIC FlyCommon)
