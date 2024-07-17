using namespace std;
template<typename T>
struct Nodo{
    T elemento;
    Nodo<T> *proximo;
    Nodo<T> *anterior;
};
template<typename T>
struct ListaCirculaDuplamentEncadeada{
    int cardinalidade;
    Nodo<T> *inicio;
    Nodo<T> *fim;
};

template<typename T>
void criaLista(ListaCirculaDuplamentEncadeada<T>&lista)
{
    lista.cardinalidade=0;
    lista.fim=NULL;
    lista.inicio=NULL;
}

template<typename T>
void destruirLista(ListaCirculaDuplamentEncadeada<T>& lista) {
    if (lista.cardinalidade == 0) {
        return;
    }

    Nodo<T>* atual = lista.inicio;
    Nodo<T>* proximo;
    do {
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    } while (atual != lista.inicio);

    lista.cardinalidade = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}
template<typename T>
void inserirNaPosicao(ListaCirculaDuplamentEncadeada<T>&lista,T elemento,int posicao)
{
    if(posicao < 1 || posicao > lista.cardinalidade+1)
    {
        throw "Posicao invalida";
    }
    else
    {
        Nodo<T>* p = new Nodo<T>;
        p->elemento=elemento;
        if(posicao==1 && lista.cardinalidade==0)
        {
            p->proximo=lista.inicio;
            p->anterior=lista.fim;
            lista.inicio=p;
            lista.fim=p;
        }
        else if(posicao==1){
            p->proximo=lista.inicio;
            p->anterior=lista.fim;
            lista.inicio->anterior=p;
            lista.fim->proximo=p;
            lista.inicio=p;
        }
        else if(lista.cardinalidade==1){
                p->proximo=lista.inicio;
                p->anterior=lista.inicio;
                lista.inicio->proximo=p;
                lista.inicio->anterior=p;
                lista.fim=p;
        }
        else
        {
            int i=1;
            Nodo<T> *paux=lista.inicio;
            while(i!=posicao-1)
            {
                paux=paux->proximo;
                i++;
            }
            p->proximo=paux->proximo;
            p->anterior=paux;
            paux->proximo->anterior=p;
            paux->proximo=p;
            if(posicao==lista.cardinalidade+1)
                lista.fim=p;

        }
        lista.cardinalidade++;
    }
}
template<typename T>
void excluirElemenNaPosicao(ListaCirculaDuplamentEncadeada<T>&lista,int posicao){
    if(posicao < 1 || posicao > lista.cardinalidade)
    {
        throw "Posicao invalidade";
    }
    else
    {
        Nodo<T>* p=lista.inicio;
        if(posicao==1 && lista.cardinalidade==1)
        {
            lista.inicio=NULL;
            lista.fim=NULL;
            delete p;
        }
        else if(posicao==1)
        {
            lista.inicio=lista.inicio->proximo;
            lista.inicio->anterior=lista.fim;
            lista.fim->proximo=lista.inicio;
            delete p;
        }
        else
        {
            Nodo<T>* paux;
            int i=1;
            while(i != posicao){
                    p=p->proximo;
                    i++;
            }
            paux = p->anterior;
            paux->proximo=p->proximo;
            p->proximo->anterior=paux;
            delete p;
            if(posicao==lista.cardinalidade)
                lista.fim=paux;
        }
        lista.cardinalidade--;
    }
}
template<typename T>
bool ListaVazia(ListaCirculaDuplamentEncadeada<T> lista){
    return(lista.cardinalidade==0);
}
template<typename T>
int NumeroElementos(ListaCirculaDuplamentEncadeada<T> lista){
    return lista.cardinalidade;
}
template<typename T>
bool ExistEseElemento(ListaCirculaDuplamentEncadeada<T> lista,T elemento){
    Nodo<T>* p=lista.inicio;
        int i=1;
        while(i<lista.cardinalidade+1){
            if(p->elemento==elemento)
                   return true;
            p=p->proximo;
            i++;
        }
    return false;
}

template<typename T>
void mostraLista(ListaCirculaDuplamentEncadeada<T> lista) {
    if (lista.cardinalidade == 0) {
        cout << "Lista vazia" << endl;
        return;
    }

    Nodo<T>* atual = lista.inicio;
    int i=0;
    do {
        cout << atual->elemento << " ";
        atual = atual->proximo;
        i++;
    } while (i<lista.cardinalidade);
    cout << endl;
}


//Leitura De String e char
#include <random>
#include <fstream>
#include <cstring>

int contarPalavras(string arquivo){
    ifstream text(arquivo);
    if(text.is_open()){
        int tamanho=0;
        string palavra;
        while(text>>palavra)
        {
            tamanho++;
        }
        return tamanho;
    }
    throw "Erro ao abrir o arquivo!!";

}
string lerPalavra(string nomeArquivo){
    ifstream text(nomeArquivo);
    if(text.is_open()){
        int p=rand()%contarPalavras(nomeArquivo) + 1;
        string palavra;
        int i=1;
        while(text>>palavra)
        {
            if(p==i)
               return palavra;
            i++;

        }
    }
    throw "Erro ao abrir o arquivo!!";
}

bool validarUmaLetra(string resp){
    int n=resp.size();
    if(n>1 or n<1)
    {
        return false;
    }
    for(int i=0;i<n;i++)
    {
        if(isdigit(resp[i])==true)
            return false;
    }
    if(isalpha(resp[0]))
        return true;
    else
        return false;
}
void displayForca(int erros){
    if(erros==0){
        cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
                 cout<<"  "<<endl;
                  cout<<"  "<<endl;
                 cout<<"-------"<<endl;
        cout<<"Zero erros"<<endl;
    }
    else if(erros==1)
    {
        cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
        cout<<" O"<<endl;
         cout<<"  "<<endl;
          cout<<"  "<<endl;
         cout<<"-------"<<endl;
        cout<<"5 erros restante"<<endl;
    }
    else if(erros==2){
        cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
        cout<<" O"<<endl;
        cout<<" |"<<endl;
         cout<<"  "<<endl;
         cout<<"-------"<<endl;
        cout<<"4 erros restante"<<endl;
    }
    else if(erros==3){
        cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
         cout<<" O"<<endl;
        cout<<"/|"<<endl;
         cout<<"  "<<endl;
         cout<<"-------"<<endl;
        cout<<"3 erros restante"<<endl;
    }
    else if(erros==4){
        cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
          cout<<" O"<<endl;
        cout<<"/|";
        cout<<"\\"<<endl;
         cout<<"  "<<endl;
         cout<<"-------"<<endl;
        cout<<"2 erros restante"<<endl;
    }
    else if(erros==5){
        cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
         cout<<" O"<<endl;
        cout<<"/|";
        cout<<"\\"<<endl;
        cout<<"/"<<endl;
         cout<<"-------"<<endl;
        cout<<"1 erros restante"<<endl;

    }
    else{
            cout<<"DESENHO FORCA: "<<endl;//Para demostra a forca
                cout<<"-!"<<endl;//Cabo da forca
         cout<<" O"<<endl;
        cout<<"/|";
        cout<<"\\"<<endl;
        cout<<"/";
        cout<<" \\"<<endl;
     cout<<"-------"<<endl;
        cout<<"GAME OVER"<<endl;
    }

}