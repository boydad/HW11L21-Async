cmake_minimum_required(VERSION 3.5)

project(HW11L21-Async)
set(EXECUTE_FILE_NAME async_check)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GetGitRevisionDescription)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/bulk/include)

add_executable(${EXECUTE_FILE_NAME} src/main.cpp)
add_library(async SHARED src/async.cpp)

target_link_libraries(${EXECUTE_FILE_NAME} async)

set_target_properties(${EXECUTE_FILE_NAME} async PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

# install(TARGETS ${EXECUTE_FILE_NAME} DESTINATION bin)
install(TARGETS async LIBRARY DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/async.h DESTINATION include)

set(CPACK_PACKAGE_NAME async)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION ${VERSION_SHORT})
set(CPACK_PACKAGE_CONTACT xxx@xxx.xx)

include(CPack)
