#include "battle_visitor.hpp"

#include <string>
#include <vector>

#include "squirrel.hpp"
#include "gtest/gtest.h"
#include "observer.hpp"
#include "point.hpp"
#include "rogue.hpp"
#include "elf.hpp"

class DummyObserver : public IObserver {
   public:
    std::vector<std::string> messages;

    void onEvent(const std::string& msg) override {
        messages.push_back(msg);
    }
};

TEST(BattleVisitorTest, SquirrelKillsElf) {
    Point pointSquirrel(0, 0);
    Point pointElf(10, 10);

    Squirrel squirrel("Pin", pointSquirrel);
    Elf elf("Losyash", pointElf);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    squirrel.accept(visitor, elf);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Pin killed Losyash");
}

TEST(BattleVisitorTest, RogueKillsSquirrel) {
    Point pointRogue(0, 0);
    Point pointSquirrel(10, 10);

    Rogue rogue("Krosh", pointRogue);
    Squirrel squirrel("Pin", pointSquirrel);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    rogue.accept(visitor, squirrel);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Krosh killed Pin");
}

TEST(BattleVisitorTest, ElfKillsRogue) {
    Point pointElf(0, 0);
    Point pointRogue(10, 10);

    Elf elf("Losyash", pointElf);
    Rogue rogue("Krosh", pointRogue);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    elf.accept(visitor, rogue);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Losyash killed Krosh");
}

TEST(BattleVisitorTest, NoKillOutOfRange) {
    Point pointSquirrel(0, 0);
    Point pointRogue(100, 100);

    Squirrel squirrel("Pin", pointSquirrel);
    Rogue rogue("Losyash", pointRogue);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    squirrel.accept(visitor, rogue);

    EXPECT_TRUE(observer.messages.empty());
}
