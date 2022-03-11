#include "sistema.h"
#include <math.h>


Sistema::Sistema(int e,string n){
	numeroP = e;
	nombreS = n;
}

void Sistema::crearDef(){	//--------CREAR SISTEMA POR DEFECTO------
		Planeta Tierra[6];	//--Crear vector de planetas
		Tierra[0].def("Mercurio",10,10,2);
		Tierra[1].def("Venus",8,2,3);
		Tierra[2].def("Tierra",11,9,2);
		Tierra[3].def("Marte",9,12,1);
		Tierra[4].def("Jupiter",14,6,1);
		Tierra[5].def("Saturno",11,13,0);
		for(int k=0;k<=5;k++){
			mat[k] = Tierra[k];
		}
		
}

void Sistema::abrir(){
		//----------------INFORMACIÓN DEL SISTEMA----
		
		cout<<"|| ------------------------------- ||"<<endl;
		cout<<"|| .  .  .  .  .  .  .  .  .  .  . ||"<<endl;
		cout<<"|| ---SISTEMA SOLAR '"<<nombreS<<"'--- "<<endl;
		cout<<"|| .  .  .  .  .  .  .  .  .  .  . ||"<<endl;
		cout<<"|| ------------------------------- ||"<<endl;
		cout<<"|| Clasificación de Estrella: '"<<gran.getclasif()<<"' "<<endl;
		cout<<"|| Temperatura de Estrella: '"<<gran.gettemp()<<"' "<<endl;
		cout<<"|| ------------------------------- ||"<<endl;
		cout<<"|| ..Numero de Planetas: "<<numeroP<<".. "<<endl;
		cout<<"|| ------------------------------- ||"<<endl;
		for(int i=0;i<=numeroP-1;i++){
		cout<<"|| -------------------------- ||"<<endl;
		cout<<"|| ---PLANETA '"<<mat[i].getname()<<"' --- "<<endl;
		cout<<"|| .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;	
		cout<<"|| ..Color: "<<mat[i].getcol()<<endl;
		cout<<"|| ..Radio: "<<mat[i].getradio()<<endl;
		cout<<"|| ..Lunas? -> "<<mat[i].getlunas()<<endl;
		cout<<"|| .  .  .  .  .  .  .  .  .  .  . ||"<<endl;
		cout<<"|| .  .  .  .  .  .  .  .  .  .  . ||"<<endl;
	}
}

void Sistema::editar(){	//-----MENÚ DE EDICION DEL SISTEMA-----
	int f,edi,c=2;
	do{
	
	cout<<"\t|| ----------------------------------- ||"<<endl;
	cout<<"\t|| 1 --> Editar Nombre al Sistema  	||"<<endl;
	cout<<"\t|| 2 --> Editar Planetas 				||"<<endl;
	cout<<"\t|| 3 --> Editar Estrella				||"<<endl;
	cout<<"\t|| 4 --> Editar otros cuerpos celestes	||"<<endl;
	cout<<"\t|| ----------------------------------- ||"<<endl;
	cin>>edi;
	
	switch(edi){
		case 1:{
			string nuevoN;
			cout<<"Escriba el nuevo nombre Para el Sistema Planetario"<<endl;
			cin>>nuevoN;
			nombreS = nuevoN;
			break;
		}
		case 2:{
			int op;
			cout<<"PLANETAS DEL SISTEMA "<<nombreS<<"... \n"<<endl;
			for(int i=0;i<=numeroP-1;i++){
				cout<<"\t PLANETA #"<<i<<endl;
				mat[i].mostrarData();
			}
			cout<<"Elija un Planeta a editar "<<endl;
			cin>>op;
				mat[op].editarData();
			
			break;
		}
		case 3:{
			char cl;//---------------------TABLA DE INFORMACION 'CLASIFICACION DE ESTRELLAS'
			cout<<"\t|| ----------------------------------- ||"<<endl;
			cout<<"	|| Informacion:							|| "<<endl;
			cout<<" ||La estrella es de clasificacion'"<<gran.getclasif()<<"' ||"<<endl;
			cout<<" || ------------------------------------ ||"<<endl;
			cout<<" || ------------------------------------ ||"<<endl;
			cout<<" ||TABLA DE CLASIFICACION DE UNA ESTRELLA||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -O-					||"<<endl;
			cout<<" || 		Color Azul						||"<<endl;
			cout<<" ||		Temperatura 40.000-25.000 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -B-					||"<<endl;
			cout<<" || 		Color Blanca					||"<<endl;
			cout<<" ||		Temperatura 25.000-11.000 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -A-					||"<<endl;
			cout<<" || 		Color Blanca					||"<<endl;
			cout<<" ||		Temperatura 11.000-7.500 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -F-					||"<<endl;
			cout<<" || 		Color Amarilla					||"<<endl;
			cout<<" ||		Temperatura 7.500-6.000 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -G-					||"<<endl;
			cout<<" || 		Color Amarilla					||"<<endl;
			cout<<" ||		Temperatura 6.000 - 5.000 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -K-					||"<<endl;
			cout<<" || 		Color Naranja					||"<<endl;
			cout<<" ||		Temperatura 5.000-3.500 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<" || **Clasificacion: -M-					||"<<endl;
			cout<<" || 		Color Roja						||"<<endl;
			cout<<" ||		Temperatura 3.500-3.000 k		||"<<endl;
			cout<<" ||  .  .  .  .  .  .  .  .  .  .  .  .  ||"<<endl;
			cout<<"	|| ------------------------------------ ||"<<endl;
			
			cout<<"***Eliga el caracter en mayuscula de el clasificación que va a asignar**"<<endl;
			cin>>cl;
			switch(cl){
				case 'O':{
					gran.setcolor(1);	//--Azul--1--
					gran.setclasif(cl);
					gran.settemp("40.000-25.000k");
					break;
				}
				case 'B':{
					gran.setcolor(15);	// --Blanca--15--
					gran.setclasif(cl);
					gran.settemp("25.000-11.000k");
					break;
				}
				case 'A':{
					gran.setcolor(15);	// --Blanca--15--
					gran.setclasif(cl);
					gran.settemp("11.000-7.500k");
					break;
				}
				case 'F':{
					gran.setcolor(14);	//--Amarilla--14--
					gran.setclasif(cl);
					gran.settemp("7.500-6.000k");
					break;
				}
				case 'G':{
					gran.setcolor(14);	//--Amarilla--14--
					gran.setclasif(cl);
					gran.settemp("6.000-5.000k");
					break;
				}
				case 'K':{
					gran.setcolor(12);	//--Rojo claro--12--
					gran.setclasif(cl);
					gran.settemp("5.000-3.500k");
					break;
				}
				case 'M':{
					gran.setcolor(4);	//--Rojo--4---
					gran.setclasif(cl);
					gran.settemp("3.500-3.000k");
					break;
				}
			}
			
			
			break;
		}
		
		}
		cout<<"	|| ------------------------------------ ||"<<endl;
		cout<<" || 1 --> Editar otra cosa				||	"<<endl;
		cout<<" || 2 --> Volver al menu principal 		||"<<endl;
		
		cin>>f;
		if(f==2){
			c=0;
		}else{
			
		}
	}while(c!=0);
}

void Sistema::crearPlanetas(){
	//Crea y Asigna datos de cada objeto Planeta
	Planeta Tierra[8];
	for(int k=0;k<numeroP;k++){
	
		Tierra[k].asignarDatos(k);
		mat[k] = Tierra[k];
	}
}

void Sistema::animarSistema(int z){	
	int ejex,ejey,ejeauxx,ejeauxy;
	double Pi=3.1416;	
    int angle=0,op,vueltas=0;
	int val=1;
		do{
			if(mat[0].getcint() == 1){	//--Si hay Cinturon de Asteroides
				gran.cinturonAst();
			}
			setcolor(15);
			for(int k=1;k<=numeroP;k++){	//---Órbita Eliptica (linea)
			    		setfillstyle(EMPTY_FILL,15);
			    		fillellipse(getmaxx()/2,getmaxy()/2,k*70,k*40);
					}
			mat[0].putCometa(z*angle+100,mat[0].getcom());	//----Cantidad 'Cometas'
			    
				for(int i=0;i<=numeroP;i++){
			    	
			    	//---FORMULA!!...
			    	//  x=(int)floor(radio*cos((angulo*Pi/180.0))); 
			    	
			    		//variables aux para borrar 2 pixeles atras
							ejeauxx=(int)floor(val*70*cos((z*angle-2)*val*Pi/180.0));
							ejeauxy=(int)floor(val*40*sin((z*angle-2)*val*Pi/180.0));
						//variables para dibujar cuerpos
							ejex=(int)floor(val*70*cos((z*angle*val*Pi/180.0))); 
				   			ejey=(int)floor(val*40*sin((z*angle*val*Pi/180.0))); 
				   			
					   	// Estrella
							gran.crearEstrella(getmaxx()/2,getmaxy()/2,14);	
							setcolor(0);
						// Planeta
							mat[i].putPlanet(z*angle,ejex,ejey,ejeauxx,ejeauxy);
						// Lunas
							mat[i].putLunas(ejex,ejey,z*angle,ejeauxx,ejeauxy);
						// Asteroide
								if(mat[0].getast() == 1){
									mat[0].putAste(z*angle,50,70);
								}
							val = val + 1;
				}
				
				//-----------------------------------------------------------------------
				//------------fondo de estrelllas--------(poco optimo; se hizo hasta el final)
				//---------------------------------------
				// 'X' aumentado
				setcolor(14);
				gran.putEstrella(z*angle,+430,-10);
				gran.putEstrella(z*angle,320,-20);
				gran.putEstrella(z*angle,280,+50);
				gran.putEstrella(z*angle,530,-20);
				gran.putEstrella(z*angle,320,-100);
				gran.putEstrella(z*angle,280,-120);
				gran.putEstrella(z*angle,50,-100);
				gran.putEstrella(z*angle,80,-160);
				// 'Y' aumentado
				gran.putEstrella(z*angle,-10,+80);
				gran.putEstrella(z*angle,-20,+140);
				gran.putEstrella(z*angle,-30,+200);
				gran.putEstrella(z*angle,-45,+40);
				gran.putEstrella(z*angle,-65,+180);
				gran.putEstrella(z*angle,-85,+230);
				gran.putEstrella(z*angle,+10,+280);
				gran.putEstrella(z*angle,+20,+350);
				gran.putEstrella(z*angle,+30,+420);
				// 'X' reducido
				gran.putEstrella(z*angle,-430,-10);
				gran.putEstrella(z*angle,-320,-20);
				gran.putEstrella(z*angle,-280,+50);
				gran.putEstrella(z*angle,-530,-20);
				gran.putEstrella(z*angle,-320,-100);
				gran.putEstrella(z*angle,-280,-120);
				gran.putEstrella(z*angle,-50,-100);
				gran.putEstrella(z*angle,-80,-160);
				// 'Y' reducido
				gran.putEstrella(z*angle,-10,-80);
				gran.putEstrella(z*angle,-20,-140);
				gran.putEstrella(z*angle,-30,-200);
				gran.putEstrella(z*angle,-45,-40);
				gran.putEstrella(z*angle,-65,-180);
				gran.putEstrella(z*angle,-85,-230);
				gran.putEstrella(z*angle,+10,-280);
				gran.putEstrella(z*angle,+20,-350);
				gran.putEstrella(z*angle,+30,-420);
				// 'X' y 'Y' aumentadas
				gran.putEstrella(z*angle,+50,+80);
				gran.putEstrella(z*angle,+120,+140);
				gran.putEstrella(z*angle,+180,+200);
				gran.putEstrella(z*angle,+250,+240);
				gran.putEstrella(z*angle,+365,+380);
				gran.putEstrella(z*angle,+425,+450);
				gran.putEstrella(z*angle,+510,+530);
				gran.putEstrella(z*angle,+570,+600);
				gran.putEstrella(z*angle,+630,+670);
				// 'X' y 'Y' reducidos
				gran.putEstrella(z*angle,-50,-80);
				gran.putEstrella(z*angle,-120,-140);
				gran.putEstrella(z*angle,-180,-200);
				gran.putEstrella(z*angle,-250,-240);
				gran.putEstrella(z*angle,-365,-380);
				gran.putEstrella(z*angle,-425,-450);
			
				gran.putSistema();
				
				setcolor(0);
				//-----------------------------------------------------------------------
		   		val = 1;//---Para reiniciar el multiplicador a el tamaño de las orbitas
				  
				  
				  	  if(vueltas==1){	//--- si (angulo == 360  --> vueltas = 1)
						
						cout<<" 1--Volver al menu"<<endl;
						cout<<" 2--Continuar Viendo"<<endl;
						cin>>op;
								if(op==1){
									
									angle=361;
									op=0;
								}
								if(op==2){
									vueltas = 0;
								}
								
							}
					
						if(z==0){
							angle = angle + 2;
						}
				   		if(z==1){
				   			angle = angle + 1;
						}
			   
					if(angle==358){
						angle=0;
						vueltas = vueltas + 1;
					}
				delay(20);
		}while(angle<=360);       
}
