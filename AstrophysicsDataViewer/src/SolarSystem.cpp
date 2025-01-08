#include "solarSystem.h"

void SolarSystem::solarSystemTextures() {

    sunTexture = LoadTexture("assets/planets/sun.png");
    mercuryTexture = LoadTexture("assets/planets/mercury.png");
    venusTexture = LoadTexture("assets/planets/venus.png");
    earthTexture = LoadTexture("assets/planets/earth.png");
    moonTexture = LoadTexture("assets/planets/moon.png");
    marsTexture = LoadTexture("assets/planets/mars.png");
    jupiterTexture = LoadTexture("assets/planets/saturn.png");
    saturnTexture = LoadTexture("assets/planets/jupiter.png");
    uranusTexture = LoadTexture("assets/planets/uranus.png");
    neptuneTexture = LoadTexture("assets/planets/neptune.png");
    backFont = LoadFont("assets/fonts/BebasNeue-Regular.ttf");

    sunPosition = { 780, 550 };

    mercuryAngle = 0.0f;
    venusAngle = 0.0f;
    earthAngle = 0.0f;
    marsAngle = 0.0f;
    jupiterAngle = 0.0f;
    saturnAngle = 0.0f;
    uranusAngle = 0.0f;
    neptuneAngle = 0.0f;

    mercuryOrbitRadius = 70.0f;
    venusOrbitRadius = 110.0f;
    earthOrbitRadius = 160.0f;
    marsOrbitRadius = 210.0f;
    jupiterOrbitRadius = 270.0f;
    saturnOrbitRadius = 330.0f;
    uranusOrbitRadius = 390.0f;
    neptuneOrbitRadius = 450.0f;

    mercurySpeed = 0.01f;
    venusSpeed = 0.008f;
    earthSpeed = 0.006f;
    marsSpeed = 0.005f;
    jupiterSpeed = 0.003f;
    saturnSpeed = 0.002f;
    uranusSpeed = 0.0015f;
    neptuneSpeed = 0.001f;
}

void SolarSystem::update() {

    mercuryAngle += mercurySpeed;
    venusAngle += venusSpeed;
    earthAngle += earthSpeed;
    marsAngle += marsSpeed;
    jupiterAngle += jupiterSpeed;
    saturnAngle += saturnSpeed;
    uranusAngle += uranusSpeed;
    neptuneAngle += neptuneSpeed;
    moonAngle += moonSpeed;

    mercuryAngle = fmod(mercuryAngle, 2 * PI);
    venusAngle = fmod(venusAngle, 2 * PI);
    earthAngle = fmod(earthAngle, 2 * PI);
    marsAngle = fmod(marsAngle, 2 * PI);
    jupiterAngle = fmod(jupiterAngle, 2 * PI);
    saturnAngle = fmod(saturnAngle, 2 * PI);
    uranusAngle = fmod(uranusAngle, 2 * PI);
    neptuneAngle = fmod(neptuneAngle, 2 * PI);
    moonAngle = fmod(moonAngle, 2 * PI);
}

void SolarSystem::draw() {
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    ClearBackground(BLACK);



    float sunSize = 100.0f;
    float mercurySize = 14.0f;
    float venusSize = 20.0f;
    float earthSize = 24.0f;
    float moonSize = 10.0f;
    float marsSize = 18.0f;
    float jupiterSize = 50.0f;
    float saturnSize = 40.0f;
    float uranusSize = 30.0f;
    float neptuneSize = 30.0f;

    float sunScale = sunSize / sunTexture.width;
    float mercuryScale = mercurySize / mercuryTexture.width;
    float venusScale = venusSize / venusTexture.width;
    float earthScale = earthSize / earthTexture.width;
    float moonScale = moonSize / moonTexture.width;
    float marsScale = marsSize / marsTexture.width;
    float jupiterScale = jupiterSize / jupiterTexture.width;
    float saturnScale = saturnSize / saturnTexture.width;
    float uranusScale = uranusSize / uranusTexture.width;
    float neptuneScale = neptuneSize / neptuneTexture.width;


    DrawTextureEx(sunTexture, { sunPosition.x - sunSize / 2, sunPosition.y - sunSize / 2 }, 0.0f, sunScale, WHITE);

    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, mercuryOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, venusOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, earthOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, marsOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, jupiterOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, saturnOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, uranusOrbitRadius, GRAY);
    DrawCircleLines((int)sunPosition.x, (int)sunPosition.y, neptuneOrbitRadius, GRAY);

    Vector2 earthPosition = { sunPosition.x + earthOrbitRadius * cos(earthAngle), sunPosition.y + earthOrbitRadius * sin(earthAngle) };
    DrawTextureEx(earthTexture,
        { earthPosition.x - earthSize / 2, earthPosition.y - earthSize / 2 },
        0.0f, earthScale, WHITE);

    Vector2 moonPosition = { earthPosition.x + moonOrbitRadius * cos(moonAngle) - moonSize / 2,
                             earthPosition.y + moonOrbitRadius * sin(moonAngle) - moonSize / 2 };

    DrawTextureEx(moonTexture, moonPosition, 0.0f, moonScale, WHITE);

    DrawTextureEx(mercuryTexture,
        { sunPosition.x + mercuryOrbitRadius * cos(mercuryAngle) - mercurySize / 2,
          sunPosition.y + mercuryOrbitRadius * sin(mercuryAngle) - mercurySize / 2 },
        0.0f, mercuryScale, WHITE);

    DrawTextureEx(venusTexture,
        { sunPosition.x + venusOrbitRadius * cos(venusAngle) - venusSize / 2,
          sunPosition.y + venusOrbitRadius * sin(venusAngle) - venusSize / 2 },
        0.0f, venusScale, WHITE);

    DrawTextureEx(marsTexture,
        { sunPosition.x + marsOrbitRadius * cos(marsAngle) - marsSize / 2,
          sunPosition.y + marsOrbitRadius * sin(marsAngle) - marsSize / 2 },
        0.0f, marsScale, WHITE);

    DrawTextureEx(jupiterTexture,
        { sunPosition.x + jupiterOrbitRadius * cos(jupiterAngle) - jupiterSize / 2,
          sunPosition.y + jupiterOrbitRadius * sin(jupiterAngle) - jupiterSize / 2 },
        0.0f, jupiterScale, WHITE);

    DrawTextureEx(saturnTexture,
        { sunPosition.x + saturnOrbitRadius * cos(saturnAngle) - saturnSize / 2,
          sunPosition.y + saturnOrbitRadius * sin(saturnAngle) - saturnSize / 2 },
        0.0f, saturnScale, WHITE);

    DrawTextureEx(uranusTexture,
        { sunPosition.x + uranusOrbitRadius * cos(uranusAngle) - uranusSize / 2,
          sunPosition.y + uranusOrbitRadius * sin(uranusAngle) - uranusSize / 2 },
        0.0f, uranusScale, WHITE);

    DrawTextureEx(neptuneTexture,
        { sunPosition.x + neptuneOrbitRadius * cos(neptuneAngle) - neptuneSize / 2,
          sunPosition.y + neptuneOrbitRadius * sin(neptuneAngle) - neptuneSize / 2 },
        0.0f, neptuneScale, WHITE);

    DrawRectangleRounded(backRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(backFont, "Back", { backRect.x + 80, backRect.y + 15 }, 36, 0.7, WHITE);
}

void SolarSystem::buttonHandler() {
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    if (CheckCollisionPointRec(GetMousePosition(), backRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Back button pressed" << std::endl; // Check if back button is pressed
            isReturnPressed = true;
        }
    }
}