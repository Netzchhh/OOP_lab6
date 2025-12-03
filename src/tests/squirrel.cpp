#include "squirrel.hpp"

#include "gtest/gtest.h"
#include "rogue.hpp"
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

TEST(SquirrelTest, ConstructorAndGetType) {
    Point point(10, 20);
    Squirrel squirrel("Pin", point);
    EXPECT_EQ(squirrel.getName(), "Pin");
    EXPECT_EQ(squirrel.getType(), "Squirrel");
    EXPECT_EQ(squirrel.getPosition().getX(), 10);
    EXPECT_EQ(squirrel.getPosition().getY(), 20);
}

TEST(SquirrelTest, KillsLogic) {
    Point point1(0, 0);
    Squirrel squirrel1("Pin", point1);

    Point point2(1, 1);
    Elf elf1("Losyash", point2);
    Rogue rogue1("Krosh", point2);

    EXPECT_TRUE(squirrel1.kills(elf1));
    EXPECT_FALSE(squirrel1.kills(rogue1));
    EXPECT_FALSE(squirrel1.kills(squirrel1));
}

TEST(SquirrelTest, AcceptVisitor) {
    Point point1(0, 0);
    Squirrel squirrel1("Pin", point1);

    Point point2(1, 1);
    Elf elf1("Losyash", point2);

    DummyVisitor visitor1;
    squirrel1.accept(visitor1, elf1);

    EXPECT_TRUE(visitor1.visitedSquirrel);
    EXPECT_FALSE(visitor1.visitedRogue);
    EXPECT_FALSE(visitor1.visitedElf);
}
