#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"

class TextZone
{
    public:
        TextZone(){}

        static void initLines(std::vector<std::string> lines)
        {
            TextZone::lines = lines;
        }

        void Render()
        {
            if(TextZone::isInstanced)
            {
                DrawRectangle(160, 360, 960, 320, WHITE);
                DrawRectangle(170, 370, 940, 300, BLACK);   
                
                if(IsKeyPressed(KEY_E) && canAdvance)
                {
                    if(index < lines.size() - 1)
                    {
                        index++;
                        canAdvance = false;
                        std::cout << index << std::endl;
                    }else
                    {
                        index = 0;
                        TextZone::isInstanced = false;
                        std::cout << "Should close textbox" << std::endl;
                    }
                }

                DrawText(lines.at(index).c_str(), 180, 380, 20, WHITE);

                if(IsKeyReleased(KEY_E))
                {
                    canAdvance = true;
                }
            }
        }

        inline static bool isInstanced;
    private:
        inline static std::vector<std::string> lines;
        int index = 0;
        bool canAdvance = true;
};