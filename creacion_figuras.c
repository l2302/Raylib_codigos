#include "raylib.h"

int main(void) {
    // Inicializar dimensiones de la ventana y la ventana misma
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Figuras Geometricas con Raylib");

    SetTargetFPS(60);

    // Bucle principal del juego/aplicación
    while (!WindowShouldClose()) {
        
        // --- DIBUJO ---
        BeginDrawing();
        
        // Color de fondo de la ventana
        ClearBackground(RAYWHITE);

        // Texto informativo en la parte superior
        DrawText("Ejemplo de Figuras Geometricas en Raylib", 180, 20, 20, DARKGRAY);

        // 1. Rectángulo relleno
        // DrawRectangle(posX, posY, ancho, alto, color)
        DrawRectangle(50, 100, 160, 100, BLUE);

        // 2. Círculo relleno
        // DrawCircle(centroX, centroY, radio, color)
        DrawCircle(360, 150, 60, RED);

        // 3. Línea recta
        // DrawLine(inicioX, inicioY, finX, finY, color)
        DrawLine(500, 100, 720, 200, GREEN);

        // 4. Triángulo (requiere 3 puntos definidos con vectores Vector2)
        Vector2 v1 = { 200, 450 };
        Vector2 v2 = { 100, 550 };
        Vector2 v3 = { 300, 550 };
        DrawTriangle(v1, v2, v3, ORANGE);

        // 5. Rectángulo con bordes (solo contorno, sin relleno)
        // DrawRectangleLines(posX, posY, ancho, alto, color)
        DrawRectangleLines(450, 350, 220, 140, PURPLE);

        EndDrawing();
    }

    // Cerrar ventana y liberar memoria al salir
    CloseWindow();

    return 0;
}