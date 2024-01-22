#include <mlx.h>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100
#define TILE_SIZE 30

int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 5, 5, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void draw_rectangle(void *mlx_ptr, void *win_ptr, int x, int y, int width, int height, int color) {
    int i, j;
    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
        }
    }
}

void draw_map(void *mlx_ptr, void *win_ptr) {
    int x, y;
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            int tile_x = x * TILE_SIZE;
            int tile_y = y * TILE_SIZE;
            int color = map[x][y] == 1 ? 0x008000 : 0xFF00FF05; // Black for walls, white for empty space

            draw_rectangle(mlx_ptr, win_ptr, tile_x, tile_y, TILE_SIZE, TILE_SIZE, color);
        }
    }
}

int main() {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width = 800;          // Window width
    int height = 600;         // Window height


    // Create a new connection to the X server
    mlx_ptr = mlx_init();

    // Create a new window
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "starting");

    // Load the background image from an XPM file
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "/Users/ytarhoua/Desktop/so_long0/img1.xpm", &width, &height);

    // Put the image to the window at position (0, 0)
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    // Draw the map
    draw_map(mlx_ptr, win_ptr);

    // Handle events
    mlx_loop(mlx_ptr);

    return 0;
}
