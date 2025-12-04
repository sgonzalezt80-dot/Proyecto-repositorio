#include <stdio.h>
#include <string.h>

int ponerPelicula(){
	FILE *ap;
	FILE *hora; 
	char nombreP[30]={};
	char genero[20]={};
	char sinopsis[100]={};
	char duracion[10]={};
	char horario[40]={};
	char sala[10]={};
	int confirmar = 2;
	
	do{
		printf("Nombre de la pelicula\n");
		fflush(stdin);
		gets(nombreP);
		printf("Genero:\n");
		fflush(stdin);
		gets(genero);
		printf("Sinopsis:\n");
		fflush(stdin);
		gets(sinopsis);
		printf("Duracion:\n");
		fflush(stdin);
		gets(duracion);
		printf("horario(s)\n");
		fflush(stdin);
		gets(horario);
		printf("sala de proyeccion\n");
		fflush(stdin);
		gets(sala);
		printf("Esta seguro?\nSI[1]\nNO[2]\nCancelar[3]");
		fflush(stdin);
		scanf("%i", &confirmar);
		
	}while(confirmar == 2);
	
	if(confirmar == 1){
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
		printf("%s\n", carp);

		ap = fopen("RegistroPelicula.txt", "a"); 
		hora = fopen(carp, "w");
		fprintf(hora, "%s | ", nombreP);
		fprintf(hora, "%s | ", horario);
		fclose(hora);
		
		fprintf(ap, "%s | ", nombreP);
		fprintf(ap, "%s | ", genero);
		fprintf(ap, "%s | ", sinopsis);
		fprintf(ap, "%s | ", duracion);
		//fprintf(ap, "%s | ", horario);
		fprintf(ap, "%s | \n", sala);
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