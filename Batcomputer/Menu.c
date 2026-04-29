#include "Batman.c"


void menu(){
    FILE *f; 
    
    f = fopen("users.txt", "a+");

    char user[20] ={};
    while(strcmp(user, "yawe")){
        printf("Ingresa tu usuario\n");
        scanf("%s", user);

        fprintf(f, "%s\n", user);

    }

    while(0){

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