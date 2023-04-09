#pragma once

#include "../BasicBehaviour.hpp"

class Player : public BasicBehaviour
{
    public:
        Player(int x, int y);
        ~Player();
        void Revert();
        int getX();
        int getY();
};