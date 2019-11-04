#include"drawer.h"
#include"graphics.h"
#include"cell.h"
#include"laser.h"

void drawer::drawCell(int x, int y)
{
    setcolor(WHITE);
    line(x,y,x,y-LENGHT);
	line(x,y-LENGHT,x+LENGHT,y-LENGHT);
	line(x+LENGHT,y-LENGHT,x+LENGHT,y);
	line(x+LENGHT,y,x,y);
}
void drawer::drawLaser(std::vector<direction> dir, int x, int y)
{
    setcolor(RED);
    if(dir[0] == NORD || dir[1] == SUD)
    {
        line(x+(LENGHT/2),y,x+(LENGHT/2),y-LENGHT);
    }
    if( dir[2] == OUEST || dir[3] == EST)
    {
        line(x,y-(LENGHT/2),x+LENGHT,y-(LENGHT/2));
    }
    setcolor(WHITE);
}

void drawer::drawCellVide(std::vector<direction> dir,int x, int y)
{
	drawCell(x,y);

	if(dir[0] == NORD || dir[1] == SUD || dir[2] == OUEST || dir[3] == EST )
        drawLaser(dir,x,y);


}


//// dessiner laser dans cell mirroirs/////////////////////

void drawer::drawLaserSud(int x, int y)
{
    line(x+LENGHT/2,y-LENGHT,x+LENGHT/2,y-LENGHT/2);

}

void drawer::drawLaserNord(int x, int y)
{
    line(x+LENGHT/2,y,x+LENGHT/2,y-LENGHT/2);

}

void drawer::drawLaserEst(int x, int y)
{
    line(x,y-LENGHT/2,x+LENGHT/2,y-LENGHT/2);

}

void drawer::drawLaserOuest(int x, int y)
{
    line(x+LENGHT,y-LENGHT/2,x+LENGHT/2,y-LENGHT/2);

}

void drawer::drawLaserMirroir(std::vector<direction> dir, int x, int y)
{
    setcolor(RED);
    if(dir[0] == NORD) drawLaserNord(x,y);
    if(dir[1] == SUD) drawLaserSud(x,y);
    if(dir[3] == EST) drawLaserEst(x,y);
    if(dir[2] == OUEST) drawLaserOuest(x,y);
    setcolor(WHITE);
}

/////////dessine cellule mirroir ////////////

void drawer::drawCellMirroir1(std::vector<direction> dir,int x, int y)
{

	drawCell(x,y);
	setcolor(BLUE);
	line(x,y-LENGHT,x+LENGHT,y);
	if(dir[0] == NORD || dir[1] == SUD || dir[2] == OUEST || dir[3] == EST )
        drawLaserMirroir(dir,x,y);
    setcolor(WHITE);

}


void drawer::drawCellMirroir2(std::vector<direction> dir,int x, int y)
{

	drawCell(x,y);
	setcolor(BLUE);
	line(x,y,x+LENGHT,y-LENGHT);
    if(dir[0] == NORD || dir[1] == SUD || dir[2] == OUEST || dir[3] == EST )
        drawLaserMirroir(dir,x,y);
    setcolor(WHITE);

}


//// Dessine mur /////////////////
void drawer::drawCellMur(std::vector<direction> dir,int x, int y)
{
    setcolor(GREEN);
	drawCell(x,y);
	int points[8] = {x,y,x,y-LENGHT,x+LENGHT,y-LENGHT,x+LENGHT,y};
	fillpoly(4,points);
    setcolor(WHITE);

}


void drawer::drawCellCible(std::vector<direction> dir,int x, int y)
{

	drawCell(x,y);
	setcolor(YELLOW);
	int r = int(LENGHT/2.);
	circle(x+r,y-r,r);
    setcolor(WHITE);

}

void drawer::drawCellPoints(std::vector<direction> dir,int x, int y)
{

	drawCell(x,y);
	setcolor(MAGENTA);
	if(dir[0] == NORD || dir[1] == SUD || dir[2] == OUEST || dir[3] == EST )
        drawLaser(dir,x,y);
	int r = int(LENGHT/2.);
	circle(x+r,y-r,r/4);
    setcolor(WHITE);

}

