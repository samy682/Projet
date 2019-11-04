#include"laser.h"
#include"cell.h"



point laser::pos() const { return d_pos;}

direction laser::dir() const {return d_dir;}


void laser::deplace(cell* c)
{
    c->deplaceLaser(this);

}

void laser::changePos(int x , int y)
{
    d_pos.deplaceDe(x,y);
}

void laser::changeDirection(direction dir)
{
    d_dir = dir;
}

bool laser::estDansGrid(int xmax,int ymax)
{
    return d_pos.x() < xmax && d_pos.x() >= 0 && d_pos.y() < ymax && d_pos.y() >= 0;

}

void laser::inversionDirection()
{
    d_dir.inversion();
}

void laser::inversionDirectionNegative()
{
    d_dir.inversionNegative();
}

void laser::ajoutPts(int pts)
{
    d_pts += pts;
}

int laser::points(){ return d_pts;}
