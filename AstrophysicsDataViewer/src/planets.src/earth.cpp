#include "planets.h/earth.h"

void Earth::earthTextures() {

    earth = LoadTexture("assets/planets/earth.png");
    buttonFont = LoadFont("assets/fonts/BebasNeue-Regular.ttf");
}

void Earth::displayEarth() {

    DrawTextureEx(earth, { 690, 370 }, 0, 1.0f, RAYWHITE);
    DrawRectangleRounded(backRect, 0.3f, 10, DARKGRAY);
    DrawTextEx(buttonFont, "Back", { backRect.x + 80, backRect.y + 15 }, 36, 0.7, RAYWHITE);
    DrawTextEx(buttonFont, "Orbital Characteristics", { 100, 200 }, 39, 0.7, RAYWHITE);
    DrawTextEx(buttonFont, "Orbital Period: 365.25 days (1 year)\nOrbital Eccentricity: 0.0167 (almost circular)\nSemi-Major Axis: 149.6 million km (1 Astronomical Unit, AU)\nPerihelion (closest to the Sun): ~147.1 million km\nAphelion (farthest from the Sun): ~152.1 million km\nOrbital Velocity: Average ~29.78 km/s", { 100, 250 }, 30, 0.7, RAYWHITE);
    DrawTextEx(buttonFont, "Physical Properties", { 100, 550 }, 39, 0.7, RAYWHITE);
    DrawTextEx(buttonFont, "Equatorial Radius: 6,378.1 km\nPolar Radius: 6,356.8 km (Earth is an oblate spheroid)\nMean Radius: 6,371 km\nSurface Area: ~510.1 million km² - ~29.2% land, ~70.8% water\nMass: ~5.972 × 10²⁴ kg\nDensity: ~5,514 kg/m³ (densest planet in the Solar System)\nSurface Gravity: ~9.8 m/s²\nEscape Velocity: ~11.186 km/s", { 100, 600 }, 30, 0.7, RAYWHITE);
    DrawTextEx(buttonFont, "Atmospheric Composition", { 1300, 200 }, 39, 0.7, RAYWHITE);
    DrawTextEx(buttonFont, "Nitrogen (N₂): ~78%\nOxygen (O₂): ~21%\nArgon (Ar): ~0.93%\nCarbon Dioxide (CO₂): ~0.04%\nMean Atmospheric Pressure: ~101.3 kPa (at sea level)\nScale Height: ~8.5 km", { 1300, 250 }, 30, 0.7, RAYWHITE);

}

void Earth::buttonHandler() {
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    if (CheckCollisionPointRec(GetMousePosition(), backRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            std::cout << "Back button pressed" << std::endl;
            isBackClicked = true;
        }
    }
}
