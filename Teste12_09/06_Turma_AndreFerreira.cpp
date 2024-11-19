#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Aluno {
    string nomeAluno;
    string curso;
    float faltas;
};

struct Modulo {
    string nomeModulo;
    string codigo;
    float notaFinal;
};

struct Turma {
    Aluno aluno;
    Modulo modulo;
};

void listarFormandos(int FORMANDOS, int MODULOS, Turma turma[5][7]);
void inserirFormandos(int FORMANDOS, int MODULOS, Turma turma[5][7]);
void apagarFormandos(int FORMANDOS, int MODULOS, Turma turma[5][7]);
bool sair(bool queroSair, char opcao);


int main()
{
const int FORMANDOS = 5, MODULOS = 7;
Turma turma[FORMANDOS][MODULOS];
char opcao = '\0';
bool queroSair = false;


setlocale(LC_ALL, "Portuguese");
for(int numFormando = 0; numFormando < FORMANDOS; numFormando++)
   {
   for(int numModulos = 0; numModulos < MODULOS; numModulos++)
      {        
             turma[numFormando][numModulos].aluno.nomeAluno = "";
             turma[numFormando][numModulos].aluno.curso = "";
             turma[numFormando][numModulos].aluno.faltas = 0;
             turma[numFormando][numModulos].modulo.nomeModulo = "";
             turma[numFormando][numModulos].modulo.codigo = "";
             turma[numFormando][numModulos].modulo.notaFinal = 0;
      }
   }

do {

system("cls");
cout<<"*****************************"<<endl;
cout<<"*                           *"<<endl;
cout<<"*        Turma PROG20       *"<<endl;
cout<<"*                           *"<<endl;
cout<<"*    1. Listar alunos.      *"<<endl;
cout<<"*    2. Inserir alunos.     *"<<endl;
cout<<"*    3. Apagar aluno.       *"<<endl;
cout<<"*    4. Saír.               *"<<endl;
cout<<"*                           *"<<endl;
cout<<"*****************************"<<endl;
cout<<endl;       

cout<<"-> Qual é a sua escolha (1-4)? ";
fflush(stdin);
cin>>opcao;
cout<<endl;        

switch(opcao)
{
   case '1':
    {       
    cout<<"-> Listagem de alunos: "<<endl;
    listarFormandos(FORMANDOS, MODULOS, turma);
    cout<<endl;   
    system("pause");                                         
    break;
    }
           
   case '2': {
    inserirFormandos(FORMANDOS, MODULOS, turma);
    system("pause");
    break;
    }
    
   case '3':              
    {   
    apagarFormandos(FORMANDOS, MODULOS, turma);
    system("pause");
    break; 
    }  
                               
   case '4':
     {   
     sair(queroSair, opcao);
     break;
     }  
   default:
     cout<<"Escolha inválida!"<<endl;
     cout<<"As escolhas vão de 1 a 4."<<endl;                        
     system("pause");              
}
}while(!queroSair);
                                        
cout<<"Obrigado por ter utilizado o programa!";
cout<<endl;
system("pause");
}


void listarFormandos(int FORMANDOS, int MODULOS, Turma turma[5][7]){
for(int numFormando = 0; numFormando < FORMANDOS; numFormando++)
   {
   for(int numModulos = 0; numModulos < MODULOS; numModulos++)
      {
      cout<<"Aluno -> "<<turma[numFormando][numModulos].aluno.nomeAluno<<endl;
      cout<<"Curso -> "<<turma[numFormando][numModulos].aluno.curso<<turma[numFormando][numModulos].aluno.faltas<<endl;
      cout<<"Modulo -> "<<turma[numFormando][numModulos].modulo.nomeModulo<<turma[numFormando][numModulos].modulo.codigo<<endl;
      cout<<"Curso -> "<<turma[numFormando][numModulos].modulo.notaFinal<<endl<<endl;
      }
   }
}

void inserirFormandos(int FORMANDOS, int MODULOS, Turma turma[5][7]){

int num = 0;
cout<<"Qual número do formando (1 a "<< FORMANDOS<<")?";
cin>>num;

cout<<endl<<"Insira o nome do aluno: ";  
cin>>turma[num][7].aluno.nomeAluno;

cout<<endl<<"Insira o nome do curso: ";
cin>>turma[num][7].aluno.curso;

cout<<endl<<"Insira a quantidade de faltas: ";
cin>>turma[num][7].aluno.faltas;
        
    for(int numModulos = 0; numModulos < MODULOS; numModulos++)
      {      
        cout<<endl<<"Insira o nome do módulo: ";
        cin>>turma[num][7].modulo.nomeModulo;
        
        cout<<endl<<"Insira o código do módulo: ";
        cin>>turma[num][7].modulo.codigo;
        
        cout<<endl<<"Insira a nota final do aluno: ";
        cin>>turma[num][7].modulo.notaFinal;
      }
}

void apagarFormandos(int FORMANDOS, int MODULOS, Turma turma[5][7]){
int num = 0;
cout<<"Qual número do formando (1 a "<< FORMANDOS<<")?";
cin>>num;
 
    for(int numModulos = 0; numModulos < MODULOS; numModulos++)
      {
        turma[num][7].aluno.nomeAluno = "";
        turma[num][7].aluno.curso = "";
        turma[num][7].aluno.faltas = 0;
        turma[num][7].modulo.nomeModulo = "";
        turma[num][7].modulo.codigo = "";
        turma[num][7].modulo.notaFinal = 0;
      }
}

bool sair(bool queroSair, char opcao){
cout<<"-> Sair do programa: "<<endl;   
    cout<<"Tem a certeza que quer sair (S/N)? ";
    fflush(stdin);
    cin>>opcao;
          
    if (opcao == 'S' || opcao == 's'){
       queroSair = true;
    }
return queroSair;
}
