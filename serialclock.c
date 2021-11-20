#include "raylib.h"
#include "time.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int numBars = 3;

    const int screenWidth = 800;
    const int screenHeight = 450;

    const int padding = 20;
    const int topMargin = 20;
    const int barDistance = 20;
    const int maxBarWidth = screenWidth - (padding * 2);
    const int barHeight = (screenHeight - topMargin - (padding * 2) - (barDistance * (numBars-1))) / numBars;

    const int hourX = padding;
    const int hourY = padding + topMargin;

    const int minuteX = padding;
    const int minuteY = padding + barHeight + barDistance + topMargin;

    const int secondX = padding;
    const int secondY = padding + barHeight + barDistance + barHeight + barDistance + topMargin;

    int hourWidth = 0;
    int minuteWidth = 0;
    int secondWidth = 0;
    char buffer[9];
    const int lineTop = topMargin + padding/2;
    const int lineBottom = screenHeight - padding/2;
    const int line1X = ((maxBarWidth - padding) * 0.25) + padding;
    const int line2X = screenWidth/2;
    const int line3X = ((maxBarWidth - padding) * 0.75) + padding;

    InitWindow(screenWidth, screenHeight, "Linear clock");

    SetTargetFPS(2);
    //--------------------------------------------------------------------------------------

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        strftime(buffer, 9, "%H:%M:%S", tm_struct);
        hourWidth = tm_struct->tm_hour * (maxBarWidth / 24);
        minuteWidth = tm_struct->tm_min * (maxBarWidth / 60);
        secondWidth = tm_struct->tm_sec * (maxBarWidth / 60);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawLine(line1X, lineTop, line1X, lineBottom, LIGHTGRAY);
            DrawLine(line2X, lineTop, line2X, lineBottom, DARKGRAY);
            DrawLine(line3X, lineTop, line3X, lineBottom, LIGHTGRAY);

            DrawLine(screenWidth/2, topMargin + padding/2, screenWidth/2, (screenHeight - padding/2), GRAY);

            DrawRectangle(hourX, hourY, hourWidth, barHeight, RED);
            DrawRectangle(minuteX, minuteY, minuteWidth, barHeight, GREEN);
            DrawRectangle(secondX, secondY, secondWidth, barHeight, BLUE);

            DrawText(buffer, padding, 10, 20, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
