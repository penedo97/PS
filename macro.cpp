#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using std::cout; using std::string;
using std::ifstream; using std::vector;
using std::ofstream; using std::basic_string;

string nome = "teste_macro_z808.txt";

int main(){
    //string filename("file.txt");
    vector<string> lines;
    string line;

    ofstream f_out; //gera Arquivo de saida
    f_out.open("untitled1.txt");

    if(!f_out.good()){ //verifica se houve erro na criação do arquivo
        printf("Erro ao criar arquivo!");
        exit(1);
    }

    ifstream input_file("file.txt");
    input_file.is_open();

    if (!input_file){//testa se houve errro, se tiver encerra o programa
        printf("Erro na leitura1!\n");
        exit(1);
    }


    ofstream temp_macro; //gera Arquivo de saida
    temp_macro.open("macro.txt");

    if(!temp_macro.good()){ //verifica se houve erro na criação do arquivo
        printf("Erro ao criar arquivo!");
        exit(1);
    }

    while (getline(input_file, line) && (line.compare(0,13,"SomaMem MACRO") != 0)){ //copia até a definição da macro
        f_out << line + "\n";
    }

    while(getline(input_file, line) && (line.compare(0,4,"ENDM") != 0)){ //copia os dados da macro pra um arquivo
        temp_macro << line + "\n";
    }
    temp_macro.close();


    //string dados("macro.txt");
    //int p=0, q=0;

    while(getline(input_file, line)){//le tudo linha a linha
        if(line.compare(0,9,"SomaMem V") == 0){ //cada vez q tiver somaMen V expande a macro
            char algumacoisa;
            int espacosemps;
            int virgulina;
            string var1;
            string var2;
            string temp;
            string aux;
            int flag=0;
            //temp = line;
            //cout << temp;
            for(int i=7;i<line.length();i++){// separa var1 e var2
                temp = line.at(i);
                if((temp != ",") && flag == 0){
                    var1 += line[i];
                }

                else{
                    flag += 1;
                    var2 += line[i];
                }
            }
            //var2 = var1 - aux;
            //var1 = aux;
            //cout << var1;

           int p=0, q=0;


            //pega as variaveis
            for(int i=0; i<line.length(); i++){//pega as posições de espaço e virgula
                algumacoisa = line.at(i);
                if(algumacoisa == ' '){
                    espacosemps= i;
                }
                if(algumacoisa == ','){
                    virgulina = i;
                }
            }


            // O ERRO TA NESSA PARTE
            //não ta armazenando em var1 e var2 ao sair do for
            //----------------------------------------------------------------------------
           /* for(int i=espacosemps + 1; i<virgulina; i++){//variavel1
                var1[p] = line.at(i);
                p++;
            }
            var1[p] = '\0';

            for(int i=virgulina + 1; i<line.length(); i++){//variavel2
                var2[q] << line.at(i);
                q++;
            }
            var2[q]='\0';*/
            //----------------------------------------------------------------------------

            ifstream dados_macro("macro.txt"); //abre o macro para leitura
            dados_macro.is_open();
            if (!dados_macro){//testa se houve errro, se tiver encerra o programa
                printf("Erro na leitura!\n");
                exit(1);
            }


            vector<string> commandss;
            string commands;

            //ta printando en hexadecimal no arquivo
            while(getline(dados_macro, commands)){//le cada linha alterando Mem1 pela primeira variavel e Mem2 pela segunda variavel
                for(int i=0; i<commands.length(); i++){//pega as posições de espaço e virgula
                        if(commands.at(i) == '1'){
                            f_out << var1;//var1;
                        }
                        else if(commands.at(i) == '2'){
                            f_out << var2; //var2;
                        }
                        else if(commands.at(i) == 'M'){
                            i=i+2;
                        }
                        else{
                            f_out << commands.at(i);
                        }
                    }
                    f_out << "\n";

                }
            dados_macro.close();
        }
        else{ //não tem q expandir macro, só copia
            f_out << line + "\n";
        }
    }

    input_file.close();
    f_out.close();
    return EXIT_SUCCESS;
}
