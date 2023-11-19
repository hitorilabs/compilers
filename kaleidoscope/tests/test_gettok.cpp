#include "gtest/gtest.h"
#include "smolcc.h"

TEST(EnumTests, TOK_DEF) {
    std::string buf;
    std::string inputString = "def";
    std::istringstream stringStream(inputString);
    EXPECT_EQ(gettok(stringStream, buf), TOK_DEF);
}

TEST(EnumTests, TOK_EOF) {
    std::string buf;
    std::string inputString = "";
    std::istringstream stringStream(inputString);
    EXPECT_EQ(gettok(stringStream, buf), TOK_EOF);
}

TEST(EnumTests, TOK_EXTERN) {
    std::string buf;
    std::string inputString = "extern";
    std::istringstream stringStream(inputString);
    EXPECT_EQ(gettok(stringStream, buf), TOK_EXTERN);
}

TEST(EnumTests, TOK_NUMBER) {
    std::string buf;
    std::string inputString = "1";
    std::istringstream stringStream(inputString);
    EXPECT_EQ(gettok(stringStream, buf), TOK_NUMBER);
}

TEST(EnumTests, TOK_IDENTIFIER) {
    std::string buf;
    std::string inputString = "any";
    std::istringstream stringStream(inputString);
    EXPECT_EQ(gettok(stringStream, buf), TOK_IDENTIFIER);
}

