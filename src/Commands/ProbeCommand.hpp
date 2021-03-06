#pragma once
#include "Command.hpp"

class ProbeCommand : public Command {
    public:
        void run(const std::vector<std::string> &args) override {
            if (!hasExactArguments(1, args)) return;
            
            SecuritySuite security = GameManager::getInstance()->getCurrentComputer()->getSecurity();
            std::cout << security.probe();
        }
};
