#include "interface.h"

int main() {
    //creates new interface object called program and stores an empty User object inside it
    Interface program(new User);
    //runs start screen which shows user information
    program.start();
    //begin to take input from the user
    program.console();
    return 0;
}