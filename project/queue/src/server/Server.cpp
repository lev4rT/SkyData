#include "Server.h"

Message Server::pop_message_from_queue(Queue *queue) {
    return queue->pop_from_queue();
}

void Server::push_message_to_queue(Queue *queue, Message &message) {
    queue->push_to_queue(&message);
}
