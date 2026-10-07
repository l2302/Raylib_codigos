#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Traslacion de una figura");
    SetTargetFPS(120);

    // Posicion de la figura
    float posX = 100;
    float posY = 200;

    // Tamaño de la figura
    float tamaño = 100;

    // Velocidad de movimiento
    float velocidad = 150.0f;

    // Traslacion
    float Tx = 500;
    float Ty = 0;

    int moviendoDerecha = 1;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Movimiento de la figura
        if (moviendoDerecha == 1)
        {
            posX += velocidad * deltaTime;

            if (posX >= 100 + Tx)
            {
                posX = 100 + Tx;
                moviendoDerecha = 0;
            }
        }
        else
        {
            posX -= velocidad * deltaTime;

            if (posX <= 100)
            {
                posX = 100;
                moviendoDerecha = 1;
            }
        }

        BeginDrawing();

        ClearBackground(WHITE);

        // Figura original
        DrawRectangle(
            100,
            200,
            tamaño,
            tamaño,
            LIGHTGRAY
        );

        // Figura trasladada
        DrawRectangle(
            posX,
            posY,
            tamaño,
            tamaño,
            SKYBLUE
        );

        // Mostrar el desplazamiento
        DrawText(
            "TRASLACION",
            320,
            40,
            30,
            DARKBLUE
        );

        DrawText(
            TextFormat("Tx = %.0f", Tx),
            330,
            420,
            25,
            BLACK
        );

        DrawText(
            TextFormat("Ty = %.0f", Ty),
            330,
            450,
            25,
            BLACK
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}