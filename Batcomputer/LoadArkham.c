enum boolean LoadArkham(struct RecordData **h){
    int id;
    //char id[5]; 
    char name[50]; 
    char risk[20]; 

    //abre el archivo donde se encuentran los crimenes
    FILE *f = fopen("registroArkm.txt", "r");
    if(f == NULL) return False; 

    while(fscanf(f, "%d, %50[^,], %19[^\n]\n", &id, name, risk) == 3){//lee el archivo mientras encuentre datos que leer

        //reserva memoria
        struct RecordData *tmp = malloc(sizeof(struct RecordData));
        if(tmp == NULL){
            fclose(f);
            return False;
        } //cierra y te manda de regreso si falla

        //forma correcta de guardar el valor de una cadena con espacios en una variable tipo cadena 
        tmp -> id_registro = id;
        strcpy(tmp -> nombre, name);
        strcpy(tmp -> nivel_riesgo, risk);

        //Si no hay registros, *h se queda en el primero que lea la lista 
        if(*h == NULL){
            *h = tmp;
            tmp -> nxt = NULL;

        }else{ //para los demás registros se guarda aqui
            tmp -> nxt = (*h);
            (*h) = tmp; 
        }
        
    }
    fclose(f); 
    return True; 
}