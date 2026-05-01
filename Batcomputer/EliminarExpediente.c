enum boolean EliminarExpediente(struct RecordData **h){
    int opcion;

    if(*h == NULL){
        printf("No hay archivos\n");
        return False;
    }   

    struct RecordData *tmp = *h; 
    struct RecordData *sup; 

    printf("Escriba el id del expediente que desea eliminar\n"); 
    scanf("%d", &opcion);

    if(!SearchExp(&tmp, opcion)){
        printf("No fue posible eliminar\n");
        return False; 

    }else{
        if((*h) -> id_registro == opcion){
            (*h) = (*h) -> nxt;
            free(tmp); 
            //return True; 

        }else{
            do{
                sup = tmp;
                tmp = tmp -> nxt;
                if(tmp -> id_registro == opcion){
                    sup -> nxt = tmp -> nxt; 
                    tmp -> nxt = NULL; 
                    free(tmp);
                    tmp = NULL; 
                    printf("Se elimino con exito\n");
                    break; 
                    //return True;
                }

            }while(tmp != NULL);

        }

        FILE *f = fopen("registroArkm.txt", "w"); 

        if(*h != NULL){
            tmp = *h;
            while(tmp != NULL){
                fprintf(f, "%d, %s, %s\n", tmp-> id_registro, tmp -> nombre, tmp -> nivel_riesgo);
                tmp = tmp -> nxt;
            }
        }

        fclose(f);
    }
}