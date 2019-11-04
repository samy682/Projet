#include"grid.h"
#include<vector>
#include<iostream>


grid::grid():d_cells(8, std::vector <cell*> (8))
{
	for(int i=0;i<YMAX;i++)
		for(int j=0;j<XMAX;j++)
			d_cells[i][j] = new cellVide;


}





void grid::affiche() const
{

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			d_cells[i][j]->affiche(ORIGIN.x()*(i+1),ORIGIN.y()*(j+1));
}


void grid::ajoutCell(cell* c,int x, int y)
{


	delete d_cells[x][y];
	d_cells[x][y] = c;



}

std::vector<cell*> grid::operator[](int i) {return d_cells[i];}
