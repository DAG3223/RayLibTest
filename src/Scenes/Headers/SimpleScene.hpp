#pragma once

#include <iostream>
#include "raylib.h"

#include "SceneMainMenu.hpp"
#include "SimpleScene.hpp"
#include "../Scenes.hpp"

#include "../../Entity/header/Player.hpp"
#include "../../Entity/header/Tile.hpp"

#include "../../Util/SceneManager.hpp"
#include "../../Util/GUIManager.hpp"
#include "../../GUI/Button.hpp"
#include "../../GUI/TextZone.hpp"

#include "vector"

class SimpleScene : public Scene
{
    public: 
        SimpleScene()
        {
            mainMenuMusic = LoadMusicStream("rescources/sounds/music/Underclocked.mp3");
            PlayMusicStream(mainMenuMusic);

            player = new Player(GetScreenWidth() / 2, GetScreenHeight() / 2);
            text = new TextZone();

            for(int x = 0; x < 1280; x += 40)
            {
                tileset.insert(tileset.begin(), new Tile("wall", x, 0, 0, true));
                tileset.insert(tileset.begin(), new Tile("wall", x, GetScreenHeight() - 40, 0, true));
            }

            for(int y = 0; y < 720; y += 40)
            {
                tileset.insert(tileset.begin(), new Tile("wall", GetScreenWidth() - 40, y, 0, true));
                tileset.insert(tileset.begin(), new Tile("wall", 0, y, 0, true));
            }

            for(int y = 0; y < 9; y++)
            {
                tileset.insert(tileset.begin(), new Tile("wall", GetScreenWidth() / 3 + (60 * y), GetScreenHeight()/3, y, false));
            }
        }

        void Render() override
        {
            UpdateMusicStream(mainMenuMusic);

            for(Tile *tile : tileset)
            {
                if(tile->getLayer() <= 5)
                {
                    tile->Render(player);
                }
            }
            // player is rendered between the layer 5 and 6
            player->Update();

            for(Tile *tile : tileset)
            {
                if(tile->getLayer() > 5)
                {
                    tile->Render(player);
                }
            }

            if(TextZone::isInstanced)
            {
                text->Render();
            }
        };
    private:
        Music mainMenuMusic;
        Player *player;
        TextZone *text;
        vector<Tile*> tileset {new Tile("void", 1280 / 2, 720 / 2, 5, false, {"", "test", "textbox", "there is 4 entry", "within that box"})};
};