#include "elf.hpp"

#include "squirrel.hpp"
#include "gtest/gtest.h"
#include "rogue.hpp"
#include "visitor.hpp"

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

TEST(ElfTest, ConstructorAndGetType) {
    Point point(7, 14);
    Elf elf("Losyash", point);
    EXPECT_EQ(elf.getName(), "Losyash");
    EXPECT_EQ(elf.getType(), "Elf");
    EXPECT_EQ(elf.getPosition().getX(), 7);
    EXPECT_EQ(elf.getPosition().getY(), 14);
}

TEST(ElfTest, KillsLogic) {
    Point point1(0, 0);
    Elf elf1("Losyash", point1);

    Point point2(1, 1);
    Rogue rogue1("Krosh", point2);
    Squirrel squirrel1("Pin", point2);

    EXPECT_TRUE(elf1.kills(rogue1));
    EXPECT_FALSE(elf1.kills(squirrel1));
    EXPECT_FALSE(elf1.kills(elf1));
}

TEST(ElfTest, AcceptVisitor) {
    Point point1(0, 0);
    Elf Elf1("Losyash", point1);

    Point point2(1, 1);
    Rogue rogue1("Krosh", point2);

    DummyVisitor visitor1;
    Elf1.accept(visitor1, rogue1);

    EXPECT_FALSE(visitor1.visitedSquirrel);
    EXPECT_FALSE(visitor1.visitedRogue);
    EXPECT_TRUE(visitor1.visitedElf);
}
