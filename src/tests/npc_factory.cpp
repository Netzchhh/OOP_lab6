#include "npc_factory.hpp"

#include "squirrel.hpp"
#include "gtest/gtest.h"
#include "rogue.hpp"
#include "elf.hpp"

TEST(NPCFactoryTest, CreateSquirrel) {
    std::shared_ptr<NPC> squirrel = NPCFactory::create("Squirrel", "Pin", 10, 20);
    ASSERT_NE(squirrel, nullptr);
    EXPECT_EQ(squirrel->getType(), "Squirrel");
    EXPECT_EQ(squirrel->getName(), "Pin");
    EXPECT_EQ(squirrel->getPosition().getX(), 10);
    EXPECT_EQ(squirrel->getPosition().getY(), 20);
}

TEST(NPCFactoryTest, CreateRogue) {
    std::shared_ptr<NPC> rogue = NPCFactory::create("Rogue", "Krosh", 5, 15);
    ASSERT_NE(rogue, nullptr);
    EXPECT_EQ(rogue->getType(), "Rogue");
    EXPECT_EQ(rogue->getName(), "Krosh");
    EXPECT_EQ(rogue->getPosition().getX(), 5);
    EXPECT_EQ(rogue->getPosition().getY(), 15);
}

TEST(NPCFactoryTest, CreateElf) {
    std::shared_ptr<NPC> elf = NPCFactory::create("Elf", "Losyash", 7, 14);
    ASSERT_NE(elf, nullptr);
    EXPECT_EQ(elf->getType(), "Elf");
    EXPECT_EQ(elf->getName(), "Losyash");
    EXPECT_EQ(elf->getPosition().getX(), 7);
    EXPECT_EQ(elf->getPosition().getY(), 14);
}

TEST(NPCFactoryTest, CreateUnknownType) {
    std::shared_ptr<NPC> unknown1 = NPCFactory::create("Dragon", "Igor", 0, 0);
    EXPECT_EQ(unknown1, nullptr);
}

TEST(NPCFactoryTest, FromStringCreatesSquirrel) {
    std::shared_ptr<NPC> squirrelFromString = NPCFactory::fromString("Squirrel Pin 10 20");
    ASSERT_NE(squirrelFromString, nullptr);
    EXPECT_EQ(squirrelFromString->getType(), "Squirrel");
    EXPECT_EQ(squirrelFromString->getName(), "Pin");
    EXPECT_EQ(squirrelFromString->getPosition().getX(), 10);
    EXPECT_EQ(squirrelFromString->getPosition().getY(), 20);
}

TEST(NPCFactoryTest, FromStringCreatesRogue) {
    std::shared_ptr<NPC> rogueFromString = NPCFactory::fromString("Rogue Krosh 5 15");
    ASSERT_NE(rogueFromString, nullptr);
    EXPECT_EQ(rogueFromString->getType(), "Rogue");
    EXPECT_EQ(rogueFromString->getName(), "Krosh");
    EXPECT_EQ(rogueFromString->getPosition().getX(), 5);
    EXPECT_EQ(rogueFromString->getPosition().getY(), 15);
}

TEST(NPCFactoryTest, FromStringCreatesElf) {
    std::shared_ptr<NPC> elfFromString = NPCFactory::fromString("Elf Losyash 7 14");
    ASSERT_NE(elfFromString, nullptr);
    EXPECT_EQ(elfFromString->getType(), "Elf");
    EXPECT_EQ(elfFromString->getName(), "Losyash");
    EXPECT_EQ(elfFromString->getPosition().getX(), 7);
    EXPECT_EQ(elfFromString->getPosition().getY(), 14);
}

TEST(NPCFactoryTest, FromStringUnknownType) {
    std::shared_ptr<NPC> unknownFromString = NPCFactory::fromString("Dragon Igor 0 0");
    EXPECT_EQ(unknownFromString, nullptr);
}
