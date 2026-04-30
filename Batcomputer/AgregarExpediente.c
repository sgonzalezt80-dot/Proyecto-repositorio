enum boolean AgregarExpediente(struct RecordData **h){  
    int opcion, error, ln; 
    char name[60];
    char risk[30];
    int id; 

    FILE *f = fopen("registroArkm.txt", "a");
    if (f ==  NULL){
        return False; 
    }

    //apuntador de apoyo
    struct RecordData *sup = *h; 
    do {
        printf("Escriba el id del expediente (solo numeros): ");
        if (scanf("%d", &id) != 1) {
            printf("Error: Ingresa un número válido.\n");
            error = 1;
        } else {
            error = 0;
        }
        if(SearchExp(&sup, id)){
            printf("Id existente, utilice otro\n");
            error = 1; 
        }

        while(getchar() != '\n'); 
    } while(error);

    do{
        error = 0;
        printf("Escriba el nombre del villano, evite usar comas\n");
        scanf(" %59[^\n]", name); 
        //guarda el tamaño de la cadena       
        ln = strlen(name); 

        //evita que escriba reportes muy largos
        if(strlen(name) > 50){
            printf("Error, linea muy larga\n");
            error = 1;
        }

        //evita que escriba un reporte incluyendo una coma 
        for(int i = 0; i < ln; i++){
            if(name[i] == ','){
                printf("ERROR, Evita usar comas\n"); 
                error = 1; 
                break; 
            }
        }
        while(getchar() != '\n'); 

    }while(error);

    setbuf(stdin, NULL);
    
    do{
        error = 0;
        printf("Escriba el nivel de peligro del villano, evite usar comas\n");
        scanf(" %49[^\n]", risk);
        ln = strlen(risk);
        //evita que escriba niveles de prioridad muy largos
        if(ln > 20){
            printf("Error, descripcion muy larga\n");
            error = 1;
        }
        // evita que incluya comas
        for(int i = 0; i < ln; i++){
            if(risk[i] == ','){
                printf("ERROR, Evite usar comas\n"); 
                error = 1; 
            }
        }

        while(getchar() != '\n');

    }while(error);

    //reserva memoria 
    struct RecordData *tmp = malloc(sizeof(struct RecordData)); 
    if(tmp == NULL) return False; 

    //primer caso registrado
    if(*h == NULL){
        *h = tmp;
        tmp -> nxt = NULL; 
        tmp -> id_registro = id; 
        strcpy(tmp -> nombre, name);
        strcpy(tmp -> nivel_riesgo, risk);
    
    //no es el primer caso   
    }else{
        tmp -> id_registro = id; 
        strcpy(tmp -> nombre, name);
        strcpy(tmp -> nivel_riesgo, risk);
         
        tmp -> nxt = (*h);
        *h = tmp; 
    }

    //las guarda en archivo
    fprintf(f, "%d, %s, %s\n", id, name, risk); 
    fclose(f);

    return True; 
}