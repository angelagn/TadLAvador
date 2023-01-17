const int MaxEstados = 10;
typedef enum EstadoLavadora{parada, prelavado, lavado, centrifugado, vacio};
typedef EstadoLavadora VectorEstados[MaxEstados];
Typedef struct Lavadora{
    void InicializarMemoria();
    void GuardarEnMemeoia(EstadoLavadora est);
    void Recetear();
    bool CambiarDeEstado(EstadoLavadora actualEstado, EstadoLavadora nuevoEstado);
    void ListarEstados();
    private:
        EstadoLavadora estado;
        VectorEstados memoria;

};

