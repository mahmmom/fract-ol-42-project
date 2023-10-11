#include "fractol.h"

//LINEAR INTERPOLATION
double  scale(double s, double min2, double max2, double min1, double max1)
{
    return ((s - min1) * (max2 - min2) / (max1 - min1) + min2);
}
