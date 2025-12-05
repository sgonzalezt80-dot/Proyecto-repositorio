#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void Boletos(){
	FILE* peliculas;
	FILE*temporal;
	char texto[10000]={};
	int i = 0;
	char eleccion[100]={};
	char numeroPelicula[10000] = {};
	int longitud = 0, longitud2 = 0;
	char peliculaAbrir[100] = {};
	
	char carpeta[100] ={};
	char txt[5]= {".txt"};
	char car[2]={'/'};
	char pel[10]= {"/Pel/"};
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
	
	if(strcmp(eleccion, "0") == 0){
		
		printf("saliendo\n");
		
	}else{
		temporal = fopen("TemporalRegistro.txt", "r");
		
		while(feof(temporal) == 0){
			fscanf(temporal, "%s", numeroPelicula);
								
			if(strcmp(numeroPelicula, eleccion) == 0){
				
				while(strcmp(numeroPelicula, "|") != 0){					
					fscanf(temporal, "%s", numeroPelicula);
					
					if(strcmp(numeroPelicula, "|") != 0){
						longitud = 0;
						longitud = strlen(numeroPelicula);					
							
						for(i = 0; i <= longitud + 1; i++){
							peliculaAbrir[i + longitud2] = numeroPelicula[i];
							
							if(i == longitud){
								longitud2 = strlen(peliculaAbrir);
								peliculaAbrir[longitud2] = ' ';
							}	
						}
						longitud2 = strlen(peliculaAbrir);
					}
				}	
				while(strcmp(numeroPelicula, "\n") != 0){					
					fscanf(temporal, "%s", numeroPelicula);
					
					if(strcmp(numeroPelicula, "A") == 0){
						carpeta[0] = numeroPelicula[0];
						carpeta[1] = car[0];
						break;
					}else{
						if(strcmp(numeroPelicula, "B") == 0){
							carpeta[0] = numeroPelicula[0];
							carpeta[1] = car[0];
							break;
						}else{
							if(strcmp(numeroPelicula, "V") == 0){
								carpeta[0] = numeroPelicula[0];
								carpeta[1] = car[0];
								break;
							}
						}
					}		
				}				
			}							
		}	
		fclose(temporal);
	}	
	
	longitud2 = strlen(carpeta);
	for(i = 0; i <= 40; i++){
		carpeta[longitud2 + i] = pel[i];
	}
	longitud2 = strlen(carpeta);
	for(i = 0; i <= 40; i++){
		carpeta[longitud2 + i] = peliculaAbrir[i];
	}
	longitud2 = strlen(carpeta);
	for(i = 0; i <= 5; i++){
		carpeta[longitud2 + i - 1] = txt[i];
	}
	char pelHora[1000]={};
	FILE* movie;
	FILE* temp;
	movie = fopen(carpeta, "r");
	temp = fopen("temporalRegistro.txt", "w");
	printf("Estos son los horarios\n");
	i = 0;
	while(feof(movie)==0){
		fgets(pelHora, 1000, movie);
		fprintf(temp, "%s", pelHora);
		printf("%s", pelHora);
		i++;
	}
	fclose(movie);
	fclose(temp);
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
				break;
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