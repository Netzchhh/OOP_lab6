#include "rogue.hpp"

#include "squirrel.hpp"
#include "gtest/gtest.h"
#include "visitor.hpp"
#include "elf.hpp"

class DummyVisitor : public Visitor {
   public:
    bool visitedSquirrel = false;
    bool visitedRogue = false;
    bool visitedElf = false;

    void visit(Squirrel& attacker, NPC& defender) override {
        visitedSquirrel = true;
    }
    void visit(Rogue& attacker, NPC& defender) override {
        visitedRogue = true;
    }
    void visit(Elf& attacker, NPC& defender) override {
        visitedElf = true;
    }
};

TEST(RogueTest, ConstructorAndGetType) {
    Point point(5, 10);
    Rogue rogue("Krosh", point);
    EXPECT_EQ(rogue.getName(), "Krosh");
    EXPECT_EQ(rogue.getType(), "Rogue");
    EXPECT_EQ(rogue.getPosition().getX(), 5);
    EXPECT_EQ(rogue.getPosition().getY(), 10);
}

TEST(RogueTest, KillsLogic) {
    Point point1(0, 0);
    Rogue rogue1("Krosh", point1);

    Point point2(1, 1);
    Squirrel squirrel1("Pin", point2);
    Elf elf1("Losyash", point2);

    EXPECT_TRUE(rogue1.kills(squirrel1));
    EXPECT_FALSE(rogue1.kills(elf1));
    EXPECT_FALSE(rogue1.kills(rogue1));
}

TEST(RogueTest, AcceptVisitor) {
    Point point1(0, 0);
    Rogue rogue1("Krosh", point1);

    Point point2(1, 1);
    Squirrel squirrel1("Squirrel", point2);

    DummyVisitor visitor1;
    rogue1.accept(visitor1, squirrel1);

    EXPECT_FALSE(visitor1.visitedSquirrel);
    EXPECT_TRUE(visitor1.visitedRogue);
    EXPECT_FALSE(visitor1.visitedElf);
}
