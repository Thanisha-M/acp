#ifndef GRAPHICS_H
#define GRAPHICS_H

#define WIDTH 60
#define HEIGHT 20
#define MAX_SHAPES 100

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    SHAPE_LINE,
    SHAPE_RECTANGLE,
    SHAPE_CIRCLE,
    SHAPE_TRIANGLE
} ShapeType;

typedef struct {
    Point start;
    Point end;
} Line;

typedef struct {
    Point topLeft;
    int width;
    int height;
} Rectangle;

typedef struct {
    Point center;
    int radius;
} Circle;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
} Triangle;

typedef struct {
    int id;
    ShapeType type;
    union {
        Line line;
        Rectangle rect;
        Circle circle;
        Triangle tri;
    } data;
} Shape;

typedef struct {
    char grid[HEIGHT][WIDTH];
} Canvas;

// Function prototypes
void canvas_clear(Canvas *canvas);
void canvas_draw_point(Canvas *canvas, int x, int y);
void canvas_draw_line(Canvas *canvas, int x1, int y1, int x2, int y2);
void canvas_draw_circle(Canvas *canvas, int cx, int cy, int radius);
void canvas_draw_rectangle(Canvas *canvas, int x, int y, int w, int h);
void canvas_draw_triangle(Canvas *canvas, int x1, int y1, int x2, int y2, int x3, int y3);
void canvas_render(Canvas *canvas, const Shape *shapes, int num_shapes);
void canvas_display(const Canvas *canvas);

#endif // GRAPHICS_H
