void Batman(){
    int opciones; 

    while(1){
        printf("Bienvenido batman, que desea hacer\n");
        printf("1)\n2)\n3)\n4)\n");
        scanf("%d", &opciones);


        switch(opciones){
            case 1:
                printf("Revisar base de datos\n");
                break;
            case 2:
                printf("Atender caso\n");
                break;
            case 3:
                printf("Recoger 100000 trofeos de enigma\n");
                break;
            case 4:
                printf("Alfred the buttler with two T's\n");
                return;
        }
    }
}