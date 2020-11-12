#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "queue_api_mock.h"
#include "queue_mock.h"
#include "server_mock.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

TEST(QUEUE_API, ESTABLISH_CONNECTION) {
    Mock_Queue_API api;
    EXPECT_CALL(api, establish_connection()).Times(AtLeast(1));
    User<Mock_Queue_API> user(&api);
    user.get_connection();
}

TEST(QUEUE_API, SEND_MESSAGE) {
    Mock_Queue_API api;
    message msg;
    EXPECT_CALL(api, establish_connection()).Times(1);
    EXPECT_CALL(api, send_message(&msg)).Times(1);
    User<Mock_Queue_API> user(&api);
    user.get_connection();
    user.try_to_send_message(&msg);
}

TEST(QUEUE_API, RECEIVE_MESSAGE) {
    Mock_Queue_API api;
    EXPECT_CALL(api, establish_connection()).Times(1);
    EXPECT_CALL(api, receive_message()).Times(1);
    User<Mock_Queue_API> user(&api);
    user.get_connection();
    user.try_to_receive_message();
}


TEST(QUEUE_API, BREAK_CONNECTION) {
    Mock_Queue_API api;
    EXPECT_CALL(api, establish_connection()).Times(1);
    EXPECT_CALL(api, break_connection()).Times(1);
    User<Mock_Queue_API> user(&api);
    user.get_connection();
    user.quit_connection();
}

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

int main(int argc, char** argv) {
    return RUN_ALL_TESTS();
}