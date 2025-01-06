#pragma once
#include "precompile.h"

class Credits {
public:
    void CreditsTextures();
    void displayCreditsMenu();
    void buttonHandler();
    void updateBackground();
    bool IsBackButtonPressed = false;

private:
    Font textFont;
    Font buttonFont;

    Texture2D Logo;
    Texture2D dev1;
    Texture2D dev2;
    Texture2D dev3;

    Rectangle backButtonRect = { 1700, 950, 200, 60 };

    std::vector<Vector2> stars;
    std::vector<float> speed;

    float slidingSpeed = 0.0f;
    float scrollSpeed = 150.0f;
    float scrollAcceleration = 0.0f;
};