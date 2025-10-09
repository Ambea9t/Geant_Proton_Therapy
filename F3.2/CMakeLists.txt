
cmake_minimum_required(VERSION 3.16...3.21)

project(F2_dop)


find_package(Geant4 REQUIRED ui_all vis_all)


include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include ${Geant4_INCLUDE_DIR})


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)


add_executable(go go.cc ${sources} ${headers})
target_link_libraries(go ${Geant4_LIBRARIES})


file(GLOB MACRO_FILES
  "*.mac"
)

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})


add_custom_target(F2_dop DEPENDS go)
