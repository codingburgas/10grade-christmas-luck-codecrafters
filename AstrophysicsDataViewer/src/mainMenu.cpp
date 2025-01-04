#include "mainMenu.h"
#include "precompile.h"

void MainMenu::mainMenuTextures() {

    titleFont = LoadFont("fonts/Sixtyfour-Regular.ttf");
    buttonsFont = LoadFont("fonts/BebasNeue-Regular.ttf");
    Logo = LoadTexture("assets/logo/no-background-logo.png");

    const int starCount = 100;
    stars.resize(starCount);
    speed.resize(starCount);

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    for (int i = 0; i < starCount; i++)
    {
        stars[i] = { (float)(rand() % screenWidth), (float)(rand() % screenHeight) }; // Explicit cast
        speed[i] = 1.0f + (rand() % 3);
    }
}

void MainMenu::updateBackground() {
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();

    for (size_t i = 0; i < stars.size(); i++)
    {
        stars[i].y += speed[i];

        if (stars[i].y > screenHeight) {
            stars[i].y = 0;
            stars[i].x = (float)(rand() % screenWidth);
        }
    }
}

void MainMenu::displayMainMenu() {

    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();

    for (const auto& star : stars) // range-based for loop
    {
        DrawCircleV(star, 2.0f, WHITE);
    }

    DrawTextEx(titleFont, "Welcome to AstroPhysics", {140, 150 }, 40, 0.7, DARKBLUE);
    DrawTextEx(titleFont, "Data Viewer", { 810, 230 }, 40, 0.7, DARKBLUE);

    DrawTexture(Logo, 650, 300, RAYWHITE);

    DrawRectangleRounded(startButtonRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonsFont, "Start", { startButtonRect.x + 100, startButtonRect.y + 15 }, 36, 0.7, WHITE);

    DrawRectangleRounded(quitButtonRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonsFont, "Quit", { quitButtonRect.x + 100, quitButtonRect.y + 15 }, 36, 0.7, WHITE);

}

void MainMenu::buttonHandler() {
    if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Start button pressed" << std::endl; // Check if the button is pressed
        }
    }
    else
    {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }

    if (CheckCollisionPointRec(GetMousePosition(), quitButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            CloseWindow();
        }
    }
}
