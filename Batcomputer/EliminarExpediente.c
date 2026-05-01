enum boolean EliminarExpediente(struct RecordData **h) {
    int opcion;
    if(*h == NULL) {
        printf("\n[!] No hay expedientes registrados.\n");
        return False; 
    }
    
    opcion = get_val("\nEscriba el ID del expediente a eliminar: ");
    
    struct RecordData *tmp = *h;
    struct RecordData *sup = NULL;
    
    // Si queremos eliminar el primer elemento (el head)
    if (tmp != NULL && tmp->id_registro == opcion) {
        *h = tmp->nxt;
        free(tmp);
        printf("\n[+] Expediente %d eliminado exitosamente.\n", opcion);
    } else {
        // Buscamos el elemento en el resto de la lista
        while (tmp != NULL && tmp->id_registro != opcion) {
            sup = tmp;
            tmp = tmp->nxt;
        }
        
        if (tmp == NULL) {
            printf("\n[!] Expediente no encontrado.\n");
            return False;
        }
        
        sup->nxt = tmp->nxt;
        free(tmp);
        printf("\n[+] Expediente %d eliminado exitosamente.\n", opcion);
    }

    // Sobrescribimos el archivo para reflejar los cambios
    FILE *f = fopen("registroArkm.txt", "w"); 
    if(f != NULL) {
        struct RecordData *curr = *h;
        while(curr != NULL) {
            fprintf(f, "%d, %s, %s\n", curr->id_registro, curr->nombre, curr->nivel_riesgo);
            curr = curr->nxt;
        }
        fclose(f);
    }
    return True; 
}