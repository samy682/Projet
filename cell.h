#ifndef CELL_H
#define CELL_H

#include"direction.h"
#include<vector>
#include<string>



class laser;

const int LENGHT = 50;// longueur coté cell
const int PTS = 5;// points ciblePoints
const direction IMMOBILE{0,0};

class cell
{
	public:
        cell();

		virtual void affiche(double x, double y) const = 0;// affiche une cellule

		virtual void deplaceLaser(laser*)  = 0;
		void ajoutDirection(direction dir);
		virtual bool estLibre() const = 0;
		virtual bool estCible() const = 0;
		virtual std::string type() const = 0;

	protected:
		std::vector<direction> d_passageLaser;// 0 si le laser n'est pas passé, EST,NORD,SUD ou OUEST sinon


};


class cellVide : public cell
{
	public:
		virtual void affiche(double x, double y) const ;
		virtual void deplaceLaser(laser*)   override ;// deplace le laser d'une cell sans changer sa direction
		virtual bool estCible() const override;
		virtual bool estLibre() const override;
		virtual std::string type()  const override;
};

class cellMirroir1 : public cell
{
	public:
		virtual void affiche(double x, double y) const override;// affiche le mirroi " \"
		virtual void deplaceLaser(laser*)   override ;// Deplace le robot en changeant sa direction
		virtual bool estCible() const override;
		virtual bool estLibre() const override;
		virtual std::string type()  const override;
};

class cellMirroir2 : public cell
{
	public:
		virtual void affiche(double x, double y) const;// affiche le mirroi " / "
		virtual void deplaceLaser(laser*)   override ;// Deplace le robot en changeant sa direction
		virtual bool estCible() const override;
		virtual bool estLibre() const override;
		virtual std::string type()  const override;
};


class cellMur : public cell
{
	public:
		virtual void affiche(double x, double y) const;
		virtual void deplaceLaser(laser*)   override;// Arret le deplacement du robot
		virtual bool estCible() const override;
		virtual bool estLibre() const override;
		virtual std::string type()  const override;
};


class cellCible : public cell
{
	public:
		virtual void affiche(double x, double y) const;
		virtual void deplaceLaser(laser*)   override ;// Si le robot est dans cette celle le jeu est fini
		virtual bool estCible() const override;
		virtual bool estLibre() const override;
		virtual std::string type()  const override;
};


class cellPoints : public cell
{
	public:
		virtual void affiche(double x, double y) const;
		virtual void deplaceLaser(laser*)   override ;// Deplace le robot en lui ajoutant les points ( methode ajout points est dans le laser laser::ajoutPoint(int points) )
        virtual bool estLibre() const override;
        virtual bool estCible() const override;
        virtual std::string type()  const override;

};







#endif
