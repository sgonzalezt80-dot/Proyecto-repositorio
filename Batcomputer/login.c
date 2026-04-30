// Funcion para validar usuarios desde users.txt
// Retorna True si el acceso es correcto, False si falla.

enum boolean login_user(struct User *active_user) {
    FILE *file = fopen("users.txt", "r"); 
    // Abrimos el archivo users.txt en modo lectura "r"
    //El formato de cada linea es: username password access_level
    
    if (file == NULL) {
        printf("\n[!] ERROR: No se encontro el archivo users.txt\n");
        return False;
    }
    
    char input_user[20];
    char input_pass[20];
    
    printf("\n= LOGIN =\n");
    printf("Usuario: ");
    scanf("%19s", input_user); //  19 para  evitar el desbordamiento de memoria 
    printf("Contrasena: ");
    scanf("%19s", input_pass);
    
    struct User temp_user; // Variable temporal para almacenar los datos leidos del archivo
    int role_int; 
    
    // LEER el archivo linea por linea y comparamos con las credenciales ingresadas
    while (fscanf(file, "%19s %19s %d", temp_user.username, temp_user.password, &role_int) == 3) { //  lee linea por linea, guardando el username, password y access_level en temp_user y role_int respectivamente
    //En cada vuelta, agarra temporalmente un Usuario, una Contraseña y un Nivel de Acceso (1 o 2).
    //==3 porque esperamos leer 3 elementos por linea, si no se leen 3 elementos, se asume que es el final del archivo o un error de formato
        // Si las credenciales coinciden con la linea actual del .txt
        if (strcmp(input_user, temp_user.username) == 0 && strcmp(input_pass, temp_user.password) == 0) { 
        //strcmp= string compare de <string.h>
        /*Esta función compara dos textos; si son exactamente iguales, da como resultado 0.
        Compara el usuario y contr tecleado con el de la línea actual.*/
            
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