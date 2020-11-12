#ifndef QUEUE_SERVER_MOCK_H
#define QUEUE_SERVER_MOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Queue_API.h"
#include "Server.h"

#include <vector>
#include <string>

class Mock_Server : public Server {
    MOCK_METHOD(void, run_server, (), ());
};

#endif //QUEUE_SERVER_MOCK_H
