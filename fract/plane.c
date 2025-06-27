#include <plane.h>

float plane_min_x;
float plane_max_x;

float plane_min_y;
float plane_max_y;

/*
 * plane_to_screen transforms the plane point `p` into a screen point which can
 * be drawn to the framebuffer.
 */
struct screen_point plane_to_screen(struct plane_point p) {
  struct screen_point ret;

  float dx = plane_max_x - plane_min_x;
  float dy = plane_max_y - plane_min_y;

  ret.x = (p.x - plane_min_x) / dx * (screen_width - 1);
  ret.y = (p.y - plane_min_y) / dy * (screen_height - 1);

  return ret;
}

/*
 * set_plane_x sets the x bounds of the plane. It returns 0 on success and -1
 * on failure.
 */
int set_plane_x(float min, float max) {
  if (min >= max) {
    return -1;
  }

  plane_min_x = min;
  plane_max_x = max;

  return 0;
}

/*
 * set_plane_y sets the y bounds of the plane. It returns 0 on success and -1
 * on failure.
 */
int set_plane_y(float min, float max) {
  if (min >= max) {
    return -1;
  }

  plane_min_y = min;
  plane_max_y = max;

  return 0;
}
