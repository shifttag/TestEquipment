#ifndef COMMAND_H
#define COMMAND_H

#include <Arduino.h>

class Command {
public:
    String command;
    void readCommand();
    void processCommand(String command);
};

extern Command cmd;
#endif