#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "raylib.h"
class Ball
{
    private:
        float ballX;
        float ballY;
        float ballXSpeed;
        float ballYSpeed;
        float ballRadius;
        Color ballColor;
    public:
        Ball (float x, float y, float sx, float sy, float r, Color col): ballX(x), ballY(y), ballXSpeed(sx), ballYSpeed(sy),ballRadius(r), ballColor(col) {}
        void draw_ball()
        {
            DrawCircle(ballX, ballY, ballRadius, ballColor);
        }
        void ball_move()
        {
            ballX += ballXSpeed;
            ballY += ballYSpeed;
        }
        float getBallX()
        {
            return ballX;
        }
        float getBallY()
        {
            return ballY;
        }
        void xbounce()
        {
            ballXSpeed *= -1.1;
        }
        void ybounce()
        {
            ballYSpeed *= -1;
        }
        void resetPosition(float x, float y)
        {
            ballX = x;
            ballY = y;
        }

        void resetSpeed(float xspeed, float yspeed)
        {
            ballXSpeed = xspeed;
            ballYSpeed = yspeed;
        }

        void reverseXDirection()
        {
            ballXSpeed = -ballXSpeed;
        }



};

#endif // BALL_H_INCLUDED
