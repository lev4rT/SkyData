#ifndef QUEUE_ON_DISK_SAVER_QUEUE_H
#define QUEUE_ON_DISK_SAVER_QUEUE_H

#include "Queue.h"
#include <string>

class On_Disk_Saver_Queue : public Queue {
private:
    std::string queue_directory;
    size_t start_index;
    size_t end_index;

public:
    void push_to_queue(Message* message) override;
    Message pop_from_queue() override;
};


#endif //QUEUE_ON_DISK_SAVER_QUEUE_H
