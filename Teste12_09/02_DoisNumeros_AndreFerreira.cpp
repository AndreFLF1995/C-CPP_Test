#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void operacao (float, float, int);

int main()
{
    float num1 = 0, num2 = 0;
    const int NN = 2;

    cout<<"***************************************************************"<<endl;
    cout<<"*                           Dois Numeros                      *"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"Dependo dos numeros que coloque ira ter uma operacao diferente."<<endl;
    do {
        cout<<"\n\nInsira o primeiro numero: \n";
        cin>>num1;
        cout<<"\n\nInsira o segundo numero: \n";
        cin>>num2;
        if (num1 < (3-NN) || num1 > (53+NN) || num2 < (3-NN) || num2 > (53+NN)){
           cout<<"Insira numeros entre "<<3-NN<<" e "<<53+NN<<endl;
        }
    }while(num1 < (3-NN) || num1 > (53+NN) || num2 < (3-NN) || num2 > (53+NN));
    
    operacao(num1, num2, NN);

    system("pause");
}

void operacao (float num1, float num2, int NN){
    
    if (num1 < (20+NN) && num2 < (20+NN)){
           cout<<"Subtracao"<<endl;
           cout<<"O resultado e: "<<num1-num2<<endl;
        }
    else if (num1 > (40+NN) && num2 > (40+NN)){
         cout<<"Divisao"<<endl;
       cout<<"O resultado e: "<<fixed<<setprecision(2)<<num1/num2<<endl;
    }
    else{
         cout<<"Multiplicacao"<<endl;
       cout<<"O resultado e: "<<num1*num2<<endl;
    }
}
