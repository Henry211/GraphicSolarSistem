#include <iostream>
#include <math.h>
#include <winbgim.h>
#include <windows.h>
#include "sistema.h"
using namespace std;
#define tam 4//---Capacidad de sistemas guardados

Sistema *Solar[tam];
void askFor();
void clean();

int main(){
	
	//clean para llenar de NULL todos los espacios del vector de SistemasSolares
		clean();
	// 'askFor' para abrir menu
		askFor();
	
	
	getch();
	return 0;
}


void clean(){
	//-- Lismpia todos los espacios del vector
	for(int i=0;i<=tam;i++){
		Solar[i] = NULL;
	}
}

void askFor(){	//-- ABRIR MENÚ
		int npl,opc,i=0;
		string nam;
	
	int s=1;
	
	while(s==1){
		initwindow(1200,700);
		cout<<"\t||--- 1.Crear nuevo Sistema -------||"<<endl;
		cout<<"\t||--- 2.Verificar Sistemas Guardado||"<<endl;
		cout<<"\t||--- 3.Graficar Sistemas Guardado ||"<<endl;
		cout<<"\t||--- 4.Borrar Sistema Guardado ---||"<<endl;
		cout<<"\t||----5.Dibujar Sistema por defecto||"<<endl;
		
		cin>>opc;
		system("cls");
		switch(opc){
			
			case 1:{//----------CREAR NUEVO SISTEMA------------------
				
				cout<<"Escriba el nombre de el nuevo sistema solar: _";
				cin>>nam;
				cout<<"Digite el numero de Planetas que tendra su sistema Solar			|| 6 MAXIMO ||"<<endl;
				cin>>npl;
				
				
					//-- Crea un puntero señalando el nuevo objeto tipo sistema
					Sistema *P = new Sistema(npl,nam);
					//-- Asigna el espacio del vector a el objeto creado
					Solar[i] = P;
					//-- Asigna valores a los planetas del sistema
					Solar[i]->crearPlanetas();
					//-- muestra en pantalla el sistema inmovil
					Solar[i]->animarSistema(0); //parametro '0' para que el sistema no se mueva
					
					Solar[i]->setst(1);
				i++;
					if(i==3){	//--- 'if' para volver al espacio uno si se supera el maximode 4
						i=1;
					}
			
				break;
			}
			case 2:{//---------VERIFICAR SISTEMA ----------
				int sis,edi;
					//-- Muestra los espacios del vector vacios o llenos
					for(int j=0;j<tam;j++){
						if(Solar[j]==NULL){
							cout<<" --#"<<j<<" ---> No existe"<<endl;
						}
						else{
							cout<<" --#"<<j<<" ---> Existe"<<endl;
						}
					}
				cout<<"Seleccione un Sistema guardado.. "<<endl;
				cin>>sis;
				//--Muestra los datos del sistema
				Solar[sis]->abrir();
				cout<<"Desea editar este Sistema?		|| 1=SI  ||"<<endl;
				cin>>edi;
					//-- Habilita la edicion del sistema
					if(edi==1){
						Solar[sis]->editar();	
					}
				
				break;
			}
			case 3:{//-------------GRAFICAR SISTEMA---------------
				int sis,edi;
					//-- Muestra los espacios del vector vacios o llenos
					for(int j=0;j<tam;j++){
						if(Solar[j]==NULL){
							cout<<" --#"<<j<<" ---> No existe"<<endl;
						}
						else{
							cout<<" --#"<<j<<" ---> Existe"<<endl;
						}
					}
				cout<<"Seleccione un Sistema guardado para graficarlo.. "<<endl;
				cin>>sis;
				//-- Mostrar sistema en pantalla
				Solar[sis]->animarSistema(1);//-- Parametro '1' para que el sistema sea movil
				break;
			}
			case 4:{//---------BORRAR SISTEMA-----------
				int sis;
				//-- Muestra los espacios del vector vacios o llenos
					for(int j=0;j<tam;j++){
						if(Solar[j]==NULL){
							cout<<" --#"<<j<<" ---> No existe"<<endl;
						}
						else{
							cout<<" --#"<<j<<" ---> Existe"<<endl;
						}
					}
				cout<<"Seleccione el Sistema a eliminar.. "<<endl;
				cin>>sis;
				//-- Eliminación total de un sistema
				delete Solar[sis];
				Solar[sis] = NULL;
				break;
			}
			case 5:{//--------------POR DEFECTO-----------------
								//-----------------------------------------------------------------
								Sistema *Q = new Sistema(6,"SistemaPorDefecto");
								Solar[3] = Q;
								Solar[3]->crearDef();//-----------------------SISTEMA POR DEFECTO
								Solar[3]->animarSistema(1);
								//-----------------------------------------------------------------
				break;
			}
		}
		closegraph();
		system("cls");
	}
	
}


