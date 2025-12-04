#include<stdio.h>
#include<string.h>

int InicioSesion(){
	char usuario[30]={};
	char contrasena[30]={};
	char comparar [50]={};
	FILE *fu;
	int regresar = 1; 
	
	int cuentaAdmin = 0;
	
	do{
		fu = fopen("UsuarioContrasena.txt", "r");
		fflush(stdin);
		printf("Ingrese su usuario\n");
		scanf("%s", &usuario);
		fflush(stdin);
		printf("Ingrese su contraseña\n");
		scanf("%s", &contrasena);
		
		//compaera si el usuario o contraseña es del admin
		if(strcmp(usuario, "elAdmin") == 0){
			if(strcmp(contrasena, "3l4dm1n") == 0){
				printf("Has ingresado con la cuenta del admin\n");
				cuentaAdmin = 1;
				regresar = 0;
				fclose(fu);
			}
		}
		//este ciclo compara que el usuario y la contraseña se den correctamente 
		if(cuentaAdmin == 0){
			if(fu != NULL){
				while(feof(fu) == 0){
					fscanf(fu, "%s", comparar);
				
					if(strcmp(comparar, usuario) == 0){						
																						
					fscanf(fu, "%s", comparar);	
					
						if(strcmp(comparar, contrasena) == 0){

						//	printf("El nombre de usuario y la contraseña son correctos\n");
							printf("Bienvenido\n");
							regresar = 0;
							cuentaAdmin = 0;
							fclose(fu);
							break;
						}				
					}
				}
				//printf("El usuario o la contraseña son incorrectos, inentelo de nuevo\n");
			}
		}
	}while(regresar == 1);
	
	return cuentaAdmin; 
}
