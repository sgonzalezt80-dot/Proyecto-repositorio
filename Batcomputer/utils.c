// no modificar utilidades
//filtro con manejo de errores y EOF 

int get_val(char *msg) { 
    /* Funcion para obtener un valor entero con manejo de errores estricto */
    int v; //v de valor, res de resultado de scanf
    printf("%s", msg);
    int res = scanf("%d", &v);
    if (res != 1) {
        if (res == EOF) {
            clearerr(stdin); // Limpia el error si  EOF (Ctrl+D, Ctrl+Z)
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Limpia el buffer de entrada
        }
        return -1; 
    }
    return v; // Devuelve el valor ingresado si es válido
}