cmake_minimum_required(VERSION 3.0.2)
project(barcode_lister)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES barcode_lister
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME}_node src/barcode_lister.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})