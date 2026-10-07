#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Escalacion de una figura");
    SetTargetFPS(120);

    float escala = 1.0f;
    float velocidad = 0.5f;

    int creciendo = 1;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Aumentar o disminuir la escala
        if (creciendo == 1)
        {
            escala += velocidad * deltaTime;

            if (escala >= 3.0f)
            {
                escala = 3.0f;
                creciendo = 0;
            }
        }
        else
        {
            escala -= velocidad * deltaTime;

            if (escala <= 1.0f)
            {
                escala = 1.0f;
                creciendo = 1;
            }
        }

        // Tamaño de la figura
        float tamaño = 100 * escala;

        // Centrar la figura
        float posX = screenWidth / 2 - tamaño / 2;
        float posY = screenHeight / 2 - tamaño / 2;

        BeginDrawing();

        ClearBackground(WHITE);

        // Figura escalada
        DrawRectangle(
            posX,
            posY,
            tamaño,
            tamaño,
            SKYBLUE
        );

        // Mostrar escala
        DrawText(
            "ESCALACION",
            320,
            40,
            30,
            DARKBLUE
        );

        DrawText(
            TextFormat("Escala: %.1f", escala),
            340,
            440,
            25,
            BLACK
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}