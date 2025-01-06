#pragma once
#include "credits.h"

class SolarSystem {
public:
    void solarSystemTextures();
    void update();
    void draw();
    void buttonHandler();
    bool isReturnPressed = false;

private:
    Font backFont;

    Texture2D sunTexture;
    Texture2D mercuryTexture;
    Texture2D venusTexture;
    Texture2D earthTexture;
    Texture2D moonTexture;
    Texture2D marsTexture;
    Texture2D jupiterTexture;
    Texture2D saturnTexture;
    Texture2D uranusTexture;
    Texture2D neptuneTexture;

    Vector2 sunPosition;
    Vector2 earthPosition;

    Rectangle backRect = { 1700, 950, 200, 60 };

    float mercuryAngle, venusAngle, earthAngle, marsAngle;
    float jupiterAngle, saturnAngle, uranusAngle, neptuneAngle;
    float moonAngle = 0.0f;

    float mercuryOrbitRadius, venusOrbitRadius, earthOrbitRadius, marsOrbitRadius;
    float jupiterOrbitRadius, saturnOrbitRadius, uranusOrbitRadius, neptuneOrbitRadius;
    float moonOrbitRadius = 40.0f;

    float mercurySpeed, venusSpeed, earthSpeed, marsSpeed;
    float jupiterSpeed, saturnSpeed, uranusSpeed, neptuneSpeed;
    float moonSpeed = 0.02f;
};
