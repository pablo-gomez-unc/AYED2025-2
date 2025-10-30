
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};

template <class T> class arbol {
nodo<T>* raiz;
void ArbolBusq(T x, nodo<T>*& nuevo);
void rid(nodo<T>* aux);
void ird(nodo<T>* aux);
void idr(nodo<T>* aux);
void getElemOrdenados(nodo<T>* aux, vector<int> &lista);
void show(nodo<T>* aux, int n);

public:
    arbol() { raiz = NULL; };
    ~arbol() {};
    void CreaArbolBus(T x);
    void RID() { rid(raiz); }
    void IRD() { ird(raiz); }
    void IDR() { idr(raiz); }
    void VerArbol() { show(raiz, 0); }
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