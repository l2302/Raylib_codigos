#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Rotacion de una figura");
    SetTargetFPS(120);

    // Posicion de la figura
    Vector2 posicion = { 400, 250 };

    // Tamaño de la figura
    float tamaño = 100;

    // Angulo de rotacion
    float angulo = 0;

    // Velocidad de rotacion
    float velocidad = 100.0f;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Aplicar rotacion
        angulo += velocidad * deltaTime;

        // Reiniciar el angulo
        if (angulo >= 360)
        {
            angulo = 0;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        // Figura original
        DrawRectangle(
            posicion.x - tamaño / 2,
            posicion.y - tamaño / 2,
            tamaño,
            tamaño,
            LIGHTGRAY
        );

        // Figura rotada
        DrawRectanglePro(
            (Rectangle){
                posicion.x,
                posicion.y,
                tamaño,
                tamaño
            },
            (Vector2){
                tamaño / 2,
                tamaño / 2
            },
            angulo,
            SKYBLUE
        );

        // Titulo
        DrawText(
            "ROTACION",
            335,
            40,
            30,
            DARKBLUE
        );

        // Mostrar angulo
        DrawText(
            TextFormat("Angulo: %.0f grados", angulo),
            300,
            440,
            25,
            BLACK
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}