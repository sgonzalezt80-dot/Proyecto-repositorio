enum boolean SolveCrimes(struct IncidentData **h, struct IncidentData **t){
    int res; 
    struct IncidentData *tmp = NULL;

    //manda este mensaje en caso de que la cola este vacia
    if(*h == NULL){
        printf("No hay crimenes que resolver\n");
        return True; 
    }

    printf("Deseas fijar este crimen como objetivo?\n"); 
    printf("Prioridad %s: %s\n", (*h)->prioridad, (*h)->descripcion);
    printf("1) Si\n2) Regresar\n"); 
    
    res=get_val("Opcion: ");
    //quita el primer elemento de la cola (FIFO)
    if(res == 1){
        tmp = *h;

        if(*h == *t){ 
            *t = NULL;
            *h = NULL; 
            printf("Bien hecho caballero de la noche, no quedan más crimenes\n");

        }else{
            tmp = (*h); 
            (*h) = (*h) -> nxt; 
            printf("Bien hecho caballero de la noche. Incidente resuelto: %s\n", tmp->descripcion);
        }
        
        free(tmp);
    }else{
        return False; 
    }

    //sobre escribe el archivo el mismo modo que la lista
    FILE *f = fopen("crimes.txt", "w"); 

    if(*h != NULL){
        tmp = *h;
        while(tmp != NULL){
            fprintf(f, "%s, %s\n", tmp -> descripcion, tmp -> prioridad);
            tmp = tmp -> nxt;
        }
    }

    fclose(f);

    return True; 
}