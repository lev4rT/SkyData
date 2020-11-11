//
// Created by yaroslav on 11.11.2020.
//

#ifndef PROJECT_LOCAL_LISTENER_H
#define PROJECT_LOCAL_LISTENER_H
#include "iostream"
#include "messages.h"


class local_listener{
public:
    local_listener();
    ~local_listener();
    void list_local_machine();

private:
    message mes;
    void create_message();
};




#endif //PROJECT_LOCAL_LISTENER_H
