void WatchCrimes(struct IncidentData **h, struct IncidentData **t){
    int i = 1;

    //si la cola esta vacia no hay crimenes 
    if(*h == NULL){
        printf("Bien hecho, no hay crimenes\n");
        return; 
    }   
    struct IncidentData *tmp = *h; 
    
    //imprime los datos de la cola
    while(tmp != NULL){
        printf("%d, %s, %s\n", i, tmp -> descripcion, tmp -> prioridad);

        tmp = tmp -> nxt;
        i += 1;
    }   
}