include_directories("client/observer/inc")
include_directories("messages")


set (
        OBSERBER_SRC
        client/observer/src/local_listener.cpp
        client/observer/src/observer.cpp
        client/observer/src/message_listener.cpp
        client/observer/src/message_updater.cpp
        client/observer/src/cloud_storage_downloader.cpp
)



add_executable(project main.cpp ${OBSERVER_SRC})
