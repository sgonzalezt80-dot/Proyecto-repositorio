#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INCIDENTS 50
enum boolean { False, True };
enum role { ADMIN = 1, USER = 2 };

//estrcutura de datos
// Usuario para Login
struct User {
    char username[20];
    char password[20];
    enum role access_level; // ADMIN o USER
    //enum role es un campo que indica el nivel de acceso del usuario, puede ser ADMIN o USER.
    // un campo de tipo enum es una variable que puede tomar un conjunto de valores predefinidos, en este caso ADMIN o USER, que se representan con los valores 1 y 2 respectivamente. esto permite diferenciar entre los diferentes tipos de usuarios y otorgarles diferentes permisos en el sistema.
};

// Base de Datos (Lista Doble)
struct RecordData {
    int id_registro;
    char nombre[50];
    char nivel_riesgo[20]; 
};

// Incidentes (Cola Simple)
struct IncidentData {
    int id_incidente;
    char descripcion[100];
    char prioridad[20];
    
    struct IncidentData *nxt;
};

// Auditoria (Pila LIFO)
struct AuditData {
    char operacion[100]; 
};

// Nodo Universal
struct Node {
    struct User user_info;
    struct RecordData record_info;
    struct IncidentData incident_info;
    struct AuditData audit_info;
    
    struct Node *nxt;  
    struct Node *prev; 
};
struct List {
    struct Node *head;
    struct Node *tail;
    int count;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int count;
};

struct Stack {
    struct Node *top;
    int count;
};

#include "utils.c"
#include "login.c"
#include "Menu.c"
// #include "database.c"
// #include "queue_incidents.c"
// #include "stack_audit.c"

//void menu();
int main() {
    printf("No se por que no corre si no pongo este mensaje\n"); 
    menu();
    return 0;
}