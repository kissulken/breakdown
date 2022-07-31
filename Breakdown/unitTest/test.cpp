#include "gtest/gtest.h"
#include "../src/Block.h"
#include "../src/Constants.h"
#include "gmock/gmock.h"



class MockNavigation : public INavigation
{
public:
    MOCK_METHOD(void, setColor, (Constants::Color text, Constants::Color background), (override));
    MOCK_METHOD(void, setColor, (Constants::Color background), (override));
    MOCK_METHOD(void, textThrower, (const Points p, const std::string& phrase), (override));
    MOCK_METHOD(void, textThrower, (const Points p, const char ch), (override));
    MOCK_METHOD(void, Do_Sleep, (const int time), (override));
    MOCK_METHOD(bool, buttonPressed, (), (override));
    MOCK_METHOD(Constants::Directions, whichButtonIsPressed, (), (override));
    MOCK_METHOD(void, SetCursor, (const Points p), (override));
    MOCK_METHOD(void, WindowInit, (), (override));
    MOCK_METHOD(void, sayIt, (const std::string& s, Points p, Constants::Color text_color, Constants::Color bvackground_color), (override));
};

class BreakdownTest : public ::testing::Test
{
public:
    BreakdownTest()
    {
        mock_nav = std::make_shared<MockNavigation>();
        ON_CALL(*mock_nav, buttonPressed()).WillByDefault(testing::Return(true));
        ON_CALL(*mock_nav, whichButtonIsPressed()).WillByDefault(testing::Return(Constants::Directions::ENTER_B));
    }
protected:
    std::shared_ptr<MockNavigation> mock_nav;
};

TEST_F(BreakdownTest, HPvalueTest)
{
    Block b(0, mock_nav, 2, 2);
    EXPECT_CALL(*mock_nav, setColor(testing::_)).Times(2);
    b.minusHP();
    EXPECT_EQ(1, b.getHP());
}