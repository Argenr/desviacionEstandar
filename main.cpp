#include <iostream>
#include <cmath>

struct Nodo {
    double valor;
    Nodo* siguiente;
    Nodo(double v) : valor(v), siguiente(nullptr) {}
};
void insertar(Nodo*& cabeza, double valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;}
double calcularMedia(Nodo* cabeza, int tamano) {
    if (tamano == 0) return 0.0;
    double suma = 0.0;
    Nodo* actual = cabeza;
    while (actual) {
        suma += actual->valor;
        actual = actual->siguiente; }
    return suma / tamano;
}

double calcularDesviacionEstandar(Nodo* cabeza, int tamano, double media) {
	if (tamano <= 1) return 0.0;  // Evita división por cero si hay una sola muestra
	double sumaDiferenciasCuadradas = 0.0;
	Nodo* actual = cabeza;
	while (actual) {
		sumaDiferenciasCuadradas += pow(actual->valor - media, 2);
		actual = actual->siguiente;
	}
	return sqrt(sumaDiferenciasCuadradas / (tamano - 1));  // Corrección de Bessel
}

void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp; }
}

int main() {
    Nodo* cabeza = nullptr;
    int n;
    double numero;
    
    std::cout << "Ingrese la cantidad de numeros ";
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese un numero: ";
        std::cin >> numero;
        insertar(cabeza, numero);
    }
    
    double media = calcularMedia(cabeza, n);
    std::cout << "Media: " << media << std::endl;
    std::cout << "Desviacion estandar: " << calcularDesviacionEstandar(cabeza, n, media) << std::endl;
    
    liberarLista(cabeza);
    
    return 0;
}
