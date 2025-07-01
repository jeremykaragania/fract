#include <mandelbrot.h>

void draw_mandelbrot() {
  set_plane_x(-2, 0.47);
  set_plane_y(-1.12, 1.12);

  size_t max_iterations = 8;
  struct plane_point pp;
  struct screen_point sp;
  struct plane_point z;

  for (uint32_t x = 0; x < screen_width; ++x) {
    for (uint32_t y = 0; y < screen_height; ++y) {
      z.x = 0.0f;
      z.y = 0.0f;
      sp.x = x;
      sp.y = y;
      pp = screen_to_plane(sp);


      for (size_t i = 0; i < max_iterations; ++i) {
        z.x = z.x * z.x - z.y * z.y + pp.x;
        z.y = 2 * z.x * z.y + pp.y;
        if (z.x * z.x + z.y * z.y >= 4) {
          uint8_t r = i * 12 % 256;
          uint8_t g = i * 8 % 256;
          uint8_t b = i * 4 % 256;
          uint32_t p = b | (g << 8) | (r << 16);

          set_pixel(sp, p);
          break;
        }

        if (i == max_iterations - 1) {
          set_pixel(sp, 0);
          break;
        }
      }
    }
  }
}
