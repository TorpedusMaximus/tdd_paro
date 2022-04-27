#include "catch/catch.hpp"
#include "BowlingGame.h"


TEST_CASE("testZerowychRzutow") {
    BowlingGame game;
    for (int i = 0; i < 20; i++) {
        game.roll(0);
    }
    REQUIRE(game.getScore() == 0);
}

TEST_CASE("testJednostkowychRzutow") {
    BowlingGame game;
    for (int i = 0; i < 20; i++) {
        game.roll(1);
    }
    REQUIRE(game.getScore() == 20);
}


TEST_CASE("testSpare") {
    BowlingGame game;
    game.roll(6);
    game.roll(4);
    game.roll(4);
    for (int i = 0; i < 17; i++) {
        game.roll(0);
    }
    REQUIRE(game.getScore() == 18);
}

TEST_CASE("testStrike") {
    BowlingGame game;
    game.roll(10);
    game.roll(3);
    game.roll(4);
    for (int i = 0; i < 16; i++) {
        game.roll(0);
    }
    REQUIRE(game.getScore() == 24);
}

TEST_CASE("perfekcyjnaGra") {
    BowlingGame game;
    for (int i = 0; i < 12; i++) {
        game.roll(10);
    }
    REQUIRE(game.getScore() == 300);
}
