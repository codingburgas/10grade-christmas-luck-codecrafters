#include "mainMenu.h"

void MainMenu::mainMenuTextures() {
    titleFont = LoadFont("fonts/Sixtyfour-Regular.ttf");
    buttonsFont = LoadFont("fonts/BebasNeue-Regular.ttf");
    Logo = LoadTexture("assets/logo.png");
    //startButton = LoadTexture("assets/startButton.png");
    //quitButton = LoadTexture("assets/quitButton.png");
}

void MainMenu::displayMainMenu() {
    DrawTextEx(titleFont, "Welcome to AstroPhysics Data Viewer", { 280, 150 }, 48, 0.7, DARKBLUE);

    DrawTexture(Logo, 650, 360, RAYWHITE);

    DrawRectangleRec(startButtonRect, DARKGRAY);
    DrawTextEx(buttonsFont, "Start", { startButtonRect.x + 100, startButtonRect.y + 15 }, 36, 0.7, WHITE);

    DrawRectangleRec(quitButtonRect, DARKGRAY);
    DrawTextEx(buttonsFont, "Quit", { quitButtonRect.x + 100, quitButtonRect.y + 15 }, 36, 0.7, WHITE);
}

void MainMenu::buttonHandler() {
    if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Start Button Pressed!" << std::endl;
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), quitButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            CloseWindow();
        }
    }
}
