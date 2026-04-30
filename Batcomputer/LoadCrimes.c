enum boolean LoadCrimes(struct IncidentData **h, struct IncidentData **t){
    char descrip[100]; 
    char prior[20]; 

    //abre el archivo donde se encuentran los crimenes
    FILE *f = fopen("crimes.txt", "r");
    if(f == NULL) return False; 

    while(fscanf(f, " %99[^,], %19[^\n]\n", descrip, prior) == 2){//lee el archivo mientras encuentre datos que leer

        //reserva memoria
        struct IncidentData *tmp = malloc(sizeof(struct IncidentData));
        if(tmp == NULL){
            fclose(f);
            return False;
        } //cierra y te manda de regreso si falla

        //forma correcta de guardar el valor de una cadena con espacios en una variable tipo cadena 
        strcpy(tmp -> descripcion, descrip);
        strcpy(tmp -> prioridad, prior);
        tmp -> nxt = NULL;

        //Si no hay crimenes, *h se queda en el primero que lea la lista 
        if(*h == NULL){
            *h = tmp;
            *t = tmp;
            
        }else{ //para los demás crimenes se guarda aqui
            (*t) -> nxt = tmp;
            *t = tmp;
        }
    }
    fclose(f); 
    return True; 
}