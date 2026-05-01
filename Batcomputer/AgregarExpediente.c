enum boolean AgregarExpediente(struct RecordData **h) {  
    int error, ln; 
    char name[50];
    char risk[20];
    int id; 

    FILE *f = fopen("registroArkm.txt", "a");
    if (f == NULL) return False; 

    struct RecordData *sup = *h; 
    do {
        id = get_val("\n[ARKHAM] Escriba el ID del expediente (solo numeros): ");
        error = 0;
        
        if(SearchExp(&sup, id) == True) {
            printf("[!] Error: ID existente, utilice otro.\n");
            error = 1; 
        }
    } while(error);

    do {
        error = 0;
        printf("[ARKHAM] Escriba el nombre del villano (sin comas): ");
        scanf(" %49[^\n]", name); 
        ln = strlen(name); 

        for(int i = 0; i < ln; i++) {
            if(name[i] == ',') {
                printf("[!] ERROR: Evita usar comas.\n"); 
                error = 1; 
                break; 
            }
        }
        while(getchar() != '\n'); 
    } while(error);
    
    do {
        error = 0;
        printf("[ARKHAM] Escriba el nivel de peligro (sin comas): ");
        scanf(" %19[^\n]", risk);
        ln = strlen(risk);

        for(int i = 0; i < ln; i++) {
            if(risk[i] == ',') {
                printf("[!] ERROR: Evite usar comas.\n"); 
                error = 1; 
            }
        }
        while(getchar() != '\n');
    } while(error);

    struct RecordData *tmp = malloc(sizeof(struct RecordData)); 
    if(tmp == NULL) return False; 

    tmp->id_registro = id; 
    strcpy(tmp->nombre, name);
    strcpy(tmp->nivel_riesgo, risk);
    
    if(*h == NULL) {
        tmp->nxt = NULL; 
        *h = tmp;
    } else {
        tmp->nxt = *h;
        *h = tmp; 
    }

    fprintf(f, "%d, %s, %s\n", id, name, risk); 
    fclose(f);
    printf("\n[+] Expediente agregado con exito.\n");
    return True; 
}