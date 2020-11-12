#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/queue_api_mock.h"
#include "../include/queue_mock.h"
#include "../include/server_mock.h"

TEST(QUEUE, POP_FROM_EMPTY_QUEUE) {
    Message msg;
    Mock_Queue queue;
    EXPECT_CALL(queue, pop_from_queue()).Times(1);

    // Pop from empty queue. Test for future.
    ASSERT_THROW(queue.pop_from_queue(), std::exception);
}