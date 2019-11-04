#include <iostream>
#include "cell.h"
#include"laser.h"
#include"grid.h"
#include"graphics.h"
#include"drawer.h"
#include"point.h"
#include"direction.h"
#include"jeu.h"
#include <ctime>

void testAfficheCell()
{
	cellVide* c;

	c->affiche(100,400);
}

void testAfficheGridVide()
{
	grid gr;

	gr.affiche();
}


void testAfficheGridAvecMirroir()
{
	grid gr;
	cell* c = new cellMirroir1;
	gr.ajoutCell(c,7,7);// placer un mirroir1("\") à la coordonnee (4,4)
	gr.affiche();

}


void testAfficheGridInitialiseConsole()
{
	grid gr;
	gr.affiche();



	int x,y;

	std::cout<<"Entrer coordonnees premier mirroir \\ : "<<std::endl;
	std::cin>>x>>y;
	cell* c = new cellMirroir1();
	gr.ajoutCell(c,x,y);
	cleardevice();
	gr.affiche();

	std::cout<<"Entrer coordonnees deuxieme mirroir /: "<<std::endl;
	cell* c1 = new cellMirroir1();
	std::cin>>x>>y;
	gr.ajoutCell(c1,x,y);
	cleardevice();
	gr.affiche();

	std::cout<<"Entrer coordonnees Mur : "<<std::endl;
	cell* c2 = new cellMur();
    std::cin>>x>>y;
	gr.ajoutCell(c2,x,y);
	cleardevice();
	gr.affiche();

    std::cout<<"Entrer coordonnees Cible : "<<std::endl;
	cell* c3 = new cellCible();
    std::cin>>x>>y;
	gr.ajoutCell(c3,x,y);
	cleardevice();
	gr.affiche();




}



void testPassageLaser()
{
    cellVide* c = new cellVide;

    c->affiche(400,400);

    laser l{OUEST,{20,20}};
    std::cout<<l.pos();
    l.deplace(c);

    c->affiche(400,400);
    std::cout<<l.pos();

}

void testPoint()
{

    point p{50,25};
    std::cout<<p<<std::endl;
    p.deplaceDe(0,1);
    std::cout<<p;

}

void testDeplacementDansGridVide()
{
    grid gr;
    laser l;


    while(l.estDansGrid(XMAX,YMAX))
    {
        l.deplace(gr[l.pos().x()-1][l.pos().y()-1]);
    }


    gr.affiche();
}

void testDeplacementDansGridMirroir()
{
    grid gr;
    laser l;

    gr.affiche();

    int x,y;

	std::cout<<"Entrer coordonnees premier mirroir \\ : "<<std::endl;
	std::cin>>x>>y;
	cell* c = new cellMirroir1();
	gr.ajoutCell(c,x,y);

    std::cout<<"Entrer coordonnees premier mirroir / : "<<std::endl;
	std::cin>>x>>y;
	cell* c1 = new cellMirroir2();
	gr.ajoutCell(c1,x,y);

	std::cout<<"Entrer coordonnees deuxieme mirroir \\ : "<<std::endl;
	std::cin>>x>>y;
	cell* c2 = new cellMirroir1();
	gr.ajoutCell(c2,x,y);

	std::cout<<"Entrer coordonnees deuxieme mirroir / : "<<std::endl;
	std::cin>>x>>y;
	cell* c3 = new cellMirroir2();
	gr.ajoutCell(c3,x,y);

	std::cout<<"Entrer coordonnees Mur : "<<std::endl;
	cell* cm = new cellMur();
    std::cin>>x>>y;
	gr.ajoutCell(cm,x,y);




    while(l.estDansGrid(XMAX,YMAX) && l.dir()!=IMMOBILE)
    {
        l.deplace(gr[l.pos().x()-1][l.pos().y()-1]);
    }


    gr.affiche();
}

void testType()
{
    grid gr;
     gr.affiche();
     cell* c = new cellPoints();
	std::cout<<"la cellule 6 6 est de type ? "<<gr[7][7]->type()<<std::endl;
     gr.ajoutCell(c,8,8);
     getch();
     cleardevice();
     gr.affiche();
     std::cout<<"la cellule 6 6 est de type ? "<<gr[7][7]->type()<<std::endl;

}

void testLibre()
{
	grid gr;
     gr.affiche();
     cell* c = new cellPoints();
	std::cout<<"la cellule 6 6 est libre ? "<<gr[7][7]->estLibre()<<std::endl;
     gr.ajoutCell(c,8,8);
     getch();
     cleardevice();
     gr.affiche();
     std::cout<<"la cellule 6 6 est libre ? "<<gr[7][7]->estLibre()<<std::endl;

}

void testMouse()
{
    grid gr;
     gr.affiche();

     int x,y;

     getmouse(x,y);

     std::cout<<"coord ( "<<x<<" , "<<y<<" )"<<std::endl;

     x = x / 50 ;
     y = y / 50 + 1;

     std::cout<<"cell ( "<<x<<" , "<<y<<" )"<<std::endl;
}

int main(int argc, char** argv) {

    srand(time(0));
	opengraphsize(900,900);

	std::cout<<"Hello"<<std::endl;

	jeu j{"test.txt"};
	j.runFichier();

	getch();
	closegraph();
	return 0;
}
