#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/queue_api_mock.h"
#include "../include/queue_mock.h"
#include "../include/server_mock.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

TEST(SERVER_QUEUE_INTERACTION, PUSH_MESSAGE) {
    Mock_Server server;
    Message msg;
    Mock_Queue queue;
    EXPECT_CALL(queue, push_to_queue(&msg)).Times(1);

    server.push_message_to_queue(&queue, msg);
}

TEST(SERVER_QUEUE_INTERACTION, POP_MESSAGE) {
    Mock_Server server;
    Message msg;
    Mock_Queue queue;
    EXPECT_CALL(queue, pop_from_queue()).Times(1);

    server.pop_message_from_queue(&queue);
}
