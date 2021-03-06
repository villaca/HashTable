#ifndef TABELAHASH_H
#define TABELAHASH_H

#include "lista.h"

/*
 *Grupo 4
 * Daniel Villa�a
 * Thiago Albuquerque
 * Gabriel Teixeira
 */

class TabelaHash
{
private:

    lista * vetor;
    int tamanho;

    int hash( int itemChave );

public:

    TabelaHash( int tamanhoTabela = 13 );
    void inserirItem(int chave);
    bool removerItem(int chave);
    bool buscarItemPorChave(int chave);
    void imprimirTabela();
    void imprimirItens();
    int retornarTamanho();
    int retornarNumeroItens();
    ~TabelaHash();
};

#endif
