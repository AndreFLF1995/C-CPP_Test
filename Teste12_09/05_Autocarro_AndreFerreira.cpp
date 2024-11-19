#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void listarLugar (int FILA, int LUGAR, string LIVRE, string lugares[7][4]);
int reservarLugar (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string RESERVADO, string LIVRE);
int marcarLugar (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string MARCADO, string LIVRE);
int libertarLugar (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string LIVRE);
int chegada (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string LIVRE);
bool saida (char opcao, bool sair);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    const string LIVRE = "Livre";
    const string RESERVADO = "Reservado";
    const string MARCADO = "Marcado";
    const int FILA = 7;
    const int LUGAR = 4;
    string lugares[FILA][LUGAR];
    bool sair = false;
    char opcao = '\0';
    bool lugaresOcupados = false;
    int numLugaresOcupados = 0;
    
    for (int i = 0; i < FILA; i++){
        for (int j = 0; j < LUGAR; j++){
        lugares[i][j] = LIVRE;    
    	}   
    }


do {
    system ("cls");
    cout<<"********************************************"<<endl;
    cout<<"*                  Autocarro               *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*            1 - Listar Lugares.           *"<<endl;
    cout<<"*            2 - Reservar Lugar.           *"<<endl;
    cout<<"*            3 - Marcar Lugar.             *"<<endl;
    cout<<"*            4 - Libertar Lugar.           *"<<endl;
    cout<<"*            5 - Chegada.                  *"<<endl;
    cout<<"*            0 - Fim de Sessão.            *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    if (lugaresOcupados)
	   {
	   cout<<"**************************************"<<endl;
	   cout<<"*                                    *"<<endl;
	   cout<<"*      Não há Lugares Disponíveis    *"<<endl;
	   cout<<"*                                    *"<<endl;  
	   cout<<"**************************************"<<endl;                 
	   };
    
    cout<<"Insira a opcao que quer: "<<endl;
    cin>>opcao;
    
    switch (opcao){
           
        case '1':	
             listarLugar (FILA, LUGAR, LIVRE, lugares);
        break;
        
        case '2':
             numLugaresOcupados = reservarLugar (FILA, LUGAR, lugaresOcupados, numLugaresOcupados, lugares, RESERVADO, LIVRE);	
        break;
        
        case '3':
             numLugaresOcupados = marcarLugar (FILA, LUGAR, lugaresOcupados, numLugaresOcupados, lugares, MARCADO, LIVRE);
        break;
        
        case '4':
             numLugaresOcupados = libertarLugar (FILA, LUGAR, lugaresOcupados, numLugaresOcupados, lugares, LIVRE);
        break;
        
        case '5':
             numLugaresOcupados = chegada (FILA, LUGAR, lugaresOcupados, numLugaresOcupados, lugares, LIVRE);
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

void listarLugar (int FILA, int LUGAR, string LIVRE, string lugares[7][4]){
    for (int i = 0; i < FILA; i++){
        for (int j = 0; j < LUGAR; j++){
        cout<<"Lugar "<<i+1<<j+1<<" -> "<<lugares[i][j]<<endl;
        }
    }
system("pause");
}

int reservarLugar (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string RESERVADO, string LIVRE){
    if (!lugaresOcupados){
    	int numFila = 0;
    	int numLugar = 0;
    	cout<<" -> Reservar lugar: "<<endl;    
    	cout<<"Qual é o lugar a reservar? Fila de 1 a 7, lugar de 1 a 4."<<endl<<"Ex. 14"<<endl;
    	cout<<"Fila: ";
    	cin>>numFila;
    	cout<<"Lugar: ";
    	cin>>numLugar;
    	
    	if (numFila >= 1 && numFila <= FILA && numLugar >= 1 && numLugar <= LUGAR){
    		if (lugares[numFila-1][numLugar-1] == LIVRE){
    			lugares[numFila-1][numLugar-1] = RESERVADO;
    			cout<<"O lugar foi reservado com sucesso!"<<endl;
    			numLugaresOcupados++;
    			if (numLugaresOcupados == 10){
    				lugaresOcupados = true;
    			}
    		}
    		else{
    			cout<<"O lugar já está reservado ou foi marcado!"<<endl;
    		}
    	}
        else {
           cout<<"Número de lugar inválido!"<<endl;
           cout<<"As filas vão de 1 a 7 e os lugares vão de 1 a 4."<<endl;          
           }
    cout<<endl;
    system("pause");
    }
return numLugaresOcupados;
}

int marcarLugar (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string MARCADO, string LIVRE){
    if (!lugaresOcupados){
    	int numFila = 0;
    	int numLugar = 0;
    	cout<<" -> Marcar lugar: "<<endl;    
    	cout<<"Qual é o lugar a marcar? Fila de 1 a 7, lugar de 1 a 4."<<endl<<"Ex. 14"<<endl;
    	cout<<"Fila: ";
    	cin>>numFila;
    	cout<<"Lugar: ";
    	cin>>numLugar;
    	
    	if (numFila >= 1 && numFila <= FILA && numLugar >= 1 && numLugar <= LUGAR){
    		
    		if (lugares[numFila-1][numLugar-1] == LIVRE){
    			lugares[numFila-1][numLugar-1] = MARCADO;
    			cout<<"O lugar foi marcado com sucesso!"<<endl;
    			numLugaresOcupados++;
    		}
    		else{
    			cout<<"O lugar já está reservado ou foi marcado!"<<endl;
    		}
    	}
    	else {
           cout<<"Número de lugar inválido!"<<endl;
           cout<<"As filas vão de 1 a 7 e os lugares vão de 1 a 4."<<endl;          
           }
    cout<<endl;
    system("pause");
    }
return numLugaresOcupados;
}

int libertarLugar (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string LIVRE){
    if (!lugaresOcupados){
    	int numFila = 0;
    	int numLugar = 0;
    	cout<<" -> Libertar lugar: "<<endl;    
    	cout<<"Qual é o lugar a libertar? Fila de 1 a 7, lugar de 1 a 4."<<endl<<"Ex. 14"<<endl;
    	cout<<"Fila: ";
    	cin>>numFila;
    	cout<<"Lugar: ";
    	cin>>numLugar;
    	
    	if (numFila >= 1 && numFila <= FILA && numLugar >= 1 && numLugar <= LUGAR){
    		
    		if (lugares[numFila-1][numLugar-1] != LIVRE){
    			lugares[numFila-1][numLugar-1] = LIVRE;
    			numLugaresOcupados--;
    			cout<<"O lugar foi libertado com sucesso!"<<endl;
    		}
    		else{
    			cout<<"O lugar já está livre!"<<endl;
    		}
    	}
    	else {
           cout<<"Número de lugar inválido!"<<endl;
           cout<<"As filas vão de 1 a 7 e os lugares vão de 1 a 4."<<endl;          
       }
    cout<<endl;
    system("pause");
    }
return numLugaresOcupados;
}

int chegada (int FILA, int LUGAR, bool lugaresOcupados, int numLugaresOcupados, string lugares[7][4], string LIVRE){
    
    for (int i = 0; i < FILA; i++){
        for (int j = 0; j < LUGAR; j++){
        lugares[i][j] = LIVRE;    
    	}   
    }
    cout<<"O autocarro chegou ao seu destino, todos os passageiros devem saír!"<<endl;
    
    for (int i = 0; i < FILA; i++){
        for (int j = 0; j < LUGAR; j++){
        cout<<"Lugar "<<i+1<<j+1<<" -> "<<lugares[i][j]<<endl;
        _sleep(100);
        }
    }
    numLugaresOcupados = 0;
    
return numLugaresOcupados;
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
