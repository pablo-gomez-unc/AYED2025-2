
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <functional>
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
    void ird(nodo<T>* aux, function<void(nodo<T>*)> f);
    void dri(nodo<T>* aux, int nivel, function<void(nodo<T>*,int)> f); // es un ird invertido
    void idr(nodo<T>* aux);
    void bfs(nodo<T>* aux);
    void borrar(nodo<T>*& aux, T x);
    void borrar_aux(nodo<T>*& aux, nodo<T>*& q);
    T menor(nodo<T>* aux);
    bool buscar(nodo<T>* aux, T x);
public:
    arbol() { raiz = NULL; };
    ~arbol() {};
    void CreaArbolBus(T x);
    void RID() { rid(raiz); }
    void IRD( function<void(nodo<T>*)> f) { ird(raiz, f); }
    void IDR() { idr(raiz); }
    void BFS() { bfs(raiz); }
    void VerArbol() {
        dri(raiz, 0, [](nodo<T>* n, int nivel){
            cout << string(nivel * 4, ' ') << n->info << endl;
        });
    }
    void Borrar(T x) { borrar(raiz, x); }
    T Menor() { return menor(raiz); }
    bool Buscar(T x) { return buscar(raiz, x); }
};

template <class T> void arbol<T>::CreaArbolBus(T x){
    ArbolBusq(x, raiz);
}

template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo)
{
    if (nuevo == NULL) {
        nuevo = new nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    if (x > nuevo->info) ArbolBusq(x, nuevo->der);
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq);
}

template <class T> void arbol<T>::ird(nodo<T>* aux, function<void(nodo<T>*)> f)
{
    if (aux == NULL) return;
    ird(aux->izq, f);
    f(aux);
    ird(aux->der, f);
}

template <class T> void arbol<T>::dri(nodo<T>* aux, int nivel, function<void(nodo<T>*,int)> f){
    if (aux == NULL) return;
    dri(aux->der, nivel+1, f);
    f(aux, nivel);
    dri(aux->izq, nivel+1, f);
}

template <class T> void arbol<T>::rid(nodo<T>* aux)
{
    if (aux == NULL) return;
    cout << aux->info << " ";
    rid(aux->izq);
    rid(aux->der);
}

template <class T> void arbol<T>::idr(nodo<T>* aux)
{
    if (aux == NULL) return;

    idr(aux->izq);
    idr(aux->der);
    cout << aux->info << " ";
}

template <class T> void arbol<T>::bfs(nodo<T>* aux)
{
    if (aux == NULL) return;

    queue<nodo<T>*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        nodo<T>* actual = cola.front(); cola.pop();

        cout << actual->info << " " ;

        if (actual->izq != NULL)
            cola.push(actual->izq);
        if (actual->der != NULL)
            cola.push(actual->der);
    }
}

template <class T> bool arbol<T>::buscar(nodo<T>* aux, T x)
{
    if (aux == NULL) return false;
    if (x > aux->info) return buscar(aux->der, x);
    if (x < aux->info) return buscar(aux->izq, x);
    return true;
}

template <class T> T arbol<T>::menor(nodo<T>* aux)
{
    if (aux->izq == NULL) return aux->info;
    return menor(aux->izq);
}

template <class T> void arbol<T>::borrar(nodo<T>*& aux, T x)
{
    if (!aux) {
        cout << "El dato" << x << " NO pertenece al arbol" << endl;
        return;
    }

    if (x > aux->info) {
        borrar(aux->der, x);
        return;
    }
    if (x < aux->info) {
        borrar(aux->izq, x);
        return;
    }

    nodo<T>* q = aux;
    if (q->der == NULL) aux = q->izq;
    else if (q->izq == NULL) aux = q->der;
    else borrar_aux(q->izq, q);
    delete q;
}

template <class T> void arbol<T>::borrar_aux(nodo<T>*& aux, nodo<T>*& q)
{
    if (!aux->der) {
        q->info = aux->info;
        q = aux;
        aux = aux->izq;
        return;
    }
    borrar_aux(aux->der, q);
}

//-------------------------------------------------------

int main()
{
    int i,x;
    arbol<int> A;
    int vec[10] = { 10, 6, 15, 4, 8, 11, 16, 2, 5, 9 };
    for (i = 0; i < 10; i++) {
        A.CreaArbolBus(vec[i]);
    }
    A.VerArbol();

    A.IRD([](nodo<int>* n){ cout << n->info << " "; });
    cout <<  endl << "--------------------------------" << endl;
    A.RID();
    cout<<  endl << "--------------------------------"<< endl;
    A.IDR();
    cout<<  endl << "--------------------------------"<< endl;
    A.BFS();
    cout<<  endl << "--------------------------------"<< endl;

    cout << "Mostrar Hojas ----------";
    A.IRD([](nodo<int>* n){ 
        if (n->izq == NULL && n->der == NULL) cout << n->info << " "; 
    });
    cout << endl;

    cout << "El menor del arbol= " << A.Menor() << endl;

    if (A.Buscar(95)) cout << "El dato 95 esta" << endl;
    else cout << "El dato 95 NO esta" << endl;

    for(i=0;i<5;i++){
        cout<<"Ingrese dato a borrar = "; cin>>x;
        cout<<endl;
        A.Borrar(x);
        A.VerArbol();
    }

    return EXIT_SUCCESS;
}
