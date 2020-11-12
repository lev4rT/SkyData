#ifndef QUEUE_SERVER_H
#define QUEUE_SERVER_H

#include <vector>
#include "../queue/Queue.h"

class Socket_Wrap;

class Server {
private:
    int timeout{};
    Socket_Wrap* server_socket{};
    std::vector<Socket_Wrap*> clients_sockets;
    Queue* shared_queue{};
    std::vector<Queue*> users_queue;

protected:
    int port;
public:
    virtual void run_server() = 0;
    void push_message_to_queue(Queue* queue, Message& message);
    Message pop_message_from_queue(Queue* queue);
};


#endif //QUEUE_SERVER_H
