#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED
#include "raylib.h"
class Scoreboard
{
    private:
        int player1score = 0;
        int player2score = 0;


    public:
        void drawScore()
        {
            DrawText(TextFormat("Player 1: %d", player1score), 10, 10, 20, BLACK);
            DrawText(TextFormat("Player 2: %d", player2score), 880, 10, 20, BLACK);
        }
        void player1scores()
        {
            player1score += 1;
        }

        void player2scores()
        {
            player2score += 1;
        }

        int getPlayer1score()
        {
            return player1score;
        }

        int getPlayer2score()
        {
            return player2score;
        }



};

#endif // SCOREBOARD_H_INCLUDED
