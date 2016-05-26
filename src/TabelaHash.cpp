#include "TabelaHash.h"

/*
 *Grupo 4
 * Daniel Villaça
 * Thiago Albuquerque
 * Gabriel Teixeira
 */


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

bool TabelaHash::buscarItemPorChave(int chave){
    int index = hash(chave);
    /*f(!vetor[index].busca(chave)){
        cout << "Elemento nao encontrado na Tabela Hash." << endl;
        return false;
    }
    return true;*/

    return vetor[index].busca(chave);
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
                if(index < tamanho - 1){
                    cout << " , ";
                }
            }
    }
    cout << endl;
}

int TabelaHash::retornarTamanho(){
    return tamanho;
}

int TabelaHash::retornarNumeroItens(){
    int soma = 0;
    if(!vetor->vazia()){
        for(int index = 0; index < tamanho; index++){
            if(!vetor[index].vazia()){
                cout << "O vetor[" << index << "] tem tamanho " << vetor[index].tamanho() << endl;
                soma += vetor[index].tamanho();
            }
        }
    }
    return soma;
}

TabelaHash::~TabelaHash(){
    if(!vetor->vazia()){
        for(int index = 0; index < tamanho; index++){
            vetor[index].~lista();
        }
        vetor->~lista();
    }
}





















