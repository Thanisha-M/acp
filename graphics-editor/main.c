#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.h"

// Robust integer input scanner to handle invalid lines or bounds
int get_int_input(const char *prompt, int min_val, int max_val) {
    int val;
    char buffer[128];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }
        char *endptr;
        val = (int)strtol(buffer, &endptr, 10);
        // Check if no digits were parsed or if there are non-newline trailing chars
        if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
            printf("Invalid format. Please enter a valid integer.\n");
            continue;
        }
        if (val < min_val || val > max_val) {
            printf("Input out of range (%d to %d). Try again.\n", min_val, max_val);
            continue;
        }
        return val;
    }
}

// Print the list of currently active shapes
void print_shapes(const Shape *shapes, int num_shapes) {
    printf("\n=== Active Shapes ===\n");
    if (num_shapes == 0) {
        printf("(No shapes currently in the editor)\n");
    } else {
        for (int i = 0; i < num_shapes; i++) {
            printf("[%d] ", i + 1);
            switch (shapes[i].type) {
                case SHAPE_LINE:
                    printf("Line: from (%d, %d) to (%d, %d)\n",
                           shapes[i].data.line.start.x, shapes[i].data.line.start.y,
                           shapes[i].data.line.end.x, shapes[i].data.line.end.y);
                    break;
                case SHAPE_RECTANGLE:
                    printf("Rectangle: top-left (%d, %d), width %d, height %d\n",
                           shapes[i].data.rect.topLeft.x, shapes[i].data.rect.topLeft.y,
                           shapes[i].data.rect.width, shapes[i].data.rect.height);
                    break;
                case SHAPE_CIRCLE:
                    printf("Circle: center (%d, %d), radius %d\n",
                           shapes[i].data.circle.center.x, shapes[i].data.circle.center.y,
                           shapes[i].data.circle.radius);
                    break;
                case SHAPE_TRIANGLE:
                    printf("Triangle: vertices (%d, %d), (%d, %d), (%d, %d)\n",
                           shapes[i].data.tri.p1.x, shapes[i].data.tri.p1.y,
                           shapes[i].data.tri.p2.x, shapes[i].data.tri.p2.y,
                           shapes[i].data.tri.p3.x, shapes[i].data.tri.p3.y);
                    break;
            }
        }
    }
    printf("=====================\n");
}

// Delete shape at index (0-based) by shifting remaining elements
void delete_shape(Shape *shapes, int *num_shapes, int idx) {
    for (int i = idx; i < *num_shapes - 1; i++) {
        shapes[i] = shapes[i + 1];
    }
    (*num_shapes)--;
}

// Prompt and fill shape data structures
void input_shape_data(ShapeType type, Shape *shape) {
    shape->type = type;
    printf("\n--- Enter Coordinates (Canvas bounds: X [0 to %d], Y [0 to %d]) ---\n", WIDTH - 1, HEIGHT - 1);
    if (type == SHAPE_LINE) {
        printf("Start Point:\n");
        shape->data.line.start.x = get_int_input("  x: ", -999, 999);
        shape->data.line.start.y = get_int_input("  y: ", -999, 999);
        printf("End Point:\n");
        shape->data.line.end.x = get_int_input("  x: ", -999, 999);
        shape->data.line.end.y = get_int_input("  y: ", -999, 999);
    } else if (type == SHAPE_RECTANGLE) {
        printf("Top-Left Corner:\n");
        shape->data.rect.topLeft.x = get_int_input("  x: ", -999, 999);
        shape->data.rect.topLeft.y = get_int_input("  y: ", -999, 999);
        shape->data.rect.width = get_int_input("Width (>=1): ", 1, 999);
        shape->data.rect.height = get_int_input("Height (>=1): ", 1, 999);
    } else if (type == SHAPE_CIRCLE) {
        printf("Center Point:\n");
        shape->data.circle.center.x = get_int_input("  x: ", -999, 999);
        shape->data.circle.center.y = get_int_input("  y: ", -999, 999);
        shape->data.circle.radius = get_int_input("Radius (>=0): ", 0, 999);
    } else if (type == SHAPE_TRIANGLE) {
        printf("Vertex 1:\n");
        shape->data.tri.p1.x = get_int_input("  x: ", -999, 999);
        shape->data.tri.p1.y = get_int_input("  y: ", -999, 999);
        printf("Vertex 2:\n");
        shape->data.tri.p2.x = get_int_input("  x: ", -999, 999);
        shape->data.tri.p2.y = get_int_input("  y: ", -999, 999);
        printf("Vertex 3:\n");
        shape->data.tri.p3.x = get_int_input("  x: ", -999, 999);
        shape->data.tri.p3.y = get_int_input("  y: ", -999, 999);
    }
}

int main() {
    Canvas canvas;
    Shape shapes[MAX_SHAPES];
    int num_shapes = 0;

    printf("==========================================\n");
    printf("     Welcome to the 2D Graphics Editor\n");
    printf("==========================================\n");

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Add Object\n");
        printf("2. Modify Object\n");
        printf("3. Delete Object\n");
        printf("4. Display Picture\n");
        printf("5. Exit\n");

        int choice = get_int_input("Choose an option: ", 1, 5);
        if (choice == 5) {
            printf("Exiting Graphics Editor. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: { // Add
                if (num_shapes >= MAX_SHAPES) {
                    printf("Canvas is full! Delete some objects first.\n");
                    break;
                }
                printf("\nSelect Shape Type:\n");
                printf("1. Line\n");
                printf("2. Rectangle\n");
                printf("3. Circle\n");
                printf("4. Triangle\n");
                int type_choice = get_int_input("Choose shape: ", 1, 4);

                ShapeType type;
                if (type_choice == 1) type = SHAPE_LINE;
                else if (type_choice == 2) type = SHAPE_RECTANGLE;
                else if (type_choice == 3) type = SHAPE_CIRCLE;
                else type = SHAPE_TRIANGLE;

                Shape new_shape;
                new_shape.id = num_shapes + 1; // logical temp ID
                input_shape_data(type, &new_shape);

                shapes[num_shapes] = new_shape;
                num_shapes++;
                printf("Object added successfully!\n");
                break;
            }
            case 2: { // Modify
                if (num_shapes == 0) {
                    printf("No active shapes to modify.\n");
                    break;
                }
                print_shapes(shapes, num_shapes);
                int modify_idx = get_int_input("Enter the index of the shape to modify: ", 1, num_shapes) - 1;

                printf("Modifying shape [%d]...\n", modify_idx + 1);
                // Keep the same shape type, just prompt for new coordinates/dimensions
                input_shape_data(shapes[modify_idx].type, &shapes[modify_idx]);
                printf("Object modified successfully!\n");
                break;
            }
            case 3: { // Delete
                if (num_shapes == 0) {
                    printf("No active shapes to delete.\n");
                    break;
                }
                print_shapes(shapes, num_shapes);
                int delete_idx = get_int_input("Enter the index of the shape to delete: ", 1, num_shapes) - 1;

                delete_shape(shapes, &num_shapes, delete_idx);
                printf("Object deleted successfully!\n");
                break;
            }
            case 4: { // Display
                canvas_render(&canvas, shapes, num_shapes);
                printf("\nRendering 2D Picture Canvas (%dx%d):\n", WIDTH, HEIGHT);
                canvas_display(&canvas);
                break;
            }
        }
    }

    return 0;
}
