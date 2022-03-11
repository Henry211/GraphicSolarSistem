#include "estrella.h"
#include <math.h>
#include <iostream>
#include <winbgim.h>
#include<stdlib.h>
#include<time.h>

void Estrella::crearEstrella(int posx, int posy, int radio){
	setfillstyle(SOLID_FILL,colorE);//---Dibuja estrella
	fillellipse(posx,posy,radio,radio);
	
}

void Estrella::putEstrella(int an,int x, int y){

		int a, b, c, d, e, f, ejex, ejey,ejeauxx,ejeauxy;
		double Pi=3.1416;
		//--Variables alteradas para simular aletoriedad

		a = x*2;
		b = y*2;
		c = x+50;
		d = y+500;
		e = x+600;
		f = y*3;
		
		//--Se dibuja y se borran los siguientes 6 pixeles;
		//--Se alteran para simular aletoriedad
		putpixel((an-1)*2+x,(an-1)*2+y,0);
		putpixel(an*2+x,an*2+y,14);
		
		putpixel((an-1)*3+c,(an-1)*3+d,0);
		putpixel(an*3+c,an*3+d,14);
		
		putpixel((an-1)*2+a,(an-1)*2+d,0);
		putpixel(an*2+a,an*2+d,14);
		
		putpixel((an-1)+e,(an-1)+f,0);
		putpixel(an+e,an+f,14);
		
		putpixel((an-1)+a,(an-1)+b,0);
		putpixel(an+a,an+b,14);
		
		putpixel((an-1)+400+f,(an+f-1),0);
		putpixel(an+400+f,an+f,14);
	//----------------------------------------------

}

void Estrella::putSistema(){	//---SISTEMAS SOLARES DE FONDO
	   	circle(150,150,1);
	   	circle(650,650,1);
	   	circle(900,300,1);
	   	
	   	setfillstyle(EMPTY_FILL,1);
		fillellipse(650,650,20,10);
		fillellipse(150,150,20,10);
		fillellipse(900,300,20,10);
		fillellipse(650,650,15,5);
		fillellipse(150,150,15,5);
		fillellipse(900,300,15,5);	
}
void Estrella::cinturonAst(){	//---CINTURON DE ASTEROIDES---
     double Pi=3.1416;
     int  x = getmaxx()/2, y = getmaxy()/2;	//-coordenadas centro
     int ejex,ejey,contador = 1; 
     for(int angulo=0;angulo<=360;angulo++){    
	  
	 
			//---posiciones de la elipse
         	ejex=(int)floor(250*cos((angulo*Pi/180.0))); 
	   		ejey=(int)floor(140*sin((angulo*Pi/180.0))); 
       
       
		//-------------------------------------------------
		 //-- En un intento de evitar lineas continuas y patrones en el cinturon;
		 //-- se optó por agregar un contador que cada '8' posiciones, el pixel se coloque en otro lugar;
		 //-- ésto para simular aletoriedad en la colocación de los pixeles del cinturon
		 switch(contador){
		 	case 1:{
           		putpixel(x+ejex+7,y-ejey-8,15);
				break;
			 }
			 case 2:{
			 	putpixel(x+ejex-4,y-ejey-8,15);
				break;
			 }
			 case 3:{
            	putpixel(x+ejex-8,y-ejey-4,15);
				break;
			 }
			 case 4:{
            	putpixel(x+ejex-6,y-ejey-3,15);
				break;
			 }
			 case 5:{
			 	putpixel(x+ejex-3,y-ejey+4,15);
				break;
			 }
			 case 6:{
           		putpixel(x+ejex-4,y-ejey-8,15);
				break;
			 }
			 case 7:{
            	putpixel(x+ejex-4,y-ejey+6,15);
				break;
			 }
			 case 8:{
            	putpixel(x+ejex+4,y-ejey+2,15);
            	contador = 0;
				break;
			 }
		 }
         contador = contador + 1; 	
	 }   
}
