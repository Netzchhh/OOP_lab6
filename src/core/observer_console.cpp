#include "observer_console.hpp"

#include <iostream>

void ConsoleLogger::onEvent(const std::string& msg) {
    std::cout << msg << std::endl;
}
