file(GLOB SOURCES src/*.cpp)

#include_directories(../core/inc/public)
#include_directories(../log/inc/public)

if (WIN32)
#    add_executable(gtest WIN32 ${SOURCES})
	add_executable(gtest ${SOURCES})
elseif(APPLE)
    add_executable(gtest MACOSX_BUNDLE ${SOURCES})
else()
    add_executable(gtest ${SOURCES})
endif()


add_definitions(-DCORE_API=__DLL_IMPORT)
add_definitions(-DLOG_API=__DLL_IMPORT)
if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 /W4 /Od /DDEBUG /MDd")
	set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 /W4 /O2 /DNDEBUG /MD")
else ()
	set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 -O0 -W -Wall -g -ggdb")
	set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 -rdynamic -O2 -W -Wall -DNDEBUG")
endif ()

add_dependencies(gtest core log)
target_link_libraries(gtest core log)

target_include_directories(gtest 
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/inc/private" "${CMAKE_SOURCE_DIR}/include"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc/public"
)

# pre compile
set_target_properties(gtest PROPERTIES
    SOVERSION ${SOVERSION}
    VERSION ${VERSION}
    COTIRE_CXX_PREFIX_HEADER_INIT "${CMAKE_CURRENT_SOURCE_DIR}/inc/private/stdafx.h"
)
cotire(gtest)

# install
install(TARGETS gtest
    ARCHIVE DESTINATION lib/gtest
    LIBRARY DESTINATION lib/gtest
	RUNTIME DESTINATION bin
    COMPONENT library
)

file(GLOB INCLUDES inc/public/*.h)
install(FILES ${INCLUDES} DESTINATION include/gtest)