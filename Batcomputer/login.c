// Funcion para validar usuarios desde users.txt
// Retorna True si el acceso es correcto, False si falla.

enum boolean login_user(struct User *active_user) {
    FILE *file = fopen("users.txt", "r"); 
    // Abrimos el archivo en modo lectura, se asume que users.txt esta en el mismo directorio que el ejecutable
    //El formato de cada linea es: username password access_level
    
    if (file == NULL) {
        printf("\n[!] ERROR: No se encontro el archivo users.txt\n");
        return False;
    }
    
    char input_user[30];
    char input_pass[30];
    
    printf("\n= LOGIN =\n");
    printf("Usuario: ");
    scanf("%29s", input_user); //  29 para  evitar el desbordamiento de memoria 
    printf("Contrasena: ");
    scanf("%29s", input_pass);
    
    struct User temp_user; // Variable temporal para almacenar los datos leidos del archivo
    int role_int; 
    
    // LEER el archivo linea por linea y comparamos con las credenciales ingresadas
    while (fscanf(file, "%29s %29s %d", temp_user.username, temp_user.password, &role_int) == 3) { 
        //==3 porque esperamos leer 3 elementos por linea, si no se leen 3 elementos, se asume que es el final del archivo o un error de formato
        
        // Si las credenciales coinciden con la linea actual del .txt
        if (strcmp(input_user, temp_user.username) == 0 && strcmp(input_pass, temp_user.password) == 0) {
            
            // Copiamos los datos al usuario activo que se esta usando en menu.c
            strcpy(active_user->username, temp_user.username);
            strcpy(active_user->password, temp_user.password);
            active_user->access_level = role_int;
            
            fclose(file);
            return True; // Exito
        }
    }
    
    fclose(file);
    printf("\n[!] Acceso denegado. Credenciales incorrectas\n");
    return False; // Fracaso
}