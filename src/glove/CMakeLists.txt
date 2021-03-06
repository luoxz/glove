include_directories("${PROJECT_ROOT}/src")

add_subdirectory(natex)
add_subdirectory(events)
add_subdirectory(input)
add_subdirectory(log)
add_subdirectory(filesystem)
add_subdirectory(configuration)
add_subdirectory(utils)
add_subdirectory(resources)
add_subdirectory(services)
add_subdirectory(world)
add_subdirectory(threading)
add_subdirectory(application)
add_subdirectory(rendering)
add_subdirectory(geometry)

set(core_src
    DwarfException.cc

    exceptions/OperationNotSupported.cc
)

set(core_object_libs
    $<TARGET_OBJECTS:gc_natex>
    $<TARGET_OBJECTS:gc_events>
    $<TARGET_OBJECTS:gc_input>
    $<TARGET_OBJECTS:gc_configuration>
    $<TARGET_OBJECTS:gc_log>
    $<TARGET_OBJECTS:gc_utils>
    $<TARGET_OBJECTS:gc_filesystem>
    $<TARGET_OBJECTS:gc_resources>
    $<TARGET_OBJECTS:gc_services>
    $<TARGET_OBJECTS:gc_world>
    $<TARGET_OBJECTS:glove_utils>
    $<TARGET_OBJECTS:gc_threading>
    $<TARGET_OBJECTS:gc_application>
    $<TARGET_OBJECTS:gc_rendering>
    $<TARGET_OBJECTS:gc_geometry>
)

add_library(glove SHARED
    ${core_src}
    ${core_object_libs}
)

if(ON_UNIX)
target_link_libraries(glove ${glove_libs} dl)
else()
target_link_libraries(glove ${glove_libs})
endif()

install(TARGETS glove EXPORT GloveTargets
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
)

install(DIRECTORY .
        DESTINATION ${INCLUDE_INSTALL_DIR}/glove
        FILES_MATCHING PATTERN "*.hpp"
)
install(DIRECTORY .
        DESTINATION ${INCLUDE_INSTALL_DIR}/glove
        FILES_MATCHING PATTERN "*.h"
)
install(DIRECTORY ..
        DESTINATION ${INCLUDE_INSTALL_DIR}/glove
        FILES_MATCHING PATTERN "GloveConfig.hpp"
)