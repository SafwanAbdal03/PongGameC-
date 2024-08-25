#include <iostream>
#include "raylib.h"
#include "bin\bat.h"
#include "bin\ball.h"
#include "bin\scoreboard.h"
#include <cmath>

using namespace std;

const float screenWidth = 1000;
const float screenHeight = 600;
const float speed = 0.08;
float ballXspeed = 0.05;
float ballYspeed = 0.05;
bool playerwin = false;

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong Game");
    Bat tennisBatLeft(5.0f, screenHeight / 2, speed, 30.0f, 150.0f, BLACK);
    Bat tennisBatRight(965.0f, screenHeight / 2, speed, 30.0f, 150.0f, BLACK);
    Ball PongBall(screenWidth/2, screenHeight/2,ballXspeed,ballYspeed, 15, BLACK);
    Scoreboard Scoreboard;

            // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (!playerwin)
        {
            float distance = sqrt((PongBall.getBallX() - 30.0f) * (PongBall.getBallX() - 30.0f) + (PongBall.getBallY() - tennisBatLeft.getBatY()) * (PongBall.getBallY() - tennisBatLeft.getBatY()));
            // Start drawing
            BeginDrawing();

            // Clear the background with a color
            ClearBackground(RAYWHITE);

            tennisBatLeft.draw_bat();
            tennisBatRight.draw_bat();
            PongBall.draw_ball();
            Scoreboard.drawScore();

            if (IsKeyDown(KEY_W) && tennisBatLeft.getBatY() > 0)
                tennisBatLeft.move_bat_up();
            if (IsKeyDown(KEY_S) && tennisBatLeft.getBatY() + 150 < screenHeight)
                tennisBatLeft.move_bat_down();
            if (IsKeyDown(KEY_UP) && tennisBatRight.getBatY() > 0)
                tennisBatRight.move_bat_up();
            if (IsKeyDown(KEY_DOWN) && tennisBatRight.getBatY() + 150 < screenHeight)
                tennisBatRight.move_bat_down();


            if (PongBall.getBallY() + 15 > screenHeight || PongBall.getBallY() + 15 < 40)
            {
                PongBall.ybounce();
            }

            if (PongBall.getBallX() - 15 <= 5.0f + 30 &&
                PongBall.getBallY() + 15 >= tennisBatLeft.getBatY() &&
                PongBall.getBallY() - 15 <= tennisBatLeft.getBatY() + 150)
            {
                PongBall.xbounce();
            }

            // Check for collision with the right bat
            if (PongBall.getBallX() + 15 >= 965.0f &&
                PongBall.getBallY() + 15 >= tennisBatRight.getBatY() &&
                PongBall.getBallY() - 15 <= tennisBatRight.getBatY() + 150)
            {
                PongBall.xbounce();
            }

            if (Scoreboard.getPlayer1score() == 10 )
            {
                std::cout << "Player 1 wins! " << std::endl;
                DrawText("Player 1 wins! ", 300, 500, 40, BLACK);
                playerwin = true;
            }
            else if (Scoreboard.getPlayer2score() == 10 )
            {
                std::cout << "Player 2 wins! " << std::endl;
                DrawText("Player 2 wins! ", 300, 500, 40, BLACK);
                playerwin = true;
            }

            PongBall.ball_move();

            if (PongBall.getBallX() + 15 >= 970.0f)
            {
                Scoreboard.player1scores();
                PongBall.resetPosition(screenWidth / 2, screenHeight / 2);
                PongBall.resetSpeed(-ballXspeed,ballYspeed);


            }

            if (PongBall.getBallX() + 15 <= 0.0f)
            {
                Scoreboard.player2scores();
                PongBall.resetPosition(screenWidth / 2, screenHeight / 2);
                PongBall.resetSpeed(-ballXspeed,ballYspeed);

            }
                // End drawing
            EndDrawing();
        }

    }



    // De-initialize the window and close
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
