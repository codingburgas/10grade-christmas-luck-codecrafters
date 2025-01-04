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
    EndDrawing();
}

void App::textures() {
    mainMenu.mainMenuTextures();
}
