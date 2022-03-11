#include "planeta.h"
#include <math.h>

void Planeta::def(string nom,int rad, int col, int lun){
	//-----Sistema por defecto
	nombreP = nom;
	radioP = rad;
	colorP = col;
	lunasP = lun;
	asteroide = 1;
	cinturon = 1;
	cometas = 3;
}


void Planeta::asignarDatos(int k){	
	string nameP;
	int radP,colP,ast,lunP,aniP,cint,com;
	
		//----PIDE y ASIGNA datos de cada Planeta
		cout<<"\t || Datos de Planeta #"<<k+1<<" || \n"<<endl;
			cout<<endl;
			cout<<"Escriba..."<<endl;
			cout<<"\n ---Nombre del Planeta: _"<<endl;
			cin>>nameP;
			cout<<"\n ---Radio del Planeta: _			-- Entre '6 -> 14' de radio para mejor respuesta grafica "<<endl;
			cin>>radP;
			cout<<"\n ---Color del Planeta: _		1-> Azul || 2-> Verde || 4->Rojo || 14-> Amarillo"<<endl;
			cin>>colP;
			if(k == 0){
			cout<<"\n ---Asteroide en el Sistema?: _		||	1 = Si || "<<endl;	
			cin>>ast;	
			cout<<"\n ---Cinturon de Asteroides en el Sistema?: _	|| 1 = Si ||"<<endl;
			cin>>cint;
			cout<<"\n ---Cometas en el Sistema: _	|| 1 o 2 o 3||"<<endl;
			cin>>com;
			}
			cout<<"\n ---Lunas: _		|| 1 o 2 o 3 ||"<<endl;	
			cin>>lunP;
			
		nombreP = nameP;
		radioP = radP;
		colorP = colP;
		lunasP = lunP;
		asteroide = ast;
		cinturon = cint;
		cometas = com;
}


void Planeta::editarData(){
	int o,c;
	//---Edición de datos de un Planeta
	do{
	
	cout<<"||--------------------------------||"<<endl;
	cout<<"||- 1.Editar nombre"<<endl;
	cout<<"||- 2.Editar radio"<<endl,
	cout<<"||- 3.Editar color"<<endl;
	cout<<"||- 4.Editar cantidad de lunas"<<endl;
	cout<<"||- 5.Volver al Menu"<<endl;
	cout<<"||--------------------------------||"<<endl;
	cin>>o;
	switch(o){
		case 1:{	//---EDITAR NOMBRE
			string name;
			cout<<"Nombre actual: '"<<nombreP<<"'"<<endl;
			cout<<"Escriba el nuevo Nombre:  ";cin>>name;
			nombreP = name;	//---Cambia nombre
			break;
		}
		case 2:{	//---EDITAR RADIO
			int rad;
			cout<<"Radio actual: '"<<radioP<<"'"<<endl;
			cout<<"Escriba el nuevo Radio:  ";cin>>rad;
			radioP = rad;	//--Cambia Radio
			break;
		}
		case 3:{	//---EDITAR COLOR
			int col;
			cout<<"Color actual: '"<<colorP<<"'"<<endl;
			cout<<"Escriba el nuevo Color:  ";cin>>col;
			colorP = col;	//-Cambia Color
			break;
		}
		case 4:{	//---EDITAR LUNAS
			int lun;
			cout<<"Cantidad de Lunas: '"<<lunasP<<"'"<<endl;
			cout<<"Escriba la nueva cantidad de Lunas:  		 0 o 1 o 2 o 3 ||"<<endl;
			cin>>lun;
			lunasP = lun;	//--Cambia Lunas
			break;
		}
		case 5:{
			c=5;		//----SALIR  DEL MENÚ DE EDICIÓN 
			break;
		}
	}
}while(c!=5);
}

void Planeta::mostrarData(){	//---> MOSTRAR TODOS LOS DATOS DE UN PLANETA
	
	cout<<"||- 	Planeta: '"<<nombreP<<"' -"<<endl;
	cout<<"||	Diametro Ecuatorial: '"<<radioP*2<<"' "<<endl;
	cout<<"||	Color: '"<<colorP<<"' \n"<<endl;
	cout<<"||	Cantidad de Lunas: '"<<lunasP<<"' "<<endl;
	cout<<"||--------------------------------"<<endl;
	cout<<endl;
}

void Planeta::putLunas(int ejex, int ejey,int angle,int ejeauxx, int ejeauxy){	//---DIBUJAR LUNAS
	//-------Dinuja la cantidad de Lunas
	angle = angle*(-1);
	switch(lunasP){
		case 1:{
				struct arccoordstype a, b;
				arc((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,angle,angle+2,25); //órbita Lunas tipo 'arc' dos pixeles atras
				getarccoords(&b);
				setfillstyle(SOLID_FILL,0);//---Borrar Luna
	   			fillellipse(b.xstart,b.ystart,5,5);

				arc((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,angle,angle+2,25); //--órbita Luna tipo 'arc'
				getarccoords(&a);
			
				setfillstyle(SOLID_FILL,15);//-- Dibuja Luna
	   			fillellipse(a.xstart+1,a.ystart-1,2,2);
			break;
		}
		case 2:{
				struct arccoordstype a, b;
				arc((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,angle,angle+2,25);
				getarccoords(&b);
				setfillstyle(SOLID_FILL,0);
	   			fillellipse(b.xstart,b.ystart,5,5);

				arc((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,angle,angle+2,25);
				getarccoords(&a);
			
				setfillstyle(SOLID_FILL,15);
	   			fillellipse(a.xstart+1,a.ystart-1,2,2);
	   			//---------------------------------------------------------------
	   			
				arc((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,angle+90,angle+92,25);
				getarccoords(&b);
				setfillstyle(SOLID_FILL,0);
	   			fillellipse(b.xstart,b.ystart,5,5);

				arc((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,angle+90,angle+92,25);
				getarccoords(&a);
			
				setfillstyle(SOLID_FILL,15);
	   			fillellipse(a.xstart+1,a.ystart-1,2,2);
			break;
		}
		case 3:{
				struct arccoordstype a, b;
				arc((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,angle,angle+2,25);
				getarccoords(&b);
				setfillstyle(SOLID_FILL,0);
	   			fillellipse(b.xstart,b.ystart,5,5);

				arc((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,angle,angle+2,25);
				getarccoords(&a);
			
				setfillstyle(SOLID_FILL,15);
	   			fillellipse(a.xstart+1,a.ystart-1,2,2);
	   			//---------------------------------------------------------------
	   			
				arc((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,angle+90,angle+92,25);
				getarccoords(&b);
				setfillstyle(SOLID_FILL,0);
	   			fillellipse(b.xstart,b.ystart,5,5);

				arc((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,angle+90,angle+92,25);
				getarccoords(&a);
			
				setfillstyle(SOLID_FILL,15);
	   			fillellipse(a.xstart+1,a.ystart-1,2,2);
	   			//---------------------------------------------------------------
	   			
				arc((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,angle+210,angle+212,25);
				getarccoords(&b);
				setfillstyle(SOLID_FILL,0);
	   			fillellipse(b.xstart,b.ystart,5,5);

				arc((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,angle+210,angle+212,25);
				getarccoords(&a);
			
				setfillstyle(SOLID_FILL,15);
	   			fillellipse(a.xstart+1,a.ystart-1,2,2);
			break;
		}
	}
	   		
	}
	
void Planeta::putPlanet(int angle, int ejex, int ejey, int ejeauxx, int ejeauxy){	//--DIBUJAR PLANETA
		setfillstyle(SOLID_FILL,0);//---Borrar Planeta	(EJEAUXX & EJEAUXY)
		fillellipse((getmaxx()/2)+ejeauxx,(getmaxy()/2)-ejeauxy,radioP+5,radioP+7);
		
		setfillstyle(SOLID_FILL,colorP);//---Dibujar Planeta (EJEX & EJEY)
	   	fillellipse((getmaxx()/2)+ejex,(getmaxy()/2)-ejey,radioP,radioP);	
}

void Planeta::putAste(int angle,int plusx, int plusy){	//--DIBUJAR ASTEROIDE
	double Pi=3.1416;
	int ejex,ejey,ejeauxx,ejeauxy;
	//variabjes ejeauxx y ejeauxy retrasadas '-2' para BORRAR
				ejeauxx=(int)floor(220*cos((angle-2)*Pi/180.0));
				ejeauxy=(int)floor(100*sin((angle-2)*Pi/180.0));
	//variables ejex,ejey para DIBUJAR
				ejex=(int)floor(220*cos((angle)*Pi/180.0)); 
	   			ejey=(int)floor(100*sin((angle)*Pi/180.0)); 
	
		setfillstyle(SOLID_FILL,0);//----Borrar Asteroide (EJEAUXX & EJEAUXY)
		fillellipse((getmaxx()/2)+ejeauxx+plusx,(getmaxy()/2)-ejeauxy-plusy,4,6);
		
		setfillstyle(SOLID_FILL,11);//--- Dibujar Asteroide (EJEX & EJEY)
	   	fillellipse((getmaxx()/2)+ejex+plusx,(getmaxy()/2)-ejey-plusy,3,5);
}

void Planeta::putCometa(int angle, int can){	//-- DIBUJAR COMETA
	double Pi=3.1416;
	int ejex,ejey,ejeauxx,ejeauxy,ejeplusx,ejeplusy;
	   			
	   		
	  	switch(can){
		case 1:{	  
		
		//variables ejex,ejey para dibujar
					ejex=(int)floor(310*cos((angle)*Pi/180.0)); 	//--DIBUJAR
		   			ejey=(int)floor(170*sin((angle)*Pi/180.0)); 
		//variabjes ejeauxx y ejeauxy retrasadas '-27' para borrar
					ejeauxx=(int)floor(310*cos((angle-27)*Pi/180.0));	//--BORRAR COLA
					ejeauxy=(int)floor(170*sin((angle-27)*Pi/180.0));
		//variabjes ejeauxx y ejeauxy retrasadas '-4' para borrar
					ejeplusx=(int)floor(310*cos((angle-4)*Pi/180.0));	//--BORRAR CUERPO
					ejeplusy=(int)floor(170*sin((angle-4)*Pi/180.0));
		
	  	 //Dibujar 3 pixeles
	   	putpixel(getmaxx()/2+ejex-102,getmaxy()/2-ejey-72,15);
	   	putpixel(getmaxx()/2+ejex-103,getmaxy()/2-ejey-73,15);
	   	putpixel(getmaxx()/2+ejex-104,getmaxy()/2-ejey-74,15);
		//Borrar
		putpixel(getmaxx()/2+ejeplusx-102,getmaxy()/2-ejeplusy-72,0);//--cuerpo
		putpixel(getmaxx()/2+ejeauxx-103,getmaxy()/2-ejeauxy-73,0);	//--cola
		putpixel(getmaxx()/2+ejeplusx-104,getmaxy()/2-ejeplusy-74,0);//--cuerpo
		break;
		}
		case 2:{
			
		//variables ejex,ejey para dibujar
					ejex=(int)floor(310*cos((angle)*Pi/180.0)); 
		   			ejey=(int)floor(170*sin((angle)*Pi/180.0)); 
		//variabjes ejeauxx y ejeauxy retrasadas '-15' para borrar
					ejeauxx=(int)floor(310*cos((angle-27)*Pi/180.0));
					ejeauxy=(int)floor(170*sin((angle-27)*Pi/180.0));
		//variabjes ejeauxx y ejeauxy retrasadas '-4' para borrar
					ejeplusx=(int)floor(310*cos((angle-4)*Pi/180.0));
					ejeplusy=(int)floor(170*sin((angle-4)*Pi/180.0));
		putpixel(getmaxx()/2+ejex-102,getmaxy()/2-ejey-72,15);
	   	putpixel(getmaxx()/2+ejex-103,getmaxy()/2-ejey-73,15);
	   	putpixel(getmaxx()/2+ejex-104,getmaxy()/2-ejey-74,15);
		//Borrar
		putpixel(getmaxx()/2+ejeplusx-102,getmaxy()/2-ejeplusy-72,0);
		putpixel(getmaxx()/2+ejeauxx-103,getmaxy()/2-ejeauxy-73,0);
		putpixel(getmaxx()/2+ejeplusx-104,getmaxy()/2-ejeplusy-74,0);
		//------------------------------------------------------------------------
		//variables ejex,ejey para dibujar
					ejex=(int)floor(180*cos((angle)*Pi/180.0)); 
		   			ejey=(int)floor(300*sin((angle)*Pi/180.0)); 
		//variabjes ejeauxx y ejeauxy retrasadas '-15' para borrar
					ejeauxx=(int)floor(180*cos((angle-27)*Pi/180.0));
					ejeauxy=(int)floor(300*sin((angle-27)*Pi/180.0));
		//variabjes ejeauxx y ejeauxy retrasadas '-4' para borrar
					ejeplusx=(int)floor(180*cos((angle-4)*Pi/180.0));
					ejeplusy=(int)floor(300*sin((angle-4)*Pi/180.0));
		putpixel(getmaxx()/2+ejex-80,getmaxy()/2-ejey+150,15);
	   	putpixel(getmaxx()/2+ejex-81,getmaxy()/2-ejey+151,15);
	   	putpixel(getmaxx()/2+ejex-82,getmaxy()/2-ejey+152,15);
		//Borrar
		putpixel(getmaxx()/2+ejeplusx-80,getmaxy()/2-ejeplusy+150,0);
		putpixel(getmaxx()/2+ejeauxx-81,getmaxy()/2-ejeauxy+151,0);
		putpixel(getmaxx()/2+ejeplusx-82,getmaxy()/2-ejeplusy+152,0);
			break;
		}
		case 3:{
			//variables ejex,ejey para dibujar
					ejex=(int)floor(310*cos((angle)*Pi/180.0)); 
		   			ejey=(int)floor(170*sin((angle)*Pi/180.0)); 
		//variabjes ejeauxx y ejeauxy retrasadas '-15' para borrar
					ejeauxx=(int)floor(310*cos((angle-27)*Pi/180.0));
					ejeauxy=(int)floor(170*sin((angle-27)*Pi/180.0));
		//variabjes ejeauxx y ejeauxy retrasadas '-4' para borrar
					ejeplusx=(int)floor(310*cos((angle-4)*Pi/180.0));
					ejeplusy=(int)floor(170*sin((angle-4)*Pi/180.0));
		putpixel(getmaxx()/2+ejex-102,getmaxy()/2-ejey-72,15);
	   	putpixel(getmaxx()/2+ejex-103,getmaxy()/2-ejey-73,15);
	   	putpixel(getmaxx()/2+ejex-104,getmaxy()/2-ejey-74,15);
		//Borrar
		putpixel(getmaxx()/2+ejeplusx-102,getmaxy()/2-ejeplusy-72,0);
		putpixel(getmaxx()/2+ejeauxx-103,getmaxy()/2-ejeauxy-73,0);
		putpixel(getmaxx()/2+ejeplusx-104,getmaxy()/2-ejeplusy-74,0);
		//------------------------------------------------------------------------
		//variables ejex,ejey para dibujar
					ejex=(int)floor(180*cos((angle)*Pi/180.0)); 
		   			ejey=(int)floor(300*sin((angle)*Pi/180.0)); 
		//variabjes ejeauxx y ejeauxy retrasadas '-15' para borrar
					ejeauxx=(int)floor(180*cos((angle-27)*Pi/180.0));
					ejeauxy=(int)floor(300*sin((angle-27)*Pi/180.0));
		//variabjes ejeauxx y ejeauxy retrasadas '-4' para borrar
					ejeplusx=(int)floor(180*cos((angle-4)*Pi/180.0));
					ejeplusy=(int)floor(300*sin((angle-4)*Pi/180.0));
		putpixel(getmaxx()/2+ejex+72,getmaxy()/2-ejey+102,15);
	   	putpixel(getmaxx()/2+ejex+73,getmaxy()/2-ejey+103,15);
	   	putpixel(getmaxx()/2+ejex+74,getmaxy()/2-ejey+104,15);
		//Borrar
		putpixel(getmaxx()/2+ejeplusx+72,getmaxy()/2-ejeplusy+102,0);
		putpixel(getmaxx()/2+ejeauxx+73,getmaxy()/2-ejeauxy+103,0);
		putpixel(getmaxx()/2+ejeplusx+74,getmaxy()/2-ejeplusy+104,0);
		//------------------------------------------------------------------------
		//variables ejex,ejey para dibujar
					ejex=(int)floor(300*cos((angle)*Pi/180.0)); 
		   			ejey=(int)floor(200*sin((angle)*Pi/180.0)); 
		//variabjes ejeauxx y ejeauxy retrasadas '-15' para borrar
					ejeauxx=(int)floor(300*cos((angle-27)*Pi/180.0));
					ejeauxy=(int)floor(200*sin((angle-27)*Pi/180.0));
		//variabjes ejeauxx y ejeauxy retrasadas '-4' para borrar
					ejeplusx=(int)floor(300*cos((angle-4)*Pi/180.0));
					ejeplusy=(int)floor(200*sin((angle-4)*Pi/180.0));
		putpixel(getmaxx()/2+ejex-80,getmaxy()/2-ejey+150,15);
	   	putpixel(getmaxx()/2+ejex-81,getmaxy()/2-ejey+151,15);
	   	putpixel(getmaxx()/2+ejex-82,getmaxy()/2-ejey+152,15);
		//Borrar
		putpixel(getmaxx()/2+ejeplusx-80,getmaxy()/2-ejeplusy+150,0);
		putpixel(getmaxx()/2+ejeauxx-81,getmaxy()/2-ejeauxy+151,0);
		putpixel(getmaxx()/2+ejeplusx-82,getmaxy()/2-ejeplusy+152,0);
			break;
		}
	}
}

