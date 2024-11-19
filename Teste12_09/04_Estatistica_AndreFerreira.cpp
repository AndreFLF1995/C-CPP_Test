#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void inserir (int cont, float nota, float notas[], int NN);
void calcMedia (int NN, float media, float notas[]);
void notaMaxima (int NN, float maximo, float notas[]);
void notaMinima (int NN, float minimo, float notas[]);
bool saida (char opcao, bool sair);

int main() {
    
    const int NN = 2;
    float notas[9+NN];
    float media = 0, nota = 0, maximo = 0, minimo = 21;
    bool sair = false;
    char opcao = '\0';
    int cont = 0, cont2 = 0;
    
    for (int i = 0; i < (9+NN); i++){
        notas[i] = 0;
    }
    
    do {
        system ("cls");
        cout<<"********************************************"<<endl;
        cout<<"*            Estatisticas de Notas         *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*            1 - Inserir Notas.            *"<<endl;
        cout<<"*            2 - Apresentar Medias.        *"<<endl;
        cout<<"*            3 - Nota Maxima.              *"<<endl;
        cout<<"*            4 - Nota Minima.              *"<<endl;
        cout<<"*            0 - Sair.                     *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<endl;
        
        cout<<"Insira a opcao que quer: "<<endl;
        cin>>opcao;
        
        switch (opcao){
                        
           case '1':
                inserir (cont, nota, notas, NN);
           break;
           
           case '2':
                calcMedia (NN, media, notas);
           break;
           
           case '3':
                notaMaxima(NN, maximo, notas);
           break;
           
           case '4':
                notaMinima(NN, minimo, notas);
           break;
           
           case '0':
                sair = saida(opcao, sair);
           break;
           
           }
    }while (!sair);
        
        cout<<endl;
        cout<<"Obrigado por usar o programa! Adeus!!"<<endl;
        system("pause");
}

void inserir (int cont, float nota, float notas[], int NN){
cont = 0;
                   
    do {
    cout<<endl<<"Insira a "<<cont+1<<"a nota. (0-20)"<<endl;
    cin>>nota;
    
    if (nota < 0 || nota > 20) {
        cout<<"Insira um nota valida."<<endl;
        cout<<endl;
        continue;
        }
        
    notas[cont] = nota;
    cont++;
    } while (cont < (9+NN));
}

void calcMedia (int NN, float media, float notas[]){
cout<<endl;
    for (int i = 0; i < (9+NN); i++){
        media += notas[i];
        cout<<notas[i]<<endl;
        _sleep(200);
    }
    
    media /= (9+NN);
    
    cout<<endl;
    cout<<"Esta e a media das notas inseridas: "<<fixed<<setprecision(2)<<media<<endl;
    system("pause");
}

void notaMaxima (int NN, float maximo, float notas[]){
cout<<endl;
    for (int i = 0; i < (9+NN); i++){
        if (i == 0 || maximo < notas[i]){
           maximo = notas[i];
        }
    }
    
    cout<<endl;
    cout<<"Esta e a maior nota inserida: "<<fixed<<setprecision(2)<<maximo<<endl;
    system("pause");
}

void notaMinima (int NN, float minimo, float notas[]){
cout<<endl;
    for (int i = 0; i < (9+NN); i++){
        if (i == 0 || minimo > notas[i]){
           minimo = notas[i];
        }
    }
    
    cout<<endl;
    cout<<"Esta e a menor nota inserida: "<<fixed<<setprecision(2)<<minimo<<endl;
    system("pause");
}

bool saida (char opcao, bool sair){
cout<<"Tem a certeza que quer sair? (S/N)"<<endl;
cin>>opcao;
        
        if (opcao == 's' || opcao == 'S'){
             sair = true;
        }
        else{
             sair = false;
        }
return sair;
}
