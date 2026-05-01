#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INCIDENTS 50
enum boolean { False, True };
enum role { ADMIN = 1, USER = 2 };

// Estructuras
struct User {
    char username[20];
    char password[20];
    enum role access_level; 
};

// Base de Datos (Lista Simple para Arkham)
struct RecordData {
    int id_registro;
    char nombre[50];
    char nivel_riesgo[20]; 
    struct RecordData *nxt;
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
    struct AuditData audit_info;
    struct Node *nxt;  
};

struct Stack {
    struct Node *top;
    int count;
};

#include "utils.c"
#include "login.c"
#include "LoadCrimes.c"
#include "ReportCrime.c"
#include "WatchCrimes.c"
#include "SolveCrimes.c"
#include "SearchExp.c"
#include "LoadArkham.c"
#include "AgregarExpediente.c"
#include "EliminarExpediente.c"
#include "VerRegistros.c"
#include "StackAudit.c"
#include "Menu.c"

int main() {
    printf("\nIniciando sistemas GCPD...\n"); 
    menu();
    return 0;
}