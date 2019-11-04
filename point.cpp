#include"point.h"


int point::x() const {return d_x;}

int point::y() const {return d_y;}

int point::x()  {return d_x;}

int point::y()  {return d_y;}

void point::deplaceDe(int x, int y) {

    d_x+=x;
    d_y+=y;

}


void point::affiche(std::ostream &ost) const{

	ost<<'('<<d_x<<','<<d_y<<')'<<std::endl;

}

std::ostream& operator<<(std::ostream &ost,point p) {

	p.affiche(ost);

	return ost;

}
