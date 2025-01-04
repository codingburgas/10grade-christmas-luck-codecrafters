#pragma once
#include "precompile.h"

class MainMenu {
public:
    void mainMenuTextures();
    void displayMainMenu();
    void buttonHandler();

private:
    Font titleFont;
    Font buttonsFont;

    Texture2D Logo;
    Texture2D startButton;
    Texture2D quitButton;

    Rectangle startButtonRect = { 150, 400, 300, 60 };
    Rectangle quitButtonRect = { 150, 550, 300, 60 };
};
