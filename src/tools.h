#ifndef PVZ_TOOL_H
#define PVZ_TOOL_H
#include <graphics.h>
//¹¤¾ßº¯Êý
void putimagePNG(int  picture_x, int picture_y, IMAGE* picture);

void _putimagePNG(int  picture_x, int picture_y, IMAGE* picture);

int getDelay();

void flipImage(IMAGE*src,IMAGE*dst);

void SketchImage(IMAGE*src,IMAGE*dst);

void CoolImage(IMAGE*src,IMAGE*dst);
#endif