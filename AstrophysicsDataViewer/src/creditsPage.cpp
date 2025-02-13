#include "creditsPage.h"

void Credits::CreditsTextures() {
    textFont = LoadFont("assets/fonts/LilitaOne-Regular.ttf");
    buttonFont = LoadFont("assets/fonts/BebasNeue-Regular.ttf");
    Logo = LoadTexture("assets/logo/no-background-logo.png");
    dev1 = LoadTexture("assets/profile_pictures/Veselin.png");
    dev2 = LoadTexture("assets/profile_pictures/Dimitur.png");
    dev3 = LoadTexture("assets/profile_pictures/Panaiot.png");

    const int starCount = 100;
    stars.resize(starCount);
    speed.resize(starCount);

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    for (int i = 0; i < starCount; i++) {
        stars[i] = { (float)(rand() % screenWidth), (float)(rand() % screenHeight) }; // Explicit cast
        speed[i] = 1.0f + (rand() % 3);
    }

    slidingSpeed = screenHeight;
    scrollAcceleration = 0.0f;
}

void Credits::updateBackground() {
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();

    for (size_t i = 0; i < stars.size(); i++) {
        stars[i].y += speed[i];

        if (stars[i].y > screenHeight) {
            stars[i].y = 0;
            stars[i].x = (float)(rand() % screenWidth);
        }
    }
}

void Credits::displayCreditsMenu() {
    int screenHeight = GetScreenHeight();

    for (const auto& star : stars) {
        DrawPixelV(star, WHITE);
    }

    slidingSpeed -= scrollSpeed * GetFrameTime();

    float baseY = slidingSpeed;

    DrawTextEx(textFont, "Credits", { 880, baseY + 50 }, 70, 0.7, RAYWHITE);
    DrawTexture(Logo, 250, baseY + 1700, RAYWHITE);
    DrawTextureEx(dev1, { 200, baseY + 300 }, 0, 0.5, RAYWHITE);
    DrawTextEx(textFont, "Veselin Boyanov - Full-stack developer", { 150, baseY + 570 }, 25, 0.7, RAYWHITE);
    DrawTextEx(textFont, "Special thanks to Veselin Boyanov, our dedicated full-stack developer,\nfor his expertise and relentless effort in bringing this project to life. ", { 500, baseY + 400 }, 30, 1, RAYWHITE);

    DrawTextureEx(dev2, { 200, baseY + 800 }, 0, 0.5, RAYWHITE);
    DrawTextEx(textFont, "Dimitar Dimitrakov - Scrum Leader", { 150, baseY + 1070 }, 25, 0.7, RAYWHITE);
    DrawTextEx(textFont, "Dimitar has guided the team with strategic planning and ensured seamless collaboration \nthroughout the project.", { 500, baseY + 900 }, 30, 1, RAYWHITE);

    DrawTextureEx(dev3, { 200, baseY + 1300 }, 0, 0.15, RAYWHITE);
    DrawTextEx(textFont, "Panayot Andonov - Designer", { 150, baseY + 1570 }, 25, 0.7, RAYWHITE);
    DrawTextEx(textFont, "Panayot has given us one of the best designs, used for the app.", { 500, baseY + 1400 }, 30, 1, RAYWHITE);

    DrawTextEx(textFont, "Thank you for your time!\nOur team, CodeCrafters", { 800, baseY + 1850 }, 65, 1, RAYWHITE);

    DrawRectangleRounded(backButtonRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonFont, "Back", { backButtonRect.x + 80, backButtonRect.y + 15 }, 36, 0.7, WHITE);

    if (baseY < -2000) {
        slidingSpeed = screenHeight;
    }
}

void Credits::buttonHandler() {
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    if (CheckCollisionPointRec(GetMousePosition(), backButtonRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Back button pressed" << std::endl;
            IsBackButtonPressed = true;
        }
    }
}
