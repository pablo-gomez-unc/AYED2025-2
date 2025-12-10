/**
 * @file main.cpp
 * @brief Programa principal que demuestra el uso de árboles de búsqueda binaria
 * @author Roberto Pablo Gomez
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @class nodo
 * @brief Clase que representa un nodo en un árbol binario
 * @tparam T Tipo de dato almacenado en el nodo
 */
template <class T> class nodo {
public:
    T info;        ///< Información almacenada en el nodo
    nodo* der;      ///< Puntero al hijo derecho
    nodo* izq;     ///< Puntero al hijo izquierdo
};

/**
 * @class arbol
 * @brief Clase que representa un árbol de búsqueda binaria
 * @tparam T Tipo de dato almacenado en el árbol
 */
template <class T> class arbol {
nodo<T>* raiz;  ///< Puntero a la raíz del árbol
void ArbolBusq(T x, nodo<T>*& nuevo);
void rid(nodo<T>* aux);
void ird(nodo<T>* aux);
void idr(nodo<T>* aux);
void getElemOrdenados(nodo<T>* aux, vector<int> &lista);
void show(nodo<T>* aux, int n);

public:
    /**
     * @brief Constructor por defecto
     */
    arbol() { raiz = NULL; };
    /**
     * @brief Destructor
     */
    ~arbol() {};
    /**
     * @brief Crea un árbol de búsqueda binaria
     * @param x Valor a insertar
     */
    void CreaArbolBus(T x);
    /**
     * @brief Recorrido preorden (RID)
     */
    void RID() { rid(raiz); }
    /**
     * @brief Recorrido inorden (IRD)
     */
    void IRD() { ird(raiz); }
    /**
     * @brief Recorrido postorden (IDR)
     */
    void IDR() { idr(raiz); }
    /**
     * @brief Muestra el árbol de forma visual
     */
    void VerArbol() { show(raiz, 0); }
    /**
     * @brief Obtiene los elementos ordenados
     * @param vec_ordenado Vector donde se almacenan los elementos ordenados
     */
    void GetElemOrdenados (vector<int> &vec_ordenado) {getElemOrdenados(raiz, vec_ordenado);}
};


template <class T> void arbol<T>::CreaArbolBus(T x)
{
    ArbolBusq(x, raiz);
}

template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo) // 5
{
    if (nuevo == NULL) {
        nuevo = new nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    if (x > nuevo->info) ArbolBusq(x, nuevo->der);
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq);
}

template <class T> void arbol<T>::ird(nodo<T>* aux)
{
    if (aux != NULL) {
        ird(aux->izq);
        cout << "\n" << aux->info;
        ird(aux->der);
    }
}
template <class T> void arbol<T>::rid(nodo<T>* aux)
{
    if (aux != NULL) {
        cout << "\n" << aux->info;
        rid(aux->izq);
        rid(aux->der);
    }
}
template <class T> void arbol<T>::idr(nodo<T>* aux)
{
    if (aux != NULL) {
        idr(aux->izq);
        idr(aux->der);
        cout << "\n" << aux->info;
    }
}

template <class T> void arbol<T>::getElemOrdenados(nodo<T>* aux, vector<int> &lista)
{
    if (aux != NULL) {
        getElemOrdenados(aux->izq, lista);
        lista.push_back(aux->info);
        getElemOrdenados(aux->der, lista);
    }
}

template <class T> void arbol<T>::show(nodo<T>* aux, int n)
{
    int i;
    if (aux != NULL) {                      //OjO este es un recorrido dri
        show(aux->der, n + 1);
        for (i = 1; i <= n; i++) cout << "     ";
        cout << aux->info << "\n";
        show(aux->izq, n + 1);
    }
}
//-------------------------------------------------------
int main(int argc, char* argv[])
{

    arbol<int> A;
    vector vec = {100, 4, 200, 10, 52,190, 220};

    //for (int i = 0; i < vec.size(); i++) {
    //    A.CreaArbolBus(vec[i]);
    //}

    //for (auto it = vec.begin(); it != vec.end(); ++it) {
    //    A.CreaArbolBus(*it);
    //}

    for (const int & elem : vec) {
        A.CreaArbolBus(elem);
    }
    A.VerArbol();

    vector<int> vec_ordenado = {};
    A.GetElemOrdenados (vec_ordenado);
    for (const int & elem : vec_ordenado) {
        cout << elem << " - ";
    }
    cout << endl;

    cout << "\n IRD--------------------------------";
    A.IRD();
    cout << "\n RID--------------------------------";
    A.RID();
    cout<<"\n IDR--------------------------------";
    A.IDR();

    cout << endl << endl;
    return EXIT_SUCCESS;
}