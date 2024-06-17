#pragma once


#include <iostream>
#include "raylib.h"

#include "SceneMainMenu.hpp"
#include "SimpleScene.hpp"
#include "../Scenes.hpp"

#include "../../Util/SceneManager.hpp"
#include "../../Util/GUIManager.hpp"
#include "../../GUI/Button.hpp"

class SceneMainMenu : public Scene
{
    public: 
        SceneMainMenu()
        {
            Quit = new Button("Quit", GetScreenWidth() / 2 - 150, GetScreenHeight() - 100);
            Credit = new Button("Credits", GetScreenWidth() / 2 - 150, GetScreenHeight() - 225);
            Option = new Button("Options", GetScreenWidth() / 2 - 150, GetScreenHeight() - 350);
            Play = new Button("Play", GetScreenWidth() / 2 - 150, GetScreenHeight() - 475);

            mainMenuMusic = LoadMusicStream("rescources/sounds/music/NightShade.mp3");
            PlayMusicStream(mainMenuMusic);
        }

        ~SceneMainMenu(){
            delete Quit;
            delete Credit;
            delete Option;
            delete Play;
        }

        static void ButtonQuit()
        {
            std::cout << "Button QUIT was pressed" << std::endl;

            GUIManager::ShouldClose = true;
        }

        static void _LoadScene()
        {
            SimpleScene *Walk;
            Walk = new SimpleScene();
            SceneManager::LoadScene(Walk);
        }

        static void EmptyFunctionTMP()
        {
            
        }

        void Render() override{
            UpdateMusicStream(mainMenuMusic);
            GUIManager::WriteText("Raylib test", 0, 40, 45, 1);

            DrawText("By SomeBoringNerd", 2, GetScreenHeight() - 22, 20, WHITE);

            DrawRectangle(GetScreenWidth() / 3, 90, GetScreenWidth() / 3, 2, BLACK);

            Quit->Render(ButtonQuit);
            Credit->Render(EmptyFunctionTMP);
            Option->Render(EmptyFunctionTMP);
            Play->Render(_LoadScene);
        };
    private:
        Music mainMenuMusic;
        Button *Quit, *Play, *Option, *Credit;
};
