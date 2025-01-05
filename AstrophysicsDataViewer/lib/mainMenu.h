#pragma once
#include "precompile.h"

class MainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler();
    void updateBackground();
    bool isStartButtonPressed = false;

private:
    Font titleFont;
    Font buttonsFont;

    Texture2D Logo;
    Texture2D sun;


    Rectangle startButtonRect = { 780, 550, 290, 60 }; //Position and size for start button
    Rectangle quitButtonRect = { 780, 650, 290, 60 }; //Position and size for quit button

    std::vector<Vector2> stars;
    std::vector<float> speed;
};
