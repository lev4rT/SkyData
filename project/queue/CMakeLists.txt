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
                    "${PROJECT_SOURCE_DIR}/include/message/"
                    "${PROJECT_SOURCE_DIR}/tests/include/")

file(GLOB main_sources "${PROJECT_SOURCE_DIR}/src/queue/Queue.cpp"
                  "${PROJECT_SOURCE_DIR}/src/queue/Vector_Queue.cpp"
                  "${PROJECT_SOURCE_DIR}/src/queue/On_Disk_Saver_Queue.cpp"
                  "${PROJECT_SOURCE_DIR}/src/queue_api/Queue_API.cpp"
                  "${PROJECT_SOURCE_DIR}/src/server/Server.cpp"
                  "${PROJECT_SOURCE_DIR}/src/server/Simple_Server.cpp"
                  "${PROJECT_SOURCE_DIR}/src/socket/Socket.cpp")

file(GLOB test_sources "${PROJECT_SOURCE_DIR}/tests/src/queue_api_tests.cpp"
        "${PROJECT_SOURCE_DIR}/tests/src/queue_tests.cpp"
        "${PROJECT_SOURCE_DIR}/tests/src/server_tests.cpp")

add_executable(queue ${PROJECT_SOURCE_DIR}/src/main.cpp ${main_sources})

add_executable(tests_gmock tests/main.cpp ${test_sources} ${main_sources} ${LIB_SOURCE_FILES})
target_link_libraries(tests_gmock  ${GTEST_LIBRARIES} pthread -lgtest -lgmock)