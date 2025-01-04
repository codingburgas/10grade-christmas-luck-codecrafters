#include "app.h"

App::App() {

    InitWindow(screen.width, screen.height, "AstroPhysics Data Viewer");
    SetTargetFPS(60);

    update();
}

void App::update() {
    textures();

    while (!WindowShouldClose()) {
        display();
    }

    CloseWindow();
}

void App::display() {
    BeginDrawing();
    ClearBackground(background);

    mainMenu.displayMainMenu();
    mainMenu.buttonHandler();
    mainMenu.updateBackground();

    EndDrawing();
}

void App::textures() {
    mainMenu.mainMenuTextures();
}
