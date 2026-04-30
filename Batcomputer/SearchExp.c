enum boolean SearchExp(struct RecordData **h, int id){
    int i; 
    if(*h == NULL){
        printf("No hay registros\n");
        return False; 
    }
    
    struct RecordData *tmp = *h; 

    while(tmp != NULL){
        if(tmp -> id_registro == id){
            printf("Expediente encontrado\n");
            printf("%d, %s, %s\n", tmp -> id_registro, tmp -> nombre, tmp -> nivel_riesgo);
            return True;

        }
        tmp = tmp -> nxt; 
        
    }
    printf("El archivo no existe\n"); 
    return False;

}