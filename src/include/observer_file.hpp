#pragma once

#include <string>

#include "observer.hpp"

class FileLogger : public IObserver {
   public:
    void onEvent(const std::string& msg) override;
};
