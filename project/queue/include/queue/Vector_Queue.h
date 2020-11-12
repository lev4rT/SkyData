#ifndef QUEUE_VECTOR_QUEUE_H
#define QUEUE_VECTOR_QUEUE_H

#include "Queue.h"
#include <vector>


class Vector_Queue : public Queue {
private:
    std::vector<Message> messages;

public:
    void push_to_queue(Message* message) override;
    Message pop_from_queue() override;
};


#endif //QUEUE_VECTOR_QUEUE_H
