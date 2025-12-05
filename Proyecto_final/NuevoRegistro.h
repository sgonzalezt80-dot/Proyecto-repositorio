#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int NuevoRegistro(){
	FILE *fp;
	FILE *fu;
	FILE *nuevo;
	char nombre [30] = {};
	char edad [4] = {};
	char usuario [21] ={};
	char contrasena[21] = {};
	char correo [25]={};
	char telefono [11]={};
	int respuesta = 0;
	int regresar = 0;
	char usuarioContrasena[40]={};
	char comparar[40]={};
	int cuenta = 3; 
	//abre las carpetas donde se almacenan los nombres de los usuarios
	fp = fopen("RegistroUsuarios.txt", "a");
	fu = fopen("UsuarioContrasena.txt", "r");
			

	do{
	fflush(stdin);
	//pide los datos de los usuarios
	printf("Ingrese su nombre, apellido paterno y materno separados por un espacio\n");
	gets(nombre);
	fflush(stdin);
	
	printf("ingrese su edad\n");
	gets(edad);
	fflush(stdin);
		
	printf("ingrese su nombre de usuario(no utilice espacios)\n");
	gets(usuario);
	fflush(stdin);
		
	printf("ingrese su contraseña\n");
	gets(contrasena);
	fflush(stdin);
		
	printf("Ingresa un correo electronico\n");
	gets(correo);
	fflush(stdin);
		
	printf("Ingresa un numero telefonico\n");
	gets(telefono);
	fflush(stdin);
	//muestra al usuario que los datos sean correctos
	printf("nombre: %s \nEdad:%s \nnombre de usuario:%s \nContraseña:%s \nCorreo:%s \nTelefono:%s", nombre, edad, usuario, contrasena, correo, telefono);
	printf("Son correctos estos datos?\nSI[1]\nNO[2]");
	scanf("%i", &respuesta);
		
	}while(respuesta == 2);
	//este dato debe mantenerse así para poder registrar al usuario	
	regresar = 1;
				
		if(fu != NULL){
			//entrar en este ciclo indicaria que el usuario repitió una contraseña, por lo que no podrá guardar sus datos
			while(feof(fu)==0){
				fscanf(fu, "%s", comparar);
				if(strcmp(comparar, usuario) == 0){
					regresar = 0; 
					printf("El nombre de usuario y/o la contraseña ya existen\n");
						printf("intentalo de nuevo\n");
						regresar = 0;
						cuenta = 3;
						break;	
					if(strcmp(comparar, contrasena)){
						printf("El nombre de usuario y/o la contraseña ya existen\n");
						printf("intentalo de nuevo\n");
						regresar = 0;
						cuenta = 3; 
						break;	
					}
				}
			}
		}	
		fclose(fu);

	if (regresar != 0){
		fu = fopen("UsuarioContrasena.txt", "a");	
		int longitud = 0;
		int i = 0;
		char usuariotxt[40] = {};
		char txt [5]={".txt"};
		char carpeta [11]={"Usuarios/"};
		longitud = strlen(usuario);
		//al nombre de usuario se le agrega al inicio "/Usuarios", para poder crear un archivo propio de él
		for(i = 0; i <= 10; i++){
			if(carpeta[i] != '\0'){
				usuariotxt[i] = carpeta[i];
			}	
		}	
		//se le agrega el ".txt" para crear un archivo de ese tipo
		for(i = 0; i <= longitud+5; i++){
				if(usuario[i] != '\0'){
				usuariotxt[i + 9] = usuario[i];
			}else{
				usuariotxt[i + 9] = txt[i-longitud];
			}
		}		
	//se crea el archivo y se guarda en la carpeta automaticamente 
		nuevo = fopen(usuariotxt, "w");
		
		fprintf(nuevo, "%s", nombre);
		fprintf(nuevo, " %s", usuario);
		
		fprintf(fp, "\n%s", nombre);
		fprintf(fp, " %s", edad);
		fprintf(fp, " %s", usuario);
		fprintf(fp, " %s", contrasena);
		fprintf(fp, " %s", correo);
		fprintf(fp, " %s", telefono);
		//guardan el usuario y la contraseña del usuario
		fprintf(fu, "\n%s", usuario);
		fprintf(fu, " %s\n##", contrasena);
		//cierra los archivos
		fclose(fp);
		fclose(fu);
		fclose(nuevo); 
		printf("Se ha registrado con éxito\n");
		cuenta = 0;	
	}
	return cuenta; 
}
