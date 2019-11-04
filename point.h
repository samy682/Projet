#ifndef POINT_H
#define POINT_H

#include<iostream>

class point{

    public:
        point(int x, int y): d_x{x}, d_y{y} {}
        int x() const;
        int y() const;
        int x() ;
        int y() ;
        void affiche(std::ostream &ost) const;
        void deplaceDe(int x, int y);

    private:
        int d_x,d_y;
};


std::ostream& operator<<(std::ostream &ost,point p);

#endif
