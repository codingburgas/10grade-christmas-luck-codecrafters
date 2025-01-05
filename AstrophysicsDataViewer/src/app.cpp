#include "app.h"

App::App() {
    InitWindow(1920, 1080, "AstroPhysics Data Viewer");
    SetTargetFPS(60);

    update();
}

void App::update() {
    textures();

    while (!WindowShouldClose()) {
        pageHandler();
        display();
    }

    CloseWindow();
}

void App::pageHandler() {
    if (mainMenu.isStartButtonPressed) {
        if (!pages.isInSolarSystem) { 
            pages.isInSolarSystem = true;
            pages.isInMainMenu = false;
            solarSystem.solarSystemTextures();
        }
    }

    if (IsKeyPressed(KEY_ESCAPE) && pages.isInSolarSystem) {
        if (!pages.isInMainMenu)
        {
            pages.isInMainMenu = true;
            pages.isInSolarSystem = false;
            mainMenu.mainMenuTextures();
        }
    }
}

void App::display() {
    BeginDrawing();
    ClearBackground(background);

    if (pages.isInMainMenu)
    {
        mainMenu.displayMainMenu();
        mainMenu.buttonHandler();
        mainMenu.updateBackground();
    }
    if (pages.isInSolarSystem)
    {
        solarSystem.draw();
        solarSystem.update();
    }

    EndDrawing();
}

void App::textures() {
    mainMenu.mainMenuTextures();
    solarSystem.solarSystemTextures();
}