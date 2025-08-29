#ifndef COMMAND_H
#define COMMAND_H

#include <Arduino.h>
#include "utils/"

class Command {
public:
    String command;
    void readCommand();
    void processCommand(String command);
};

extern Command cmd;
#endif