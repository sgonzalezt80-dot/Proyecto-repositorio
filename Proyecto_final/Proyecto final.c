#include<stdio.h>
#include<stdlib.h>
#include "NuevoRegistro.h"
#include "inicioSesion.h"
#include "CuentaAdmin.h"
#include "CuentaUsuario.h"
//system("cls");

int inicio(){
//funcion que llama al menú principal
	int numero;
	int cuenta; 
	do{
		printf("Seleccione el numero correspondiente\n");
		printf("Nuevo registro[1]\nIngreso al sistema[2]\n");
		scanf("%i", &numero);
		
	}while (numero !=1 && numero !=2);
	return numero;
}

int main(){
	int eleccion;
	int cuenta = 3;	
	int regresar = 0;
	
	do{
	
		do{
			eleccion = inicio();
			
			switch(eleccion){
				case 1: 
					cuenta = NuevoRegistro();
					break;
				case 2:
					cuenta = InicioSesion();
					break; 
			}
		}while(cuenta == 3);
	
		if (cuenta == 1){
			regresar = CuentaAdmin();
			
		}else{
			CuentaUsuario();
			
		}
		
	}while(regresar == 0);
	
	
	return 0;	
}
