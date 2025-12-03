#include "squirrel.hpp"

#include <string>

#include "visitor.hpp"

Squirrel::Squirrel(const std::string& name, const Point& pos) : NPC(name, pos) {
}

std::string Squirrel::getType() const {
    return "Squirrel";
}

bool Squirrel::kills(const NPC& other) const {
    return other.getType() == "Elf";
}

void Squirrel::accept(Visitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}
