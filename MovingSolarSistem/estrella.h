#include <iostream>
#include <winbgim.h>
using namespace std;

class Estrella{
	private:
		string nombreE,temperaturaE="6.000-5.000k";
		int radioE,colorE=14;
		char clasifE='G';
	public:
		//cosntructores
		Estrella(){ };
		//metodos
		void crearEstrella(int,int,int);
		void cinturonAst();
		//sets y gets
		char getclasif(){ return clasifE;}
		string gettemp(){ return temperaturaE;}
		int getcolorE(){ return colorE;}
		void setclasif(char p){ clasifE = p;}
		void settemp(string r){ temperaturaE = r;}
		void setcolor(int q){ colorE = q;}
		void putEstrella(int,int,int);
		void putSistema();
};


