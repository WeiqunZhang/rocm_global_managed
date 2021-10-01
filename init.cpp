#include "par.H"

__managed__ int d_a;
__managed__ int d_b[2];

void init ()
{
    d_a = 1;
    d_b[0] = 2;
    d_b[1] = 3;
}
