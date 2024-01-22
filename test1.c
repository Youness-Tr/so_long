#include <mlx.h>

int main()
{
    void *mlx_ptr;            // MLX pointer
    void *win_ptr;            // Window pointer
    void *img_ptr;            // Image pointer
    int width = 800;          // Window width
    int height = 600;         // Window height

    mlx_ptr = mlx_init();     // Initialize MLX
    win_ptr = mlx_new_window(mlx_ptr, width, height, "MLX Window");  // Create a new window

    // Create an image with the desired width and height
    img_ptr = mlx_new_image(mlx_ptr, width, height);

    // Get the image data address
	int *bit = 1;
	int *size = 10;
	int *end = 2;

    char *img_data = mlx_get_data_addr(img_ptr, &bit, &size, &end);

    // Set the background color (in this example, we'll use white)
    int background_color = 0x00FFFFFF;  // White color in hexadecimal (RGB format)

    // Fill the image data with the background color
    int pixel;
    for (int i = 0; i < width * height; i++) {
        pixel = (background_color & 0xFF0000) >> 16;   // Red component
        img_data[i * 4] = pixel;
        pixel = (background_color & 0x00FF00) >> 8;    // Green component
        img_data[i * 4 + 1] = pixel;
        pixel = background_color & 0x0000FF;           // Blue component
        img_data[i * 4 + 2] = pixel;
        img_data[i * 4 + 3] = 0;                        // Alpha component (0 for fully opaque)
    }

    // Put the image to the window (this will act as the background)
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    mlx_loop(mlx_ptr);        // Start the MLX event loop

    return 0;
}