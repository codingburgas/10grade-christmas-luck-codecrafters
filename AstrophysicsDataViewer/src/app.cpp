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
            pages.isInCredits = false;
            solarSystem.solarSystemTextures();

            mainMenu.isStartButtonPressed = false; // Reset the button statement
        }
    }
    if (mainMenu.isCreditsButtonPressed)
    {
        if (!pages.isInCredits)
        {
            pages.isInSolarSystem = false;
            pages.isInMainMenu = false;
            pages.isInCredits = true;
            credits.CreditsTextures();

            mainMenu.isCreditsButtonPressed = false;
        }
    }
    if (credits.IsBackButtonPressed) {
        if (!pages.isInMainMenu) {
            pages.isInSolarSystem = false;
            pages.isInMainMenu = true;
            pages.isInCredits = false;
            mainMenu.mainMenuTextures();

            credits.IsBackButtonPressed = false;
        }
    }
}

void App::display() {
    BeginDrawing();
    ClearBackground(background);

    if(pages.isInMainMenu)
    {
        mainMenu.displayMainMenu();
        mainMenu.updateBackground();
        mainMenu.buttonHandler();
    }
    if(pages.isInSolarSystem)
    {
        solarSystem.draw();
        solarSystem.update();
    }
    if (pages.isInCredits)
    {
        credits.displayCreditsMenu();
        credits.updateBackground();
        credits.buttonHandler();
    }

    EndDrawing();
}

void App::textures() {
    mainMenu.mainMenuTextures();
    solarSystem.solarSystemTextures();
    credits.CreditsTextures();
}