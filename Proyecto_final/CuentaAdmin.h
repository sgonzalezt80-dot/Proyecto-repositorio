#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ponerPelicula(){
	FILE *ap;
	FILE *hora; 
	char nombreP[30]={};
	char genero[20]={};
	char sinopsis[100]={};
	char duracion[20]={};
	char horario[10]={};
	char horario2[10]={};
	char sala[2]={};
	char sala2; 
	int confirmar = 2;
	int i = 0;
	do{
		printf("Nombre de la pelicula\n");
		setbuf(stdin, NULL);
		gets(nombreP);
		printf("Genero:\n");
		setbuf(stdin, NULL);
		gets(genero);
		printf("Sinopsis:\n");
		setbuf(stdin, NULL);
		gets(sinopsis);
		printf("Duracion:\n");
		setbuf(stdin, NULL);
		gets(duracion);
		printf("horarios, separados por un espacio\n");
		setbuf(stdin, NULL);
		scanf("%s %s", horario, horario2);
		printf("sala de proyeccion\n");
		
		setbuf(stdin, NULL);
		gets(sala);
				
		printf("Esta seguro?\nSI[1]\nNO[2]\nCancelar[3]");
		setbuf(stdin, NULL);
		
		scanf("%i", &confirmar);
	
	}while(confirmar == 2);
	//bug al intentar escribir el numero 1, el programa se detiene
	if(confirmar == 1){		
		
		sala2 = sala[0];
		int i = 0;
		char carp[20]={};
		char abrir[20]={};
		char pel[10]={"/pel/"};
		char txt[5]={".txt"};
		int longitud = 0;
		
		for(i = 0; i <= 4; i++){
			carp[i] = sala[i];
		}				
		longitud = strlen(carp);
		for(i = 0; i<=10; i++){
			carp[i+longitud] = pel[i];
		}		
		longitud = strlen(carp);	
		for(i=0; i<=30; i++){
			carp[i+longitud] = nombreP[i];		
		}					
		longitud = strlen(carp);
		for(i=0; i<=4; i++){
			carp[longitud+i] = txt[i]; 			
		}
		
		ap = fopen("RegistroPelicula.txt", "a"); 
		hora = fopen(carp, "w");
		fprintf(hora, "| %s |", nombreP);
		fprintf(hora, "\n%s", horario);
		fprintf(hora, "\n%s", horario2);
		fclose(hora);	
		
		fprintf(ap, "%s | ", nombreP);
		fprintf(ap, "%s | ", genero);
		fprintf(ap, "%s | ", sinopsis);
		fprintf(ap, "%s | ", duracion);
		//al intentar escribir el dato, no lo hace, ni con otra variable equivalente al dato original
		fprintf(ap, "%s | \n", sala2);
		fclose(ap);
	}
		
	return 0;
}

int registro(){
	FILE * rb;
	char texto[1000]={};
	int regresar = 0;
	
	do{
		//agregar funcion
		rb=fopen("RegistroBoletos.txt", "r");	
		while(feof(rb)==0){
			
			fgets(texto, 1000, rb);
			printf("%s", texto);
			
		}
		printf("\nRegresar al menu principal\nSI[1]\nNO[2]\n");
		scanf("%i", &regresar);
	}while(regresar == 2);
	return 0; 
}

int CuentaAdmin(){
	
	int accion = 0;
	int eleccion = 0;
	
	do{
		printf("Menu principal:\n");
		printf("Cerrar sesion[0] \nDar de alta una pelicula[1] \nVer Registro de usuarios y boletos[2] \n");
		fflush(stdin);
		scanf("%i", &accion);
		
		switch (accion){
			case 0:
				eleccion = 1;
				break; 
			case 1:
				eleccion = ponerPelicula();
				break; 
			case 2:
				eleccion = registro();
				break;
			default: 
				printf("Por favor escoja una opcion válida\n");
				eleccion = 0;
				break;
		}
	}while(eleccion == 0);
	
return 0;	
}