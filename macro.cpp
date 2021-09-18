#include <stdio.h>
#include <iostream>
#include <string.h> 
#include <fstream> //manipulacçao de arquivo
#include <vector>

using namespace std;

string nome = "teste_macro_z808.txt";

int main(){
      MacroProcessor macro;

      ifstream arquivoTeste;//abrir para leitura
      arquivoTeste.open(nome);

      ofstream fout("a:teste1.txt");  // Cria arquivo para gravação 

      if (!arquivoTeste){//testa se houve errro, se tiver encerra o programa
            printf("Erro na leitura!\n");
            exit(1);
      }

  
      //....

  
      arquivoTeste.close();

      return 0;
}
