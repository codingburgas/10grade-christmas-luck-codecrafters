#include "mainMenu.h"

void MainMenu::mainMenuTextures() {

    titleFont = LoadFont("assets/fonts/Sixtyfour-Regular.ttf");
    buttonsFont = LoadFont("assets/fonts/BebasNeue-Regular.ttf");
    Logo = LoadTexture("assets/logo/no-background-logo.png");
    sun = LoadTexture("assets/planets/sun.png");

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
        DrawPixelV(star, WHITE);
    }

    DrawTextEx(titleFont, "Welcome to AstroPhysics", {200, 150 }, 40, 0.7, DARKBLUE);
    DrawTextEx(titleFont, "Data Viewer", { 1000, 230 }, 40, 0.7, DARKBLUE);

    DrawTexture(Logo, -80, 750, RAYWHITE);
    DrawTexture(sun, 1650, -200, RAYWHITE);

    DrawRectangleRounded(startButtonRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonsFont, "Start", { startButtonRect.x + 110, startButtonRect.y + 15 }, 36, 0.7, WHITE);

    DrawRectangleRounded(quitButtonRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonsFont, "Exit", { quitButtonRect.x + 110, quitButtonRect.y + 15 }, 36, 0.7, WHITE);

    DrawRectangleRounded(creditsButtonRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonsFont, "Credits", { creditsButtonRect.x + 110, creditsButtonRect.y + 15 }, 36, 0.7, WHITE);

}

void MainMenu::buttonHandler() {
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Start button pressed" << std::endl; // Check if start button is pressed
            isStartButtonPressed = true;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), creditsButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Credits button pressed" << std::endl; // Check if credits button is pressed
            isCreditsButtonPressed = true;
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), quitButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            EndDrawing();
            CloseWindow();
        }
    }
}
