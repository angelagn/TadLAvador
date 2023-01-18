
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
    }
}

