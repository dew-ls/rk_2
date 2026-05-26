#include <string>
#include <gtest/gtest.h>

struct Color
{
    Color(std::uint8_t R, std::uint8_t G, std::uint8_t B)
        : R(R), G(G), B(B)
    {}

    std::uint8_t R, G, B;
};

class Theme
{
public:
    virtual ~Theme() = default;

    virtual std::string Name() const = 0;
    virtual Color WallColor() const = 0;
    virtual Color FloorColor() const = 0;
    virtual Color CeilingColor() const = 0;
};

class CustomTheme : public Theme
{
public:
    CustomTheme(std::string name, Color wallColor, Color floorColor, Color ceilingColor)
        : name_(std::move(name)), wallColor_(wallColor), floorColor_(floorColor), ceilingColor_(ceilingColor)
    {}

    std::string Name() const override { return name_; }
    Color WallColor() const override { return wallColor_; }
    Color FloorColor() const override { return floorColor_; }
    Color CeilingColor() const override { return ceilingColor_; }

private:
    std::string name_;
    Color wallColor_, floorColor_, ceilingColor_;
};

TEST(Theme, Theme_creating)
{
    CustomTheme t("thm", Color(1, 2, 3), Color(4, 5, 6), Color(7, 8, 9));
    EXPECT_EQ(t.Name(), "thm");
    EXPECT_EQ(t.WallColor().R, 1);
    EXPECT_EQ(t.FloorColor().G, 5);
    EXPECT_EQ(t.CeilingColor().B, 9);
}
