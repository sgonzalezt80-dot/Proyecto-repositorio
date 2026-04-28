#include "Batman.c"


void menu(){
    
    char user[20] ={};

    printf("Ingresa tu usuario\n");
    scanf("%s", user);

    while(1){

        if(strcmp(user, "batman") == 0){
            printf("Iron man apesta\n");
            Batman();
        }else{
            if(strcmp(user, "GCPD") == 0){
                printf("welcome\n");

            }else{
                printf("No le sabes");
            }
        }
    }

}