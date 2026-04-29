#include "Batman.c"

void menu(){
    int opcion_principal;
    // cambiar el valor de loggin
    int loggin = 1;
    int opcion_batman;
    int opcion_normal;

    while(1){
        printf("Que desea realizar?\n1) Iniciar sesion\n2) Salir\n");
        scanf("%d", &opcion_principal);

        if(opcion_principal == 1){
            //manda a login
            //este scanf es para pruebas
            scanf("%d", &loggin); 
        }else{
            return;
        }

        if(loggin == 1){    // lleva a las opciones de batman
            while(loggin == 1){
                printf("Bienvenido batman\nQue desea realizar\n1) opcion1\n2) opcion2\n3) Salir\n");
                scanf("%d", &opcion_batman);
                switch(opcion_batman){
                    case 1:

                        break;
                    case 2:
                
                        break;
                
                    case 3:
                        loggin = 0; //reinicia la variable para romper el ciclo
                        printf("Vuelva pronto\n");
                        break;
                }
            }
        }else{  // lleva a las opciones de los policias 
            printf("Bienvenido al sistema del DPCG\nQue desea hacer?\n1) opcion1\n2) opcion2\n3)opcion3 ");
            scanf("%d", &opcion_normal); 
            while(loggin == 2){
                switch(opcion_normal){
                    case 1:

                        break;

                    case 2:

                        break;
                    
                    case 3:
                        // reinicia la variable para romper el ciclo 
                        loggin = 0;
                        break;
                }
            }
        }
    }

    //int opcion_principal;
    //struct User sesion_actual

}