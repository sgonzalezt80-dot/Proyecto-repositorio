void menu(){
    int opcion_principal; 
    int opcion_submenu;
    int exp_id; 
    int opcion_quehacer; 
    int opcion_arkham;



    struct User sesion_actual; // Estructura para almacenar la información del usuario que se loguea
    enum boolean logueado = False; //es false por defecto, se vuelve true si el login es exitoso}

    struct IncidentData *h = NULL; 
    struct IncidentData *t = NULL; 
    int success; 

    //carga la lista de crimenes [cola]
    if(!(success = LoadCrimes(&h, &t))){
        printf("Error de acceso 1\n");
        return;
    }

    //Apuntador del registro de villanos
    struct RecordData *hList = NULL;
    
    //carga la lista de villanos
    if(!(success = LoadArkham(&hList))){
        printf("Error de acceso 2\n");
        return;
    }

    //carga el historial de auditoria [pila]
    struct Stack pila_auditoria;
    pila_auditoria.top = NULL;
    pila_auditoria.count = 0;
    load_audit(&pila_auditoria);

    while(1){
        printf("SISTEMA PRINCIPAL DE SEGURIDAD || GCPD\n");
        printf("1) Iniciar sesion\n2) Salir\n");
        opcion_principal = get_val("Que desea realizar?: "); //no scanf, get_val para manejo de errores
        //get_val es una funcion que se encuentra en utils.c, sirve para validar que el usuario ingrese un numero y no una letra o así, 
        //ademas de evitar el desbordamiento de memoria
        
        if(opcion_principal == 1){
            logueado = login_user(&sesion_actual); //logueado es una variable booleana que se vuelve true si el login es exitoso
            /*login_user es una funcion que se encuentra en login.c, sirve para validar el login del usuario
            recibe un puntero a una estructura User para guardar la informacion del usuario que se logueo
            
            devuelve True si el login es exitoso y False si no lo es*/
            if (logueado == True) {
            //batman interfaz jeje
                if (sesion_actual.access_level == ADMIN) { // .access_level es un campo de la estructura User que indica el nivel de acceso del usuario
                    int en_sesion = 1;// variable para controlar el ciclo de sesión del administrador, es 1 mientras el administrador esté en sesión y se vuelve 0 cuando el administrador decide salir
                        
                    while (en_sesion == 1) {
                        printf("\nAcceso de administrador concedido: BATCOMPUTADORA \n");
                        printf("Bienvenido, %s\n", sesion_actual.username); 
                        printf("1) Base de Datos Arkham\n"); // lista 
                        printf("2) gestionar incidentes en Gotham\n"); //cola
                        printf("3) Auditoria del batsistema\n"); //pila
                        printf("4) Logout\n");

                        opcion_submenu = get_val("Que desea realizar?: "); //sin int porque se va a reutilizar la variable para los diferentes submenus, ademas de que no es necesario declarar una nueva variable para cada submenu
                        switch(opcion_submenu){
                            case 1:
                                printf("\n|Cargando Base de Datos Arkham...|\n"); //pon algo cool en estas pls
                                printf("Que desea hacer\n");
                                printf("1) Ver los registos\n2) Agregar un nuevo expediente\n3) Buscar un expediente\n4) Eliminar un expediente\n5) Salir\n");
                                scanf("%d", &opcion_arkham);

                                    switch(opcion_arkham){
                                    case(1):
                                        VerRegistros(&hList);

                                        break;

                                    case(2):
                                        AgregarExpediente(&hList);

                                        break;
                                    
                                    case(3):
                                        printf("Escriba el id del expediente\n");
                                        scanf("%d", &exp_id);
                                        if(!SearchExp(&hList, exp_id)){
                                            printf("Expediente no encontrado\n"); 
                                            break; 
                                        }
                                        break;

                                    case(4):
                                        EliminarExpediente(&hList);
                                       
                                        break;
                                    case(5):
                                        //falta salir
                                        break;
                                }
                                break;


                            case 2:
                                printf("\n|Accediendo a la gestion de incidentes en Gotham...|\n");
                                printf("1) Reportar incidente\n2) Ver todos los crimenes\n3) Fijar Objetivo\n4) Salir\n");
                                opcion_quehacer= get_val("Opcion: ");

                                if(opcion_quehacer == 1){
                                    ReportCrime(&h, &t);
                                }else if(opcion_quehacer == 2){
                                    WatchCrimes(&h, &t); 
                                }else if(opcion_quehacer == 3){
                                    SolveCrimes(&h, &t);
                                 }
                                break;
                            case 3:
                                printf("\n|Cargando modulo de auditoria...|\n");
                                break;
                            case 4:
                                en_sesion = 0; 
                                logueado = False;
                                printf("\nCerrando sesion de Admin ...\n");
                                break;
                            default: 
                                printf("\n[!] Opcion invalida [!]\n");
                    }
                }
            }else if (sesion_actual.access_level == USER) {
                int en_sesion = 1;
                while (en_sesion == 1) {
                    printf("\nAcceso concedido: TERMINAL GCPD\n");
                    printf("Bienvenido Oficial %s\n", sesion_actual.username);
                    printf("1) Consultar Base de Datos Arkham\n");
                    printf("2) Reportar Incidente\n");
                    printf("3) Ver lista de incidentes\n"); 
                    printf("4) Cerrar Sesion\n");
                        
                    opcion_submenu = get_val("Que desea realizar?: ");

                    switch(opcion_submenu) {
                        case 1:
                            printf("\n|consultando base de datos...|\n");// de nuevo pon algo cool y asi
                            break;
                        case 2:
                            ReportCrime(&h, &t);
                            break;

                        case 3:
                            WatchCrimes(&h, &t);
                            break;

                        case 4:
                            en_sesion = 0; // Rompe el ciclo del submenu
                            logueado = False;
                            printf("\nCerrando sesion de Usuario ...\n");
                            break;

                        default:
                            printf("\n[!] Opcion invalida [!]\n");
                        }
                    }
                }
            }
        }else if (opcion_principal == 2) {
            printf("\nApagando sistema...  Manten Gotham a salvo\n");
            return; // Salimos de la funcion menu y el programa termina limpiamente

        }else{
        printf("\n[?] Opcion invalida. Intente de nuevo\n");
        }
    }
}