#ifndef PLANE_H
#define PLANE_H

#include <graphics.h>

extern float plane_min_x;
extern float plane_max_x;

extern float plane_min_y;
extern float plane_max_y;

struct plane_point {
  float x;
  float y;
};

struct screen_point plane_to_screen(struct plane_point p);

int set_plane_x(float min, float max);
int set_plane_y(float min, float max);

#endif
