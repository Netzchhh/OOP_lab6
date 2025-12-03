#pragma once

#include "npc.hpp"

class Squirrel : public NPC {
   public:
    Squirrel(const std::string& name, const Point& pos);

    std::string getType() const override;
    bool kills(const NPC& other) const override;
    void accept(Visitor& visitor, NPC& other) override;
};
