// Maneja el historial de operaciones de seguridad usando una Pila LIFO
// Cada operacion se guarda como un string en un nodo de la pila, y se mantiene un archivo de texto "audit.txt" para persistencia.

//Cargar historial desde archivo
enum boolean load_audit(struct Stack *s) {
    FILE *f = fopen("audit.txt", "r");
    if (f == NULL) return False; // Si no existe, inicia vacia
    
    char op[100];
    // Lee linea por linea hasta el salto de linea
    while (fscanf(f, " %99[^\n]", op) == 1) {
        struct Node *n = malloc(sizeof(struct Node));
        if (n == NULL) { fclose(f); return False; }
        
        strcpy(n->audit_info.operacion, op); // Copia la operacion leida al nodo
        
        // Push inicial -insertar al inicio de la pila
        n->nxt = s->top;
        s->top = n;
        s->count++;
    }
    fclose(f);
    return True;
}

// Registrar una nueva accion (Push)
enum boolean push_audit(struct Stack *s, char *nueva_operacion) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) return False;
    
    strcpy(n->audit_info.operacion, nueva_operacion);
    
    // Insercion en Pila (siempre en Top)
    n->nxt = s->top;
    s->top = n;
    s->count++;

    // Guardar cambio en el archivo de texto
    FILE *f = fopen("audit.txt", "a"); // "a" para hacer append =añadir al final
    if (f != NULL) {.

        fprintf(f, "%s\n", nueva_operacion);
        fclose(f);
    }
    return True;
}

// Revertir o auditar la ultima accion (Pop)
enum boolean pop_audit(struct Stack *s) {
    if (s->top == NULL) {
        printf("\n[!] Historial vacio. No hay acciones que auditar.\n");
        return False;
    }

    struct Node *tmp = s->top;
    printf("\n[!] ALERTA: Auditando y revirtiendo ultima accion -> %s\n", tmp->audit_info.operacion);
    
    // El Top ahora apunta al siguiente
    s->top = s->top->nxt;
    free(tmp);
    s->count--;

    // Actualiza el archivo de texto (Sobrescribe todo)
    FILE *f = fopen("audit.txt", "w");
    if (f != NULL) {
        struct Node *curr = s->top;
        while (curr != NULL) {
            fprintf(f, "%s\n", curr->audit_info.operacion);
            curr = curr->nxt;
        }
        fclose(f);
    }
    return True;
}

// Mostrar el historial (Mostrar Pila)
void show_audit(struct Stack *s) {
    if (s->top == NULL) {
        printf("\nEl historial de auditoria esta vacio.\n");
        return;
    }
    
    printf("\n= HISTORIAL DE AUDITORIA =\n");
    struct Node *tmp = s->top;
    int i = 1;
    while (tmp != NULL) {
        printf("Registro %d: %s\n", i, tmp->audit_info.operacion);
        tmp = tmp->nxt; // Recorremos de Top hacia abajo
        i++;
    }
}