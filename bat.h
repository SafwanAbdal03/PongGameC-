#ifndef BAT_H_INCLUDED
#define BAT_H_INCLUDED
#include <string>
#include "raylib.h"

class Bat
{
    private:
        float batX;
        float batY;
        const float speed;
        float batWidth;
        float batLength;
        Color batColor;
    public:
        Bat(float x, float y, float s, float w, float l, Color col) : batX(x), batY(y), speed(s), batWidth(w), batLength(l), batColor(col)
        {
        }
        void draw_bat()
        {
            DrawRectangle(batX, batY, batWidth, batLength, batColor);
        }
        void move_bat_up ()
        {
            batY -= speed; // Move up only if within screen bounds
        }
        void move_bat_down()
        {
            batY += speed;
        }
        float getBatY()
        {
            return batY;
        }

};

#endif // BAT_H_INCLUDED
