#include <stdio.h>
#include "graphics.h"

int main() {
    Canvas canvas;
    canvas_clear(&canvas);

    printf("--- Testing 2D Graphics Drawing Functions ---\n");

    // 1. Test Line
    printf("\nDrawing Line from (0,0) to (20,10):\n");
    canvas_draw_line(&canvas, 0, 0, 20, 10);

    // 2. Test Rectangle
    printf("Drawing Rectangle at (30,2), width=15, height=5:\n");
    canvas_draw_rectangle(&canvas, 30, 2, 15, 5);

    // 3. Test Circle
    printf("Drawing Circle centered at (15,13), radius=5:\n");
    canvas_draw_circle(&canvas, 15, 13, 5);

    // 4. Test Triangle
    printf("Drawing Triangle with vertices (45,10), (55,18), (35,18):\n");
    canvas_draw_triangle(&canvas, 45, 10, 55, 18, 35, 18);

    // 5. Test clipping (boundary checks)
    printf("Drawing Line partially outside canvas: from (-5, -5) to (5, 5):\n");
    canvas_draw_line(&canvas, -5, -5, 5, 5);

    // Display canvas
    canvas_display(&canvas);

    printf("--- Testing Completed ---\n");
    return 0;
}
