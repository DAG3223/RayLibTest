#pragma once

#include <iostream>

using namespace std;

#include "Player.hpp"
#include "../../GUI/TextZone.hpp"

class Tile
{
    public: 
        /// @brief Create a 16x16 tile on the map
        /// @param TexturePath path of the texture
        /// @param posX initial position of the tile on the X axis
        /// @param posY initial position of the tile on the Y axis
        /// @param layer Order of rendering (0 : first, 10 last)
        /// @param trigger determine if the tile is solid or execute code when the player goes into it
        Tile(string TexturePath, int posX, int posY, int layer)
        {
            this->TexturePath = TexturePath;
            this->posX = posX;
            this->posY = posY;

            // i'm sure 10 layers is already more than needed
            if(layer < 0) layer = 0;
            else if (layer > 10) layer = 10;

            this->layer = layer;
            this->trigger = false;
            string completePath = "rescources/textures/" + TexturePath + ".png";
            Image img = LoadImage(completePath.c_str());
            texture = LoadTextureFromImage(img);
        };

        Tile(string TexturePath, int posX, int posY, int layer, bool trigger)
        {
            this->TexturePath = TexturePath;
            this->posX = posX;
            this->posY = posY;

            // i'm sure 10 layers is already more than needed
            if(layer < 0) layer = 0;
            else if (layer > 10) layer = 10;

            this->layer = layer;
            this->trigger = trigger;
            string completePath = "rescources/textures/" + TexturePath + ".png";
            Image img = LoadImage(completePath.c_str());
            texture = LoadTextureFromImage(img);
        };

        Tile(string TexturePath, int posX, int posY, int layer, bool trigger, std::vector<std::string> lines)
        {
            this->TexturePath = TexturePath;
            this->posX = posX;
            this->posY = posY;
            this->lines = lines;

            // i'm sure 10 layers is already more than needed
            if(layer < 0) layer = 0;
            else if (layer > 10) layer = 10;

            this->layer = layer;
            this->trigger = trigger;
            string completePath = "rescources/textures/" + TexturePath + ".png";
            Image img = LoadImage(completePath.c_str());
            texture = LoadTextureFromImage(img);
            
        };

        virtual void Render(Player *player) 
        {
            if(isColliding(player))
            {   
                if(!this->trigger)
                {
                    if(IsKeyPressed(KEY_E) && !TextZone::isInstanced && lines.size() > 1)
                    {
                        TextZone::initLines(lines);
                        TextZone::isInstanced = true;
                    }
                }else
                {
                    player->Revert();
                }
            }

            DrawTexture(texture, posX, posY, WHITE);
        };

        virtual void OnCollisionEnter() {};

        int isColliding(Player *player)
        {
            Rectangle playerBox = {player->getX(), player->getY(), 30, 30};
            Rectangle TileBox = {posX, posY, 40, 40};

            return CheckCollisionRecs(playerBox, TileBox);
        }

        int getLayer(){
            return layer;
        }

    private:
        vector<string> lines;
        Texture2D texture;
        string TexturePath;
        int posX, posY, layer;
        bool trigger, keepRenderTextBox;
};