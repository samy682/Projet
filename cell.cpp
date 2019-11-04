#include"cell.h"
#include"drawer.h"
#include"laser.h"


cell::cell():d_passageLaser(4, IMMOBILE)
{}

//methodes cell


void cell::ajoutDirection(direction dir)
{
    if(dir == NORD)
        d_passageLaser[0] = NORD;
    else if(dir == SUD)
        d_passageLaser[1] = SUD;
    else if(dir == OUEST)
        d_passageLaser[2] = OUEST;
    else if(dir == EST)
        d_passageLaser[3] = EST;
}




///////////////////// methodes Cell Vide /////////////////////////

void cellVide::affiche(double x, double y) const
{
	drawer dr;

	dr.drawCellVide(d_passageLaser,x,y);
}

void cellVide::deplaceLaser(laser* l)
{
   l->changePos(l->dir().x(),l->dir().y());
   ajoutDirection(l->dir());
}

bool cellVide::estCible() const { return false;}
bool cellVide::estLibre()  const { return true;}

std::string cellVide::type()  const { return "cellVide";}

//////////////////// methodes Cell mirroir1 //////////////////

void cellMirroir1::affiche(double x, double y) const
{
	drawer dr;

	dr.drawCellMirroir1(d_passageLaser,x,y);
}

void cellMirroir1::deplaceLaser(laser* l)
{
    ajoutDirection(l->dir());
    l->inversionDirection();
    cellVide cv;
    cv.deplaceLaser(l);
    ajoutDirection(l->dir().retournement());

}

bool cellMirroir1::estCible() const { return false;}
bool cellMirroir1::estLibre() const { return false;}

std::string cellMirroir1::type()  const { return "cellMirroir1";}


///////////////////////////// methodes Cell mirroir2 ///////////////////

void cellMirroir2::affiche(double x, double y) const
{
	drawer dr;

	dr.drawCellMirroir2(d_passageLaser,x,y);
}

void cellMirroir2::deplaceLaser(laser* l)
{
    ajoutDirection(l->dir());
    l->inversionDirectionNegative();
    cellVide cv;
    cv.deplaceLaser(l);
    ajoutDirection(l->dir().retournement());
}

bool cellMirroir2::estCible() const { return false;}
bool cellMirroir2::estLibre() const { return false;}

std::string cellMirroir2::type()  const { return "cellMirroir2";}


//////////////////////////////////////// methodes Cell Mur ///////////////////

void cellMur::affiche(double x, double y) const
{
	drawer dr;

	dr.drawCellMur(d_passageLaser,x,y);
}

void cellMur::deplaceLaser(laser* l)
{
    l->changeDirection(IMMOBILE);

}

bool cellMur::estCible() const { return false;}
bool cellMur::estLibre() const { return false;}

std::string cellMur::type()  const { return "cellMur";}


///////////////////////// methodes Cell cible ///////////////////

void cellCible::affiche(double x, double y) const
{
	drawer dr;

	dr.drawCellCible(d_passageLaser,x,y);
}

void cellCible::deplaceLaser(laser* l)
{
    std::cout<<"cellule cible"<<std::endl;
    l->changeDirection(IMMOBILE);
}

bool cellCible::estCible() const { return true;}
bool cellCible::estLibre() const { return false;}

std::string cellCible::type()  const { return "cellCible";}


/////////////////////////// methodes Cell Points ///////////////////

void cellPoints::affiche(double x, double y) const
{
	drawer dr;

	dr.drawCellPoints(d_passageLaser,x,y);
}

void cellPoints::deplaceLaser(laser* l)
{
   l->changePos(l->dir().x(),l->dir().y());
   l->ajoutPts(PTS);
   ajoutDirection(l->dir());
}

bool cellPoints::estCible() const { return false;}
bool cellPoints::estLibre() const { return false;}

std::string cellPoints::type()  const { return "cellPoints";}

