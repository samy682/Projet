#ifndef JEU_H
#define JEU_H

#include"grid.h"
#include"laser.h"

class jeu {

    public:
        jeu():d_grid{},d_laser{} {}
        jeu(const std::string& nomFichier);


        void setMirr();
        void initMur();
        void initPoints();
        void setParam();
        void run();
        void runFichier();
        bool coordDansGrid(int,int);

    private:
        grid d_grid;
        laser d_laser;

};
#endif
