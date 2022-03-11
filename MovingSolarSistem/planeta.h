#include <iostream>
#include <winbgim.h>
using namespace std;

class Planeta{
	private:
		string nombreP;
		int radioP, colorP;
		int f,lunasP,asteroide=0,cinturon,cometas;
	public:
		//cosntructores
		Planeta(){ };
		//metodos
		void def(string,int,int,int); 
		void asignarDatos(int);
		void crearPlanetas(int,int);
		void putLunas(int,int,int,int,int);
		void putPlanet(int,int,int,int,int);
		void putAste(int,int,int);
		void mostrarData();
		void editarData();
		void putCometa(int,int);
		//sets y gets
		int getradio(){ return radioP;}
		int getlunas(){ return lunasP;}
		int getcol(){ return colorP;}
		int getast(){ return asteroide;}
		int getcint(){ return cinturon;}
		int getcom(){ return cometas;}
		string getname(){ return nombreP;}
	
};
