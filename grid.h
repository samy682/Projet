#ifndef GRID_H
#define GRID_H
#include"point.h"
#include"cell.h"
#include <vector>
#include"laser.h"

const point ORIGIN{50,50}; //Position(coin inferieur gauche) de la toute premier cell de la grille de jeu
const int XMAX = 8;// taille de la grille en X
const int YMAX = 8;// taille de la grille en Y

class grid
{
	public:
		grid();//on initialise un terrain avec des cellules vides
		//~grid();

		void affiche() const;

		void ajoutCell(cell* c,int x, int y);// On ajoute une cellule et on donne ces coordonnees dans la grille, donc on remplace la cellule vide de base
        std::vector<cell*> operator[](int i);

	private:
		std::vector<std::vector<cell*>> d_cells;//grille de jeu

};


#endif

