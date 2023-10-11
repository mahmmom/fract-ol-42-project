#include "fractol.h"

//LINEAR INTERPOLATION
double  scale(double s, double min2, double max2, double min1, double max1)
{
    return ((s - min1) * (max2 - min2) / (max1 - min1) + min2);
}

t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex   square_complex(t_complex z)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2*z.x*z.y;
    return (result);
}
