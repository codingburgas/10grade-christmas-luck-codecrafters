#pragma once
#include "precompile.h"

class MainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler();
    void updateBackground();
    bool isStartButtonPressed = false;
    bool isCreditsButtonPressed = false;
    bool isHovered = false;

private:
    Font titleFont;
    Font buttonsFont;

    Texture2D Logo;
    Texture2D sun;


    Rectangle startButtonRect = { 780, 530, 290, 60 }; // Position and size for start button
    Rectangle quitButtonRect = { 780, 750, 290, 60 }; // Position and size for quit button
    Rectangle creditsButtonRect = { 780, 640, 290, 60 }; // Position and size for credits button

    std::vector<Vector2> stars;
    std::vector<float> speed;
};
