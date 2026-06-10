#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"

// Clear canvas to '_'
void canvas_clear(Canvas *canvas) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas->grid[y][x] = '_';
        }
    }
}

// Safely draw a single point if inside canvas boundaries
void canvas_draw_point(Canvas *canvas, int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas->grid[y][x] = '*';
    }
}

// Bresenham's Line Algorithm
void canvas_draw_line(Canvas *canvas, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        canvas_draw_point(canvas, x1, y1);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Helper to draw symmetric points of a circle
static void draw_circle_points(Canvas *canvas, int cx, int cy, int x, int y) {
    canvas_draw_point(canvas, cx + x, cy + y);
    canvas_draw_point(canvas, cx - x, cy + y);
    canvas_draw_point(canvas, cx + x, cy - y);
    canvas_draw_point(canvas, cx - x, cy - y);
    canvas_draw_point(canvas, cx + y, cy + x);
    canvas_draw_point(canvas, cx - y, cy + x);
    canvas_draw_point(canvas, cx + y, cy - x);
    canvas_draw_point(canvas, cx - y, cy - x);
}

// Bresenham's/Midpoint Circle Drawing Algorithm
void canvas_draw_circle(Canvas *canvas, int cx, int cy, int radius) {
    if (radius < 0) {
        return;
    }
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    draw_circle_points(canvas, cx, cy, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        draw_circle_points(canvas, cx, cy, x, y);
    }
}

// Rectangle is drawn using four boundary lines
void canvas_draw_rectangle(Canvas *canvas, int x, int y, int w, int h) {
    if (w <= 0 || h <= 0) {
        return;
    }
    canvas_draw_line(canvas, x, y, x + w - 1, y);
    canvas_draw_line(canvas, x, y + h - 1, x + w - 1, y + h - 1);
    canvas_draw_line(canvas, x, y, x, y + h - 1);
    canvas_draw_line(canvas, x + w - 1, y, x + w - 1, y + h - 1);
}

// Triangle is drawn connecting three vertices with lines
void canvas_draw_triangle(Canvas *canvas, int x1, int y1, int x2, int y2, int x3, int y3) {
    canvas_draw_line(canvas, x1, y1, x2, y2);
    canvas_draw_line(canvas, x2, y2, x3, y3);
    canvas_draw_line(canvas, x3, y3, x1, y1);
}

// Clear grid and render all active shapes
void canvas_render(Canvas *canvas, const Shape *shapes, int num_shapes) {
    canvas_clear(canvas);
    for (int i = 0; i < num_shapes; i++) {
        switch (shapes[i].type) {
            case SHAPE_LINE:
                canvas_draw_line(canvas, 
                                 shapes[i].data.line.start.x, shapes[i].data.line.start.y,
                                 shapes[i].data.line.end.x, shapes[i].data.line.end.y);
                break;
            case SHAPE_RECTANGLE:
                canvas_draw_rectangle(canvas,
                                     shapes[i].data.rect.topLeft.x, shapes[i].data.rect.topLeft.y,
                                     shapes[i].data.rect.width, shapes[i].data.rect.height);
                break;
            case SHAPE_CIRCLE:
                canvas_draw_circle(canvas,
                                  shapes[i].data.circle.center.x, shapes[i].data.circle.center.y,
                                  shapes[i].data.circle.radius);
                break;
            case SHAPE_TRIANGLE:
                canvas_draw_triangle(canvas,
                                    shapes[i].data.tri.p1.x, shapes[i].data.tri.p1.y,
                                    shapes[i].data.tri.p2.x, shapes[i].data.tri.p2.y,
                                    shapes[i].data.tri.p3.x, shapes[i].data.tri.p3.y);
                break;
        }
    }
}

// Output canvas grid with border outline
void canvas_display(const Canvas *canvas) {
    printf("+");
    for (int x = 0; x < WIDTH; x++) {
        printf("-");
    }
    printf("+\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            putchar(canvas->grid[y][x]);
        }
        printf("|\n");
    }

    printf("+");
    for (int x = 0; x < WIDTH; x++) {
        printf("-");
    }
    printf("+\n");
}
