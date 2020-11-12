#ifndef QUEUE_SOCKET_H
#define QUEUE_SOCKET_H


#include <memory>

class Socket {
private:
    int timeout;
    int socket_descr;

public:
    void create_server_socket(int port, int max_users);
    std::shared_ptr<Socket> accept_connection();
};


#endif //QUEUE_SOCKET_H
