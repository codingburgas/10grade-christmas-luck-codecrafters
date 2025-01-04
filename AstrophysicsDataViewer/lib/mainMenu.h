#pragma once
#include "precompile.h"

class MainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler();
    void updateBackground();

private:
    Font titleFont;
    Font buttonsFont;

    Texture2D Logo;


    Rectangle startButtonRect = { 200, 400, 280, 60 }; //Position and size for start button
    Rectangle quitButtonRect = { 200, 510, 280, 60 }; //Position and size for quit button

    std::vector<Vector2> stars;
    std::vector<float> speed;
};
