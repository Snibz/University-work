#include <stdlib.h>

#include "rectangle.h"

Rectangle *createRectangle(void)
{
    /* Creates a rectangle object. No params, rect with area of 0 and
       starting point of 0, 0 */
    Point zeroOrigin = {0, 0};
    Rectangle *rect = malloc(sizeof(Rectangle));
    rect->width = 0;
    rect->height = 0;

    rect->origin = zeroOrigin;

    return rect;
}

Rectangle *createRectangle2(Point p)
{
    /* Same as above, but starting point is given. */

    Rectangle *rect = malloc(sizeof(Rectangle));
    rect->width = 0;
    rect->height = 0;

    rect->origin = p;

    return rect;
}

Rectangle *createRectangle3(int w, int h)
{
    /* Width and height are given */
    Point zeroOrigin = {0, 0};
    Rectangle *rect = malloc(sizeof(Rectangle));
    rect->width = w;
    rect->height = h;

    rect->origin = zeroOrigin;

    return rect;
}

Rectangle *createRectangle4(Point p, int w, int h)
{
    /* Point, width and height given */

    Rectangle *rect = malloc(sizeof(Rectangle));
    rect->width = w;
    rect->height = h;

    rect->origin = p;

    return rect;
}

void move(Rectangle *r, int x, int y)
{
    /* Moves the given rectangle's origin to the given x and y */

    r->origin.x = x;
    r->origin.y = y;
}

int getArea(const Rectangle *r)
{
    /* calculates and returns the area of the given rectangle */

    int area = r->width * r->height;
    return area;
}
