#include "header/Player.hpp"
#include "../GUI/TextZone.hpp"
#include "raylib.h"

int x, y, prevX, prevY, speed;

int Player::getX(){return x;}
int Player::getY(){return y;}

Player::Player(int _x, int _y)
{
    x = _x;
    y = _y;

    speed = 10;
}

Player::~Player(){};

void Player::Revert()
{
    x = prevX;
    y = prevY;
}

void Player::BasicBehaviour::Update()
{
    prevX = x;
    prevY = y;
    if(!TextZone::isInstanced)
    {
        if(IsKeyDown(KEY_UP))
        {
            y -= speed;
        }else if(IsKeyDown(KEY_DOWN))
        {
            y += speed; 
        }
        if(IsKeyDown(KEY_LEFT))
        {
            x -= speed;
        }else if(IsKeyDown(KEY_RIGHT))
        {
            x += speed;
        }
    }


    DrawRectangle(x, y, 30, 30, BLACK);
    DrawRectangle(x + 5, y + 5, 20, 20, WHITE);
}