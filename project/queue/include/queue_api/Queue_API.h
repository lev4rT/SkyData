#ifndef QUEUE_QUEUE_API_H
#define QUEUE_QUEUE_API_H

#include <vector>
#include <string>
#include "Message.h"

enum {
    CONNECTION_SUCCESS,
    CONNECTION_FAILURE,
};

class Queue_API {
private:
    std::vector<std::string> queue_ips;
public:
    int establish_connection();
    int break_connection();
    int send_message(message &);
    message* receive_message();
};


#endif //QUEUE_QUEUE_API_H
