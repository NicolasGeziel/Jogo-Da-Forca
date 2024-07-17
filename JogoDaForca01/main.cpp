#include <iostream>
#include "Jogo.cpp"
using namespace std;
int main(){
    ListaCirculaDuplamentEncadeada<char> listaChar;
    ListaCirculaDuplamentEncadeada<char>listaTentativas;
    criaLista(listaChar),criaLista(listaTentativas);
    string palavra,nomeArquivo="";

    cout<<"***BEM VINDO AO JOGO DA FORCA***"<<endl;
    cout<<"Digite o nome do arquivo para a leitura das palavras: ";
    cout<<"Por exemplo ""NomeArquivo.txt"": ";
    getline(cin,nomeArquivo);

     try { //caso abra o arquivo o programa segue
        cin.ignore();//limpar o buffer
        string resp;
    do{
            palavra=lerPalavra(nomeArquivo);//recebe a palavra aleatoria
            for(int i=0;i<palavra.size();i++)
            {
                inserirNaPosicao(listaChar,'_',i+1);//montar o espaço da palavra com _
            }

            int acertos=0;
            int erros=0;

            cout<<"***BEM VINDO AO JOGO DA FORCA***"<<endl;
            do{
                cout<<"Digite uma letra: ";
                 do{
                    getline(cin,resp);
                    if(!validarUmaLetra(resp))
                        cout<<"Erro, digite apenas uma letra: ";
                  }while(!validarUmaLetra(resp));//validação
                  cin.ignore();//limpar o buffer

                system("CLS");//limpando a tela
                if(!ExistEseElemento(listaTentativas,resp[0])){//verificar palavras repitida
                        inserirNaPosicao(listaTentativas,resp[0],NumeroElementos(listaTentativas)+1);//inserindo na ultima posição

                    for(int i=0;i<palavra.size();i++)
                    {
                        if(palavra[i]==resp[0]){//testando letra por letra
                          excluirElemenNaPosicao(listaChar,i+1);
                          inserirNaPosicao(listaChar,palavra[i],i+1);//colocando na posição
                          acertos++;
                        }
                    }
                    if(!ExistEseElemento(listaChar,resp[0]))//verificar se a letra é errada
                       erros++;
                }
                else
                {
                    cout<<"Letra repetida!!"<<endl;
                }

                cout<<"Letras digitadas: ";
                mostraLista(listaTentativas);
                cout<<"Palavra: ";
                mostraLista(listaChar);
                cout<<"Acertos: "<<acertos<<endl;
                cout<<"Erros: "<<erros<<"/6"<<endl;

                if(acertos==palavra.size()){//caso acerte a a palavra, mostra a mensagem e sai do loping
                    cout<<"PARABEN, A PALAVRA FOI ADIVINHADA :)"<<endl;
                    break;
                }
                displayForca(erros);
            }while(erros!=6);

            cout<<"Palavra completa: "<<palavra<<endl;//mostra palavra completa

            destruirLista(listaChar);
            destruirLista(listaTentativas);
        cout<<"Quer tentar adivinhar outra palavra, (S/N): ";

        do{
                getline(cin,resp);
        if(!validarUmaLetra(resp) || toupper(resp[0])!='S'&& toupper(resp[0])!='N')
            cout<<"Erro, digite (S/N): ";
        }while(!validarUmaLetra(resp));
        cin.ignore();//limpar o buffer

        system("CLS");//Para limpar a tela
    }while(toupper(resp[0])=='S');

    cout<<"VOCE SAIU DO JOGO....";

    } catch (const char* erro) { //caso o arquivo não exista, o programa não sera executado
        cerr << "Erro: " << erro << endl;
    }

    return 0;
}


