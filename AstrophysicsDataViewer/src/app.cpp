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
            pages.isInEarthView = false;
            credits.CreditsTextures();

            mainMenu.isCreditsButtonPressed = false;
        }
    }
    if (credits.IsBackButtonPressed) { // If the back button in credits is clicked then the program returns to the main menu
        if (!pages.isInMainMenu) {
            pages.isInSolarSystem = false;
            pages.isInMainMenu = true;
            pages.isInCredits = false;
            pages.isInEarthView = false;
            mainMenu.mainMenuTextures();

            credits.IsBackButtonPressed = false;
        }
    }
    if (solarSystem.isReturnPressed) { // If the back button in  Solar System is clicked then the program returns to the main menu
        if (!pages.isInMainMenu) {
            pages.isInSolarSystem = false;
            pages.isInMainMenu = true;
            pages.isInCredits = false;
            pages.isInEarthView = false;
            mainMenu.mainMenuTextures();

            solarSystem.isReturnPressed = false;
        }
    }
    if (solarSystem.isEarthClicked) {
        if (!pages.isInEarthView) {
            pages.isInSolarSystem = false;
            pages.isInMainMenu = false;
            pages.isInCredits = false;
            pages.isInEarthView = true;
            earth.earthTextures();

            solarSystem.isEarthClicked = false;
        }
    }
    if (earth.isBackClicked) {
        pages.isInSolarSystem = false;
        pages.isInMainMenu = true;
        pages.isInCredits = false;
        pages.isInEarthView = false;
        mainMenu.mainMenuTextures();

        earth.isBackClicked = false;
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
        solarSystem.buttonHandler();
    }
    if (pages.isInCredits)
    {
        credits.displayCreditsMenu();
        credits.updateBackground();
        credits.buttonHandler();
    }
    if (pages.isInEarthView)
    {
        earth.displayEarth();
        earth.buttonHandler();
    }

    EndDrawing();
}

void App::textures() {
    mainMenu.mainMenuTextures();
    solarSystem.solarSystemTextures();
    credits.CreditsTextures();
    earth.earthTextures();
}