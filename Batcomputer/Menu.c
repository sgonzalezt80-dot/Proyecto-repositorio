void menu(){
    int opcion_principal; 
    int opcion_submenu;
    int exp_id; 
    int opcion_quehacer; 
    int opcion_arkham;

    struct User sesion_actual; // Estructura para almacenar la informacion del usuario
    enum boolean logueado = False; // Es false por defecto, se vuelve true si el login es exitoso

    struct IncidentData *h = NULL; 
    struct IncidentData *t = NULL; 

    char audit_msg[100];

    // Carga la lista de crimenes [cola]
    if(!LoadCrimes(&h, &t)){
        printf("[!] Aviso: crimes.txt no encontrado o vacio. Iniciando cola limpia.\n");
    }

    // Apuntador del registro de villanos [lista]
    struct RecordData *hList = NULL;
    if(!LoadArkham(&hList)){
        printf("[!] Aviso: registroArkm.txt no encontrado o vacio. Iniciando lista limpia.\n");
    }

    // Carga el historial de auditoria [pila]
    struct Stack pila_auditoria;
    pila_auditoria.top = NULL;
    pila_auditoria.count = 0;
    load_audit(&pila_auditoria);

    while(1){
        printf("SISTEMA PRINCIPAL DE SEGURIDAD || GCPD\n");
        printf("1) Iniciar sesion\n2) Salir\n");
        opcion_principal = get_val("Que desea realizar?: "); 
        
        if(opcion_principal == 1){
            logueado = login_user(&sesion_actual); 
            
            if (logueado == True) {
                push_audit(&pila_auditoria, "Usuario inicio sesion en el sistema");
                
                //  SUBMENU ADMIN 
                if (sesion_actual.access_level == ADMIN) { 
                    int en_sesion = 1;
                        
                    while (en_sesion == 1) {
                        printf("\nAcceso de administrador concedido: BATCOMPUTADORA \n");
                        printf("Bienvenido(a), %s\n", sesion_actual.username); 
                        printf("1) Base de Datos Arkham\n"); 
                        printf("2) gestionar incidentes en Gotham\n"); 
                        printf("3) Auditoria del batsistema\n"); 
                        printf("4) Logout\n");
                        
                        opcion_submenu = get_val("Que desea realizar?: "); 
                        
                        switch(opcion_submenu){
                            case 1:
                                printf("\n|Cargando Base de Datos Arkham...|\n"); 
                                printf("Que desea hacer\n");
                                printf("1) Ver los registos\n2) Agregar un nuevo expediente\n3) Buscar un expediente\n4) Eliminar un expediente\n5) Regresar\n");
                                opcion_arkham = get_val("Opcion: ");

                                switch(opcion_arkham){
                                    case 1:
                                        VerRegistros(&hList);
                                        sprintf(audit_msg, "[%s] consulto la base de datos de Arkham", sesion_actual.username);
                                        push_audit(&pila_auditoria, audit_msg);
                                        break;
                                    case 2:
                                        AgregarExpediente(&hList);
                                        sprintf(audit_msg, "[%s] agrego un nuevo expediente a Arkham", sesion_actual.username);
                                        push_audit(&pila_auditoria, audit_msg);
                                        break;
                                    case 3:
                                        exp_id = get_val("Escriba el id del expediente: ");
                                        if(!SearchExp(&hList, exp_id)){
                                            printf("Expediente no encontrado\n"); 
                                        }
                                        sprintf(audit_msg, "[%s] busco un expediente especifico", sesion_actual.username);
                                        push_audit(&pila_auditoria, audit_msg);
                                        break;
                                    case 4:
                                        EliminarExpediente(&hList);
                                        sprintf(audit_msg, "[%s] elimino un expediente clasificado", sesion_actual.username);
                                        push_audit(&pila_auditoria, audit_msg);
                                        break;
                                    case 5:
                                        break;
                                }
                                break;

                            case 2:
                                printf("\n|Accediendo a la gestion de incidentes en Gotham...|\n");
                                printf("1) Reportar incidente\n2) Ver todos los crimenes\n3) Fijar Objetivo\n4) Salir\n");
                                opcion_quehacer = get_val("Opcion: ");

                                if(opcion_quehacer == 1){
                                    ReportCrime(&h, &t);
                                    sprintf(audit_msg, "[%s] reporto un incidente en la red", sesion_actual.username);
                                    push_audit(&pila_auditoria, audit_msg);
                                }else if(opcion_quehacer == 2){
                                    WatchCrimes(&h, &t); 
                                    sprintf(audit_msg, "[%s] reviso los incidentes activos", sesion_actual.username);
                                    push_audit(&pila_auditoria, audit_msg);
                                }else if(opcion_quehacer == 3){
                                    SolveCrimes(&h, &t);
                                    sprintf(audit_msg, "[%s] resolvio un incidente", sesion_actual.username);
                                    push_audit(&pila_auditoria, audit_msg);
                                }
                                break;
                                
                            case 3:
                                printf("\n|Cargando modulo de auditoria...|\n");
                                printf("1) Ver historial completo\n2) Revertir/Eliminar ultima accion \n3) Regresar\n");
                                int opcion_auditoria = get_val("Opcion: ");
                                
                                if(opcion_auditoria == 1){
                                    show_audit(&pila_auditoria);
                                } else if(opcion_auditoria == 2){
                                    pop_audit(&pila_auditoria);
                                }
                                break;
                                
                            case 4:
                                en_sesion = 0; 
                                logueado = False;
                                sprintf(audit_msg, "[%s] cerro sesion del sistema", sesion_actual.username);
                                push_audit(&pila_auditoria, audit_msg);
                                printf("\nCerrando sesion de Admin ...\n");
                                break;
                                
                            default: 
                                printf("\n[!] Opcion invalida [!]\n");
                        }
                    }
                }
                // SUBMENU POLICIA 
                else if (sesion_actual.access_level == USER) {
                    int en_sesion = 1;
                    while (en_sesion == 1) {
                        printf("\n=== Acceso concedido: TERMINAL GCPD ===\n");
                        printf("Oficial en turno: %s\n", sesion_actual.username);
                        printf("1) Consultar Base de Datos Arkham\n");
                        printf("2) Reportar Incidente\n");
                        printf("3) Ver lista de incidentes\n"); 
                        printf("4) Cerrar Sesion\n");
                            
                        opcion_submenu = get_val("Que desea realizar?: ");

                        switch(opcion_submenu) {
                            case 1:
                                printf("\n|Consultando base de datos...|\n");
                                VerRegistros(&hList);
                                sprintf(audit_msg, "[%s] consulto base de datos", sesion_actual.username);
                                push_audit(&pila_auditoria, audit_msg);
                                break;
                            case 2:
                                ReportCrime(&h, &t);
                                sprintf(audit_msg, "[%s] reporto un incidente", sesion_actual.username);
                                push_audit(&pila_auditoria, audit_msg);
                                break;
                            case 3:
                                WatchCrimes(&h, &t);
                                sprintf(audit_msg, "[%s] reviso incidentes", sesion_actual.username);
                                push_audit(&pila_auditoria, audit_msg);
                                break;
                            case 4:
                                en_sesion = 0; 
                                logueado = False;
                                sprintf(audit_msg, "[%s] cerro sesion", sesion_actual.username);
                                push_audit(&pila_auditoria, audit_msg);
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
            return; 
        }else{
            printf("\n[?] Opcion invalida. Intente de nuevo\n");
        }
    }
}
