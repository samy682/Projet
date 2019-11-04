#ifndef LASER_H
#define LASER_H



#include"direction.h"
#include"point.h"

class cell;


const point ORIGINLASER{0,0};
const direction EST{1,0};
const direction OUEST{-1,0};
const direction NORD{0,-1};
const direction SUD{0,1};



class laser
{
	public:
	    laser():d_dir{EST}, d_pos{ORIGINLASER},d_pts{0} {}
        laser(const direction& dir, const point& pos): d_dir{dir}, d_pos{pos},d_pts{0} {}

        void deplace(cell* c);
        void changePos(int x , int y);
        point pos() const;
        direction dir() const;
        void changeDirection(direction dir);
        bool estDansGrid(int xmax,int ymax);
        void inversionDirection();
        void inversionDirectionNegative();
        void ajoutPts(int pts);
        int points();

	private:
        direction d_dir;
        point d_pos;
        int d_pts;

};



#endif
