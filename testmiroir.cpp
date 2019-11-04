#include "doctest.h"
#include "point.h"
#include "cell.h"
#include "direction.h"
#include "grid.h"


TEST_CASE("Les directions sont correctes")
{
    SUBCASE("L'inversion est correcte")
    {
        int x = 1 ;
        int y = 2;
        direction dir{x,y};
        dir.inversion();
        REQUIRE_EQ(dir.x(),y);
        REQUIRE_EQ(dir.y(),x);
    }
    SUBCASE("Le retournement est correcte")
    {
        int x = 1 ;
        int y = 2;
        direction dir{x,y};
        direction dirRetourne = dir.retournement();
        REQUIRE_EQ(dirRetourne.x(),-x);
        REQUIRE_EQ(dirRetourne.y(),-y);
    }
    SUBCASE("Linversion négative est correcte")
    {
        int x = 1 ;
        int y = 2;
        direction dir{x,y};
        dir.inversionNegative();
        REQUIRE_EQ(dir.x(),-y);
        REQUIRE_EQ(dir.y(),-x);
    }
}
TEST_CASE("L'ajout des types de cellules sont correcte ")
{
    SUBCASE("Les points bonus sont correcte")
    {
     grid gr;
     cell* c = new cellPoints();
     gr.ajoutCell(c,7,7);
     REQUIRE_EQ(gr[7][7]->type(),"cellPoints");
    }
    SUBCASE("Les miroirs sont correcte")
    {
     grid gr;
     cell* c1 = new cellMirroir1();
     gr.ajoutCell(c1,7,7);
     REQUIRE_EQ(gr[7][7]->type(),"cellMirroir1");
     cell* c2 = new cellMirroir2();
     gr.ajoutCell(c2,6,7);
     REQUIRE_EQ(gr[6][7]->type(),"cellMirroir2");

    }
    SUBCASE("La cible est correcte")
    {
     grid gr;
     cell* c1 = new cellCible();
     gr.ajoutCell(c1,7,7);
     REQUIRE_EQ(gr[7][7]->type(),"cellCible");


    }
    SUBCASE("La case vide est correcte")
    {
     grid gr;
     cell* c1 = new cellVide();
     gr.ajoutCell(c1,7,7);
     REQUIRE_EQ(gr[7][7]->type(),"cellVide");
    }
}
TEST_CASE("Toutes les cases sont bien non vide a part la cellule vide")
{
    SUBCASE("La case cible est non vide")
    {
     grid gr;
     cell* c1 = new cellCible();
     gr.ajoutCell(c1,7,7);
     REQUIRE_EQ(c1->estLibre(),false);
    }
       SUBCASE("La case vide est vide ")
    {
     grid gr;
     cell* c1 = new cellVide();
     gr.ajoutCell(c1,7,7);
     REQUIRE_EQ(c1->estLibre(),true);
    }
        SUBCASE("Les cases miroirs sont non vide ")
    {
     grid gr;
     cell* c1 = new cellMirroir1();
     gr.ajoutCell(c1,7,7);
     REQUIRE_EQ(c1->estLibre(),false);
     cell* c2 = new cellMirroir2();
     gr.ajoutCell(c2,6,7);
     REQUIRE_EQ(c2->estLibre(),false);
    }
    SUBCASE("Les points bonus sont non vide")
    {
     grid gr;
     cell* c = new cellPoints();
     gr.ajoutCell(c,7,7);
     REQUIRE_EQ(c->estLibre(),false);
    }
}
