#pragma once
#include "precompile.h"
#include "mainMenu.h"

class DisplayRes {
public:
    int width = 1440;
    int height = 900;
};

class App {
public:
    App();
    void display();
    void update();
    void pageHandler();
    void textures();

    Color background = { 0, 0, 0, 255 };
    DisplayRes screen;
    MainMenu mainMenu;
};
