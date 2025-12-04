#include<stdio.h>
#include<string.h>

void Boletos(){
	FILE* peliculas;
	FILE*temporal;
	char texto[1000]={};
	char nPelicula[30]={};
	int i = 0;
	char eleccion[30]={};
	peliculas = fopen("RegistroPelicula.txt", "r");	
	temporal = fopen("TemporalRegistro.txt", "w");	
	
	while(feof(peliculas) == 0){
		fgets(texto, 1000, peliculas);
		printf("%i %s", i, texto);	
		fprintf(temporal, "%i %s", i, texto);
		i++;
	}
	
	fclose(peliculas);
	fclose(temporal);
	printf("\nEscriba el numero de la película que le gustaria ver\n");
	fflush(stdin);
	scanf("%s", eleccion);
	
	temporal = fopen("TemporalRegistro.txt", "w");
	if(strcmp(eleccion, "0") == 0){
		printf("saliendo\n");
	
	}else{
		char numeroPelicula[30] = {};
		
		while(feof(temporal) == 0){
		fscanf(temporal, numeroPelicula);
			if(strcmp(numeroPelicula, eleccion) == 0){
				fscanf(temporal, numeroPelicula);
				printf("%s", numeroPelicula);
			}
		}	
	}

}





void CuentaUsuario(){

	int eleccion = 0;
	int salir = 0; 
	
	printf("Bienvenido usuario, seleccione el numero correspondiente\n");
	
	do{
		printf("Compra de boletos[1]\nRealizar comentario[2]\nComentarios de otras peliculas[3]\nCalificar una pelicula[4]\nVer calificaciones[5]\nCerrar sesion[0]\n");
		fflush(stdin);
		scanf("%i", &eleccion);
		
		switch(eleccion){
			case 0: 
				salir = 1;
			case 1:
				Boletos();
				break; 
				
			case 2:
			
			case 3:
			
			case 4: 
			
			case 5:
				
			default:
				printf("Por favor, seleccione una opcion válida\n");
				salir = 0;
				break; 
		}
	}while(salir == 0);
	
//	return 0; 
}