const int MaxEstados = 10;
typedef enum EstadoLavadora{parada, prelavado, lavado, centrifugado, vacio};
typedef EstadoLavadora VectorEstados[MaxEstados];
Typedef struct Lavadora{
    void InicializarMemoria();
    void GuardarEnMememoria(EstadoLavadora est);
    void Recetear();
    bool CambiarDeEstado(EstadoLavadora actualEstado, EstadoLavadora nuevoEstado);
    void ListarEstados();
    private:
        EstadoLavadora estado;
        VectorEstados memoria;

};

void Lavadora::InicializarMemoria(){
    for (int i=0; i<MaxEstados; i++){
        memoria[i]= vacio;
    }
}

void Lavadora::GuardarEnMememoria(EstadoLavadora est){
    bool encontrado= false;
    int indice =0;
    while (!encontrado &&(indice<MaxEstados))
    {
        if (memoria[indice]== vacio){
            encontrado = true;
        }
        indice++;
        
    }
    
    /*Si se encuentra hueco*/
    if (encontrado == true){
        memoria[indice-1] = est;
    }else{
        /*Memoria llena, se mueve un lugar hacia la izq*/
        for (int i=0; i<MaxEstados; i++){
            if(i != MaxEstados -1){
                memoria[i]= memoria[i+1];
            }
        }
        memoria[MaxEstados-1]= est;
    }
}

/*Cambia el estado actual de la lavadora y el estado al que se quiere cambiar y devuelve cierto*/
bool Lavadora::CambiarDeEstado(EstadoLavadora actualEstado, EstadoLavadora nuevoEstado){
    bool cambioRealizado = false;
    actualEstado = estado;
    switch(actualEstado){
        case parada:
        if((nuevoEstado == prelavado) || (nuevoEstado == lavado)){
            estado = nuevoEstado;
            GuardarEnMememoria(estado);
            cambioRealizado = true;
        }
        break;
        case prelavado:
        if ((nuevoEstado == centrifugado)||(nuevoEstado == lavado)){
        estado= nuevoEstado;
        GuardarEnMememoria(estado);
        cambioRealizado= true;
        }
        break;
        case lavado:
        if(nuevoEstado == centrifugado){
            estado = nuevoEstado;
            GuardarEnMememoria(estado);
            cambioRealizado = true;
        }
        break;
        case centrifugado:
        if (nuevoEstado == parada){
            estado = nuevoEstado;
            GuardarEnMememoria(estado);
            cambioRealizado = true;
        }
        break;
        default:
        ;
    }
    return cambioRealizado;
}

/*Imprime por pantalla los estados almacenados en la memoria*/

void lavadora::ListarEstados(){
    for (int i=0; i=MaxEstados; i++){
        switch(memoria[i]){
            case parada:
            printf("Estado %d; parada \n" i+1);
            break;
            case prelavado:
            printf("Estado %d; prelavado \n" i+1);
            break;
            case lavado:
            printf("Estado %d; lavado\n" i+1);
            break;
            case centrifugado:
            printf("Estado %d; parada \n" i+1);
            break;
            case vacio:
            printf("Estado %d; parada \n" i+1);
            break;
        }
    }
}