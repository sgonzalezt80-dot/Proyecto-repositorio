enum boolean VerRegistros(struct RecordData **h){

    //Si la lista esta vacia regresa
    if(*h == NULL){
        printf("No hay registros\n");
        return False; 

    }    
    
    struct RecordData *tmp = (*h);

    while(tmp != NULL){
        printf("%d, %s, %s\n", tmp -> id_registro, tmp -> nombre, tmp -> nivel_riesgo);

        tmp = tmp -> nxt;
    }   

    return True; 
}