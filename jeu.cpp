#include"jeu.h"
#include"graphics.h"
#include"cell.h"
#include<iostream>
#include"random.h"
#include<string>
#include<fstream>


jeu::jeu(const std::string& nomFichier): d_grid{}, d_laser{}
{

    std::ifstream f(nomFichier);

    int nbPointsBonus,nbMurs;

    f>>nbPointsBonus>>nbMurs;

    int x,y;

    cell* c;

    c = new cellCible();
    f>>x>>y;
    d_grid.ajoutCell(c,x,y);

    for(int i = 0 ; i < nbPointsBonus ; i++)
    {
        f>>x>>y;
        c = new cellPoints();
        d_grid.ajoutCell(c,x,y);
    }

    for(int i = 0 ; i < nbMurs ; i++)
    {
        f>>x>>y;
        c = new cellMur();
        d_grid.ajoutCell(c,x,y);
    }


}

bool jeu::coordDansGrid(int x, int y){ return x > -1 && x < XMAX && y > -1 && y < YMAX;}

void jeu::setMirr()
{

   int x = 0,y = 0;
    cell* cm1;
    int i = 0;
    while(i < 2)
    {
    do
    {

	std::cout<<"Cliquer sur une case vide pour placer le  mirroir \\ "<<i+1<<" : "<<std::endl;
	getmouse(x,y);
     x = x / 50 - 1 ;
     y = y / 50 ;

    }while(!coordDansGrid(x,y) || !d_grid[x][y]->estLibre());

    cm1 = new cellMirroir1();
	d_grid.ajoutCell(cm1,x,y);
	cleardevice();
	d_grid.affiche();
    i++;
    }

    cell* cm2;
    i = 0;
    while( i < 2)
    {

	do
    {

	std::cout<<"Cliquer sur une case vide pour placer le  mirroir / "<<i+1<<" : "<<std::endl;
    getmouse(x,y);
     x = x / 50 - 1;
     y = y / 50 ;

    }while(!coordDansGrid(x,y) || !d_grid[x][y]->estLibre());
    cm2 = new cellMirroir2();
	d_grid.ajoutCell(cm2,x,y);
	cleardevice();
	d_grid.affiche();
	i++;
    }
}

void jeu::initMur()
{
    int x,y;
    cell* cm ;
    for(int i = 0 ; i < 2; i++)
    {

          random r;
        do
        {
            x=r.randomInt(0,7);
            y=r.randomInt(1,7);
        }while(!d_grid[x][y]->estLibre());

       cm = new cellMur();
       d_grid.ajoutCell(cm,x,y);
    }
}



void jeu::initPoints()
{
    int x,y;
    random r;
   do
   {
       x=r.randomInt(0,7);
       y=r.randomInt(0,7);
   }while(!d_grid[x][y]->estLibre());

   cell* c = new cellCible();
   d_grid.ajoutCell(c,x,y);



    cell* cp;
    for(int i = 0; i<4; i++)
    {

        do
        {
            x=r.randomInt(0,7);
            y=r.randomInt(0,7);
        }while(!d_grid[x][y]->estLibre());

        cp = new cellPoints();
        d_grid.ajoutCell(cp,x,y);
    }


}

void jeu::setParam()
{

    setMirr();

}

void jeu::run()
{


    initPoints();
    initMur();
    d_grid.affiche();



    setParam();



    while(d_laser.estDansGrid(XMAX,YMAX) && d_laser.dir()!=IMMOBILE)
    {
        d_laser.deplace(d_grid[d_laser.pos().x()][d_laser.pos().y()]);
        cleardevice();
        d_grid.affiche();
        delay(70);

    }


    std::string s;

    if(d_laser.estDansGrid(XMAX,YMAX))
    {
        if( d_grid[d_laser.pos().x()][d_laser.pos().y()]->estCible())
        {
           auto points=std::to_string (int(d_laser.points()));
           s = "vous avez atteint la cible et gagné " + points + " points";
        }
        else  s = "vous avez perdu";
    }
    else
        s = "vous avez perdu";

    d_grid.affiche();

    setlinestyle(SOLID_LINE, 1, 10 );
    outtextxy(500,100,s.c_str());


}

void jeu::runFichier()
{


    d_grid.affiche();

    setMirr();

    while(d_laser.estDansGrid(XMAX,YMAX) && d_laser.dir()!=IMMOBILE)
    {
        d_laser.deplace(d_grid[d_laser.pos().x()][d_laser.pos().y()]);
        cleardevice();
        d_grid.affiche();
        delay(70);

    }


    std::string s;

    if(d_laser.estDansGrid(XMAX,YMAX))
    {
        if( d_grid[d_laser.pos().x()][d_laser.pos().y()]->estCible())
        {
           auto points=std::to_string (int(d_laser.points()));
           s = "vous avez atteint la cible et gagné " + points + " points";
        }
        else  s = "vous avez perdu";
    }
    else
        s = "vous avez perdu";

    d_grid.affiche();

    setlinestyle(SOLID_LINE, 1, 10 );
    outtextxy(500,100,s.c_str());


}
