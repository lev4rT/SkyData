#ifndef QUEUE_SIMPLE_SERVER_H
#define QUEUE_SIMPLE_SERVER_H

#include "Server.h"

class Simple_Server : public Server {
public:
    Simple_Server(int port);
    void run_server() override;
};


#endif //QUEUE_SIMPLE_SERVER_H
