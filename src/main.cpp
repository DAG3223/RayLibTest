#include "raylib.h"

#include "Util/SceneManager.hpp"

#include "Scenes/Headers/SceneMainMenu.hpp"
#include "Scenes/Scenes.hpp"


#include "Util/GUIManager.hpp"
#define DEBUG_MODE 1

const int screenWidth = 1280;
const int screenHeight = 720;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Game Test");
    InitAudioDevice();
    SetTargetFPS(60);
    SetExitKey(0);

    SceneMainMenu *menu = new SceneMainMenu();

    SceneManager::LoadScene(menu);

    while (!GUIManager::ShouldClose)
    {
        BeginDrawing();

            ClearBackground(DARKGRAY);

            if(SceneManager::SceneLoaded())
            {
                SceneManager::Update();
            }

            if(WindowShouldClose())
            {
                GUIManager::ShouldClose = true;
            }

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

