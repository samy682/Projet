#include"direction.h"


int direction::x() { return d_x;}

int direction::y() {return d_y;}

bool direction::operator==(const direction& dir)
{
    return d_x == dir.d_x && d_y == dir.d_y;

}

bool direction::operator!=(const direction& dir)
{
    return !(operator==(dir));
}

void direction::inversion()
{
    int tmp=d_x;
    d_x = d_y;
    d_y = tmp;

}

void direction::inversionNegative()
{
    inversion();
    d_x*=-1;
    d_y*=-1;
}

direction direction::retournement()
{
    int x=d_x,y=d_y;
    x*=-1;
    y*=-1;
    return {x,y};
}
