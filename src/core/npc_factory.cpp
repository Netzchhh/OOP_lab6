#include "npc_factory.hpp"

#include <memory>
#include <sstream>

#include "squirrel.hpp"
#include "rogue.hpp"
#include "elf.hpp"

std::shared_ptr<NPC> NPCFactory::create(const std::string& type, const std::string& name, int x,
                                        int y) {
    if (type == "Squirrel")
        return std::make_shared<Squirrel>(name, Point(x, y));
    if (type == "Rogue")
        return std::make_shared<Rogue>(name, Point(x, y));
    if (type == "Elf")
        return std::make_shared<Elf>(name, Point(x, y));
    return nullptr;
}

std::shared_ptr<NPC> NPCFactory::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string type, name;
    int x, y;
    ss >> type >> name >> x >> y;
    return create(type, name, x, y);
}
