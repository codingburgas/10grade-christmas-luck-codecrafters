#pragma once
#include "mainMenu.h"
#include "solarSystem.h"
#include "creditsPage.h"


class PageHandler {
public:
    bool isInMainMenu = true;
    bool isInSolarSystem = false;
    bool isInCredits = false;
};

class App {
public:
    App();
    void display();
    void update();
    void textures();
    void pageHandler();

    PageHandler pages;
    MainMenu mainMenu;
    Credits credits;
    SolarSystem solarSystem;

    Color background = { 0, 0, 0, 255 }; // Custom dark color for main menu's background
};
