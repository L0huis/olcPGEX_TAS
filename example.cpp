#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Snake : public olc::PixelGameEngine
{
public:
    Snake()
    {
        sAppName = "Snake";
    }

public:

    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        Clear(olc::BLACK);

        return true;
    }
};

int main()
{
    Snake demo;
    if (demo.Construct(256, 240, 4, 4))
        demo.Start();
    return 0;
}
