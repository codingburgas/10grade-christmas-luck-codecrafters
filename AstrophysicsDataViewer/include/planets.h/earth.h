#pragma once
#include "./precompile.h"

class Earth {
public:
    void earthTextures();
    void displayEarth();
    void buttonHandler();
    bool isBackClicked = false;

private:
    Texture2D earth;
    Camera3D camera;
    Rectangle backRect = { 1700, 950, 200, 60 };
    Font buttonFont;
};
