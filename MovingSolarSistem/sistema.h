#include <iostream>
#include <winbgim.h>
#include "planeta.h"
#include "estrella.h"
using namespace std;

class Sistema{
	private:
		Planeta mat[8];
		Estrella gran;
		int st;
		int numeroP;
		string nombreS;
	public:
		//constructores
		Sistema(){ };
		Sistema(int,string);
		//métodos
		void crearPlanetas();
		void crearDef();
		void animarSistema(int);
		void abrir();
		void editar();
		void eliminarSistema();
		//sets y gets
		int getst(){ return st;}
		void setst(int q){ st = q;}
		void setNom(string n){ nombreS = n;}
};
