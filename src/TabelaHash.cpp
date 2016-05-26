#include "TabelaHash.h"

TabelaHash::TabelaHash( int tamanhoTabela ){
    if (tamanhoTabela <= 0){
      tamanhoTabela = 13;
    }
    vetor = new lista[ tamanhoTabela ];
    tamanho = tamanhoTabela;
}

int TabelaHash::hash( int itemChave ){
    return itemChave % tamanho;
}

void TabelaHash::inserirItem( int novoItem ){
    int index = hash( novoItem );
    if (!vetor[ index ].busca(novoItem)){
        vetor[ index ].insere( novoItem );
    }
}

bool TabelaHash::removerItem(int chave){
    int index = hash(chave);
    if(!vetor[index].remove(chave)){
        cout << "Elemento inexistente na tabela Hash." << endl;
        return false;
    }
    return true;
}

// return vetor[index].busca(chave);
bool TabelaHash::buscarItemPorChave(int chave){
    int index = hash(chave);
    if(!vetor[index].busca(chave)){
        cout << "Elemento nao encontrado na Tabela Hash." << endl;
        return false;
    }
    return true;
}

void TabelaHash::imprimirTabela(){
    for (int index = 0; index < tamanho; index++){
        cout << index << ": ";
        vetor[index].imprime();
        cout << endl;

    }
}

void TabelaHash::imprimirItens(){
    cout << "Itens: ";
    for (int index = 0; index < tamanho; index++){
            if(!vetor[index].vazia()){
                vetor[index].imprime();
                cout << " , ";
            }
    }
    cout << endl;
}
int TabelaHash::retornarTamanho(){
    return tamanho;
}
int TabelaHash::retornarNumeroItens(){
}
TabelaHash::~TabelaHash(){
}

