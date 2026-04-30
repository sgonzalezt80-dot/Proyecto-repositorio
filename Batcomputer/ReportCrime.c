enum boolean ReportCrime(struct IncidentData **h, struct IncidentData **t){
    int error, ln; 
    char descrip[100];
    char prior[20];

    FILE *f = fopen("crimes.txt", "a"); /* "a" para hacer append =añadir al final del archivo
     si el archivo no existe, lo crea. Si existe, agrega al final sin borrar lo anterior.*/
    if (f ==  NULL){
        return False; 
    }

    do{
        error = 0;
        printf("Escriba el reporte del crimen, evite usar comas\n");
        scanf(" %149[^\n]", descrip); 
        //guarda el tamaño de la cadena       
        ln = strlen(descrip); 

        //evita que escriba reportes muy largos
        if(strlen(descrip) > 100){
            printf("Error, descripcion muy larga\n");
            error = 1;
        }

        //evita que escriba un reporte incluyendo una coma 
        for(int i = 0; i < ln; i++){
            if(descrip[i] == ','){
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
        printf("Escriba el nivel de prioridad, evite usar comas\n");
        scanf(" %49[^\n]", prior);
        ln = strlen(prior);
        //evita que escriba niveles de prioridad muy largos
        if(ln > 20){
            printf("Error, descripcion muy larga\n");
            error = 1;
        }
        // evita que incluya comas
        for(int i = 0; i < ln; i++){
            if(prior[i] == ','){
                printf("ERROR, Evite usar comas\n"); 
                error = 1; 
            }
        }

        while(getchar() != '\n');

    }while(error);

    //reserva memoria
    struct IncidentData *tmp = malloc(sizeof(struct IncidentData)); 
    if(tmp == NULL) return False; 

    //primer caso registrado
    if(*h == NULL){
        *h = tmp;
        *t = tmp;
        tmp -> nxt = NULL; 
        strcpy(tmp -> descripcion, descrip);
        strcpy(tmp -> prioridad, prior);
    
    //no es el primer caso   
    }else{
        strcpy(tmp -> descripcion, descrip);
        strcpy(tmp -> prioridad, prior);
        
        (*t) -> nxt = tmp;  
        tmp -> nxt = NULL;
        *t = tmp;         
    }

    //las guarda en archivo
    fprintf(f, "%s, %s\n", descrip, prior); 
    fclose(f);

    return True; 
}