#pragma once

#include "npc.hpp"

class Squirrel;
class Rogue;
class Elf;
class NPC;

class Visitor {
   public:
    virtual ~Visitor() = default;

    virtual void visit(Squirrel& attacker, NPC& defender) = 0;
    virtual void visit(Rogue& attacker, NPC& defender) = 0;
    virtual void visit(Elf& attacker, NPC& defender) = 0;
};
