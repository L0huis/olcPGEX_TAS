#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "olcPEX_TAS.h"

class Snake : public olc::PixelGameEngine
{
public:
    Snake()
    {
        sAppName = "Snake";
    }

    enum
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    } m_facing_direction = EAST;
    std::vector<olc::vi2d> m_snake{{10, 10}, {9, 10}};

    olc::vi2d m_apple;

    void eat()
    {
        // Grow the snake
        m_snake.emplace_back(m_snake.back());

        // Replace the apple and don't spawn it inside of the body.
        do
        {
            m_apple.x = rand() % ScreenWidth();
            m_apple.y = rand() % ScreenHeight();
        } while (std::find(m_snake.begin() + 1, m_snake.end(), m_apple) != m_snake.end());
    }

public:
    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        static float fTotalElapsedTime = 0.0f;
        fTotalElapsedTime += fElapsedTime;

        // Update controls
        if (GetKey(olc::W).bPressed || GetKey(olc::UP).bPressed)
            m_facing_direction = NORTH;
        if (GetKey(olc::D).bPressed || GetKey(olc::RIGHT).bPressed)
            m_facing_direction = EAST;
        if (GetKey(olc::S).bPressed || GetKey(olc::DOWN).bPressed)
            m_facing_direction = SOUTH;
        if (GetKey(olc::A).bPressed || GetKey(olc::LEFT).bPressed)
            m_facing_direction = WEST;

        if (fTotalElapsedTime >= 0.1f)
        {
            fTotalElapsedTime -= 0.1f;
            // Move the rest of the snake along
            for (auto itr = m_snake.rbegin(); itr != m_snake.rend() - 1; itr++)
            {
                *itr = *(itr + 1);
            }
            // Move the snake's head in the proper direction
            switch (m_facing_direction)
            {
                case NORTH: m_snake.front().y--; break;
                case EAST: m_snake.front().x++; break;
                case SOUTH: m_snake.front().y++; break;
                case WEST: m_snake.front().x--; break;
            }
            // Potentially wrap the snake around
            if (m_snake.front().x < 0)
                m_snake.front().x = ScreenWidth() - 1;
            if (m_snake.front().x >= ScreenWidth())
                m_snake.front().x = 0;
            if (m_snake.front().y < 0)
                m_snake.front().y = ScreenHeight() - 1;
            if (m_snake.front().y >= ScreenHeight())
                m_snake.front().y = 0;
            // Eating
            if (m_snake.front() == m_apple)
            {
                eat();
            }

            // Snake eating itself
            auto elem = std::find(m_snake.begin() + 1, m_snake.end(), m_snake.front());
            if (elem != m_snake.end())
            {
                m_snake.erase(elem, m_snake.end());
            }

            Clear(olc::BLACK);
            // Draw Snake
            Draw(m_snake.front(), olc::GREEN);
            for (auto itr = m_snake.begin() + 1; itr != m_snake.end(); itr++)
            {
                Draw(*itr, olc::WHITE);
            }
            // Draw Apple
            Draw(m_apple, olc::RED);
        }

        return true;
    }
};

int main()
{
    Snake demo;
    if (demo.Construct(50, 50, 8, 8))
        demo.Start();
    return 0;
}
