#include "main.h"

#define TOWER_MAX_COUNT 400
#define TOWER_TYPE_NONE 0
#define TOWER_TYPE_BASE 1
#define TOWER_TYPE_GUN 2

typedef struct Tower {
    int16_t x, y;
    uint8_t towerType;
} Tower;

int main(void)
{
    int screenWidth, screenHeight;
    GetPreferredSize(&screenWidth, &screenHeight);
    InitWindow(screenWidth, screenHeight, "Tower defense");
    SetTargetFPS(30);

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 5.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 0.0f, -1.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        if (IsPaused()) {
            // canvas is not visible in browser - do nothing
            continue;
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);

        BeginMode3D(camera);
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText("Hello Tower Defense 3D Tetst", 5, 5, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}