/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josevargas
 *
 * Created on October 23, 2020, 12:41 PM
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int* instanciarArregloEnteros(int);
bool primo(int);
void liberarArregloEnteros(int*&);
double potencia(double,int);
int factorial(int);

/*
 * 
 */
int main(int argc, char** argv) {
    int valid = true;
    while (valid){
        int option = 0;
        cout << "      MENU" << endl
             << "1. Ejercicio 1" << endl
             << "2. Ejercicio 2" << endl
             << "3. Ejercicio 3" << endl
             << "4. Salir" << endl
             << "Ingrese una opcion: ";
        cin >> option;
        switch(option){
            case 1:{
                int num,cont;
                cout << "Ingrese el numero a factorizar: ";
                cin >> num;
                int size = 25;
                int* arreglo;
                arreglo = instanciarArregloEnteros(size);
                if(arreglo!=NULL){
                    cout << num << " = ";
                    for(int i = 0; num > 1; i++){
                        cont = 0;
                        if(num % arreglo[i] == 0){
                            while(num % arreglo[i] == 0){
                                num/= arreglo[i];
                                cont++;
                            }
                            if(i == 0)
                                cout << arreglo[i] << "^" << cont;
                            else
                                cout << " * " << arreglo[i] << "^" << cont ;
                        }
                    }
                }
                liberarArregloEnteros(arreglo);
                cout << endl;
                break;
            }
            case 2:{
                double x, p, f;
                cout << "Ingrese el valor de x: ";
                cin >> x;
                double suma = 0;
                for(int n = 0; n < 20; n++){
                    p = potencia(x, n);
                    f = factorial(n);
                    suma += p/f;
                }
                cout <<"e^" << x << " = " <<suma << endl;
                break;
            }
            case 3:{
                int n;
                cout << "Ingrese el numero de filas: ";
                cin >> n;
                int pos = 0;
                int* arreglo2;
                arreglo2 = new int[n];
                if(arreglo2!=NULL)
                    for(int i =0;i<n;i++)
                        arreglo2[i] = 0;
                for(int j = 0; j<n; j++){
                    pos-=1;
                    for(int k = pos; k<n; k++){
                        if(k == pos || k == n-1){
                            arreglo2[k] = 1;
                        }
                        if(k != pos && k != n-1){
                            arreglo2[k]+= arreglo2[k+1];
                        }   
                    }
                    for(int l=n-1;l>=0;l--){
                        if(arreglo2[l] == 0){
                            
                        }else{
                            if(l == 0)
                                cout << arreglo2[l];
                            else
                                cout << arreglo2[l] << ", ";
                        }
                    }
                    cout << endl;
                    
                }
                liberarArregloEnteros(arreglo2);
                break;
            }
            case 4:{
                valid = false;
                break;
            }
        }
    }
    
    return 0;
}

int* instanciarArregloEnteros(int size){
    int* returnValue;
    returnValue = new int[size];
    returnValue[0] = 2; returnValue[1] = 3; returnValue[2] = 5; returnValue[3] = 7; returnValue[4] = 11; returnValue[5] = 13; returnValue[6] = 17; returnValue[7] = 19; returnValue[8] = 23; returnValue[9] = 29; returnValue[10] = 31; returnValue[11] = 37; returnValue[12] = 41; returnValue[13] = 43; returnValue[14] = 47; returnValue[15] = 53; returnValue[16] = 59; returnValue[17] = 61; returnValue[18] = 67; returnValue[19] = 71; returnValue[20] = 73; returnValue[21] = 79; returnValue[22] = 83; returnValue[23] = 89; returnValue[24] = 97;
    return returnValue;
}

void liberarArregloEnteros(int*& array){
    if(array!=NULL){
        delete[] array; 
        array = NULL;
    }
}

bool primo(int numero) {
    if (numero == 4) 
        return false;
    for (int x = 2; x < numero / 2; x++) {
        if (numero % x == 0) 
            return false;
    }
    return true;
}

double potencia(double x, int n){
    if (n==0)
        return 1.0;
    else
        return x*(potencia(x,n-1));
}

int factorial(int n) {
    if(n < 0) 
       return 0;
    else if(n > 1) 
       return n*factorial(n-1);
    return 1.0;
}
