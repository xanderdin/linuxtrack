#ifndef IMAGE_PROCESS__H
#define IMAGE_PROCESS__H

#ifdef __cplusplus
extern "C" {
#endif

#include "cal.h"
#include "list.h"

typedef struct {
  unsigned int vline;
  unsigned int hstart;
  unsigned int hstop;
  unsigned int sum_x;
  unsigned int sum;
  unsigned int points;
} stripe_t;

typedef struct {
  int w, h;
  unsigned char *bitmap;
  float ratio;
} image_t;

void ltr_int_prepare_for_processing(int w, int h);
void ltr_int_cleanup_after_processing();
void ltr_int_to_stripes(image_t *img);
int ltr_int_stripes_to_blobs(unsigned int num_blobs, struct bloblist_type *blt, 
		     int min_pts, int max_pts, image_t *img);
bool ltr_int_add_stripe(stripe_t *stripe, image_t *img);
void ltr_int_draw_cross(image_t *img, int x, int y, int size);
void ltr_int_draw_empty_square(image_t *img, int x1, int y1, int x2, int y2);
void ltr_int_draw_square(image_t *img, int x, int y, int size);

#ifdef __cplusplus
}
#endif

#endif
