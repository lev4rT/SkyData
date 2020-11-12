#ifndef QUEUE_QUEUE_MOCK_H
#define QUEUE_QUEUE_MOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Queue_API.h"
#include "Server.h"

#include <vector>
#include <string>

class Mock_Queue : public Queue {
public:
    MOCK_METHOD(void, push_to_queue, (Message* message), ());
    MOCK_METHOD(Message, pop_from_queue, (), ());
};

#endif //QUEUE_QUEUE_MOCK_H
