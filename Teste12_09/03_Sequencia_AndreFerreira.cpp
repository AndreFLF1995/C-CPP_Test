#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    
    const int NN = 2;
    const int MAIOR = 33+NN;
    const int MENOR = 11-NN;
    int num = MENOR;
    
    do{
       cout<<num<<endl;
       num += 3;
       _sleep(200);
    }while (num < MAIOR);
    
    system("pause");
}
