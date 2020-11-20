#include <iostream>
#include "../tl/Gestor.h"
#include "utilitario/Validar.h"

using namespace std;

Gestor gestor;
Validar validar;
void menu();
void procesarMenu(int &, bool &);
void menuSecundario();
void procesarMenuSecundario(int &, bool &);
void menuInsertUser();
void procesarMenuInsertUser(int &, bool &);
void menuInserAuto();
void procesarMenuInserAuto(int &, bool &);
int ingresarNum(string);
void insertVerAristCase1();
void insertVerAristCase2();
void insertVerAristCase3();
void insertVerticeUser();
void insertaAristaUser();
void listaAdyacencia();
void eliminarArista();
void eliminarVertice();
void eliminarGrafo();
void tamanio();
void recorridoAnchura();
void recorridoProfundidad();
void primeroAnchura();

int main() {
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú Árbol\n\nElija una opción\n" <<
             "01 Agregar vértice y aristas\n" <<
             "02 Imprimir\n" <<
             "03 Tamaño\n" <<
             "04 Eliminar vértice\n" <<
             "05 Eliminar arista\n" <<
             "06 Eliminar grafo\n" <<
             "07 Recorrido en anchura\n" <<
             "08 Recorrido en profundidad\n" <<
             "09 Primero en anchura\n" <<
             "10 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            menuSecundario();
            break;
        case 2:
            listaAdyacencia();
            break;
        case 3:
            tamanio();
            break;
        case 4:
            eliminarVertice();
            break;
        case 5:
            eliminarArista();
            break;
        case 6:
            eliminarGrafo();
            break;
        case 7:
            recorridoAnchura();
            break;
        case 8:
            recorridoProfundidad();
            break;
        case 9:
            primeroAnchura();
            break;
        case 10:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
void menuSecundario() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú de carga\n\nElija una opción\n" <<
             "01 Agregar por usuario\n" <<
             "02 Carga automática\n" <<
             "03 Volver al menú principal\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenuSecundario(opcion, salir);
    } while (!salir);
}
void procesarMenuSecundario(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            menuInsertUser();
            break;
        case 2:
            menuInserAuto();
            break;
        case 3:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
void menuInsertUser() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú de carga manual\n\nElija una opción\n" <<
             "01 Agregar vértice\n" <<
             "02 Agregar arista\n" <<
             "03 Volver al menu anterior\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenuInsertUser(opcion, salir);
    } while (!salir);
}
void procesarMenuInsertUser(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            insertVerticeUser();
            break;
        case 2:
            insertaAristaUser();
            break;
        case 3:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
void menuInserAuto() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú de carga automática\n\nElija una opción\n" <<
             "01 Cargar caso 1\n" <<
             "02 Cargar caso 2\n" <<
             "03 Cargar caso 3\n" <<
             "04 Volver al menu anterior\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenuInserAuto(opcion, salir);
    } while (!salir);
}
void procesarMenuInserAuto(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            insertVerAristCase1();
            break;
        case 2:
            insertVerAristCase2();
            break;
        case 3:
            insertVerAristCase3();
            break;
        case 4:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
int ingresarNum(string msg){
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1){
            cout << "El valor ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}
void insertVerticeUser(){
    int entradas;
    cout << "Ingrese el número de vértices que va a ingresar\n";
    cin >> entradas;
    string vertice;
    for (int i = 1; i <= entradas; ++i) {
        cout << "Ingrese el nombre del vértice " << i << "\n";
        cin >> vertice;
        gestor.insertVertice(vertice);
    }
    cout << "La carga se realizó satisfactoriamente.\n";
}
void insertaAristaUser(){
    int entradas;
    cout << "Ingrese el número de aristas que va a ingresar\n";
    cin >> entradas;
    string salida, llegada;
    string msg3 = "Ingrese el peso del vértice\n";
    int peso;
    for (int i = 1; i <= entradas; ++i) {
        cout << "Ingrese el nombre de la vértice de salida " << i << "\n";
        cin >> salida;
        cout << "Ingrese el nombre de la vértice de llegada " << i << "\n";
        cin >> llegada;
        peso = ingresarNum(msg3);
        gestor.insertaArista(salida, llegada, peso);
    }
    cout << "La carga se realizó satisfactoriamente.\n";
}
void insertVerAristCase1(){
    // inserción de vértices
    gestor.insertVertice("Guadalajara");
    gestor.insertVertice("Puebla");
    gestor.insertVertice("DF");
    gestor.insertVertice("Zacatecas");
    gestor.insertVertice("Michoacan");
    gestor.insertVertice("Los Cabos");
    // inserción de aristas
    gestor.insertaArista("Guadalajara", "DF", 500);
    gestor.insertaArista("Guadalajara", "Zacatecas", 200);
    gestor.insertaArista("Guadalajara", "Los Cabos", 600);
    gestor.insertaArista("Puebla", "Michoacan", 100);
    gestor.insertaArista("Puebla", "DF", 500);
    gestor.insertaArista("DF", "Los Cabos", 200);
    gestor.insertaArista("Zacatecas", "Puebla", 300);
    gestor.insertaArista("Zacatecas", "Los Cabos", 800);
    gestor.insertaArista("Michoacan", "Guadalajara", 400);
    gestor.insertaArista("Michoacan", "DF", 300);
    gestor.insertaArista("Los Cabos", "Michoacan", 300);
    cout << "La carga se realizó satisfactoriamente. Para ver reportes vuelva al menú principal\n";
}
void insertVerAristCase2(){
    // inserción de vértices
    gestor.insertVertice("A");
    gestor.insertVertice("B");
    gestor.insertVertice("C");
    gestor.insertVertice("D");
    gestor.insertVertice("E");
    gestor.insertVertice("F");
    gestor.insertVertice("G");
    // inserción de aristas
    gestor.insertaArista("A", "A", 13);
    gestor.insertaArista("A", "D", 18);
    gestor.insertaArista("B", "B", 52);
    gestor.insertaArista("B", "C", 17);
    gestor.insertaArista("B", "D", 83);
    gestor.insertaArista("B", "F", 97);
    gestor.insertaArista("B", "G", 60);
    gestor.insertaArista("C", "A", 4);
    gestor.insertaArista("D", "B", 97);
    gestor.insertaArista("D", "C", 37);
    gestor.insertaArista("D", "D", 22);
    gestor.insertaArista("D", "E", 41);
    gestor.insertaArista("D", "G", 64);
    gestor.insertaArista("E", "B", 8);
    gestor.insertaArista("E", "E", 45);
    gestor.insertaArista("E", "F", 92);
    gestor.insertaArista("F", "A", 8);
    gestor.insertaArista("F", "B", 45);
    gestor.insertaArista("F", "E", 42);
    gestor.insertaArista("G", "D", 17);
    cout << "La carga se realizó satisfactoriamente. Para ver reportes vuelva al menú principal\n";

}
void insertVerAristCase3(){
    // inserción de vértices
    gestor.insertVertice("TIJ");
    gestor.insertVertice("MTY");
    gestor.insertVertice("MZT");
    gestor.insertVertice("BJX");
    gestor.insertVertice("GDL");
    gestor.insertVertice("SAN");
    gestor.insertVertice("TAM");
    gestor.insertVertice("MEX");
    gestor.insertVertice("CUN");
    gestor.insertVertice("MID");
    // inserción de aristas
    gestor.insertaArista("TIJ", "MTY", 800);
    gestor.insertaArista("MTY", "BJX", 700);
    gestor.insertaArista("MZT", "TIJ", 400);
    gestor.insertaArista("MZT", "BJX", 300);
    gestor.insertaArista("BJX", "SAN", 900);
    gestor.insertaArista("BJX", "TAM", 400);
    gestor.insertaArista("BJX", "MEX", 350);
    gestor.insertaArista("GDL", "MZT", 500);
    gestor.insertaArista("GDL", "MTY", 450);
    gestor.insertaArista("GDL", "BJX", 250);
    gestor.insertaArista("GDL", "MEX", 500);
    gestor.insertaArista("SAN", "MID", 1200);
    gestor.insertaArista("TAM", "MID", 450);
    gestor.insertaArista("MEX", "MID", 450);
    gestor.insertaArista("MEX", "CUN", 650);
    gestor.insertaArista("CUN", "GDL", 650);
    cout << "La carga se realizó satisfactoriamente. Para ver reportes vuelva al menú principal\n";
}

void listaAdyacencia(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        cout << "La lista de adyacencia es...\n";
        gestor.listaAdyacencia();
    }
}
void eliminarVertice(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vértice que desea eliminar\n";
        cin >> vertice;
        cout << gestor.eliminarVertice(vertice);
    }
}
void eliminarArista(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string salida, llegada;
        cout << "Ingrese la ciudad de salida\n";
//        getline(cin, salida, '\n');
        cin >> salida;
        cout << "Ingrese la ciudad de llegada\n";
//        getline(cin, llegada, '\n');
        cin >> llegada;
        gestor.eliminarArista(salida, llegada);
        cout << "Proceso completado satisfactoriamente\n";
    }

}
void eliminarGrafo(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        gestor.anular();
    }

}
void tamanio(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        cout << "La matriz de adyacencia tiene " + to_string(gestor.tamanio()) + " vértices\n";
    }
}
void recorridoAnchura(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string nombre;
        cout << "Ingrese el nombre del vértice inicial\n";
        cin.ignore();
        getline(cin, nombre, '\n');
        gestor.recorridoAnchura(nombre);
    }
}
void recorridoProfundidad(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string nombre;
        cout << "Ingrese el nombre del vértice inicial\n";
        cin.ignore();
        getline(cin, nombre, '\n');
        gestor.recorridoProfundidad(nombre);
    }
}
void primeroAnchura(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string origen, destino;
        cout << "Ingrese el nombre del vértice origen\n";
        cin >> origen;
//        cin.ignore();
//        getline(cin, origen, '\n');
        cout << origen << endl;
        cout << "Ingrese el nombre del vértice destino\n";
        cin >> destino;
//        cin.ignore();
//        getline(cin, destino, '\n');
//        cout << destino << endl;
        gestor.primeroAnchura(origen, destino);
    }
}