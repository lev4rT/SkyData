#include <iostream>
#include "../include/server/Simple_Server.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " port" << std::endl;
        return 0;
    }
    int port = std::stoi(std::string(argv[1]));
    Simple_Server server(port);
    server.run_server();

    return 0;
}
