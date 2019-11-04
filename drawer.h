#ifndef DRAWER_H
#define DRAWER_H

#include"cell.h"


class drawer
{
	public:

        void drawCell(int x, int y);
		void drawCellVide(std::vector<direction> dir, int x, int y);// prends en parametre le type de cell et le coin inferieur gauche
		void drawCellMirroir1(std::vector<direction> dir,int x, int y);// dessine cellule avec mirroir " \ "
		void drawCellMirroir2(std::vector<direction> dir,int x, int y);// dessine cellule avec mirroir " / "
		void drawCellMur(std::vector<direction> dir,int x, int y);// dessine cellule pleine
		void drawCellCible(std::vector<direction> dir,int x, int y);// dessine cellule avec une cible à l'interieur
		void drawCellPoints(std::vector<direction> dir,int x, int y);// dessine cellule avec des chiffres à l'interieur
		void drawLaser(std::vector<direction> dir, int x, int y);

		// dessiner le laser dans les cellules mirroires sous differentes directions
		void drawLaserNord( int x, int y);
		void drawLaserSud( int x, int y);
		void drawLaserEst( int x, int y);
		void drawLaserOuest(int x, int y);
		void drawLaserMirroir(std::vector<direction> dir, int x, int y);

};


#endif
