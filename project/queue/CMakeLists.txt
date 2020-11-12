cmake_minimum_required(VERSION 3.17)
project(queue)

set(CMAKE_CXX_STANDARD 14)

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})


include_directories(/usr/src/googletest/googlemock/include/gmock/)
LINK_DIRECTORIES(/usr/src/googletest/googlemock/lib)

include_directories("${PROJECT_SOURCE_DIR}/include/queue/"
                    "${PROJECT_SOURCE_DIR}/include/queue_api/"
                    "${PROJECT_SOURCE_DIR}/include/server/"
                    "${PROJECT_SOURCE_DIR}/include/socket/"
                    "${PROJECT_SOURCE_DIR}/include/message/")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/queue/Queue.cpp"
                  "${PROJECT_SOURCE_DIR}/src/queue/Vector_Queue.cpp"
                  "${PROJECT_SOURCE_DIR}/src/queue/On_Disk_Saver_Queue.cpp"
                  "${PROJECT_SOURCE_DIR}/src/queue_api/Queue_API.cpp"
                  "${PROJECT_SOURCE_DIR}/src/server/Server.cpp"
                  "${PROJECT_SOURCE_DIR}/src/server/Simple_Server.cpp"
                  "${PROJECT_SOURCE_DIR}/src/socket/Socket.cpp")

add_executable(queue ${PROJECT_SOURCE_DIR}/src/main.cpp ${sources})

add_executable(tests_gmock tests/main.cpp ${sources} ${LIB_SOURCE_FILES} tests/queue_api_mock.h tests/queue_mock.h tests/server_mock.h)
target_link_libraries(tests_gmock  ${GTEST_LIBRARIES} pthread -lgtest -lgmock)