#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include "TabelaHash.h"

using namespace std;

/*
 *Grupo 4
 * Daniel Villaça
 * Thiago Albuquerque
 * Gabriel Teixeira
 */


int main(int argc, char** argv) {

    //	TabelaHash tabela;
    TabelaHash tabela(7);

    tabela.inserirItem(13);
    tabela.inserirItem(19);
    tabela.inserirItem(5);
    tabela.inserirItem(58);
    tabela.inserirItem(26);
    tabela.inserirItem(49);
    tabela.inserirItem(10);

    tabela.inserirItem(5);

    tabela.imprimirTabela();
    getchar();

    tabela.imprimirItens();
    cout << "\n\n Total de itens na tabela: " << tabela.retornarNumeroItens();
    getchar();

    tabela.removerItem(58);
    tabela.imprimirTabela();
    getchar();

    tabela.imprimirItens();
    cout << "\n\n Total de itens na tabela: " << tabela.retornarNumeroItens();
    getchar();

    cout << "\n \n Procurando chave...";
    int g = tabela.buscarItemPorChave(1);
    if (g)
        cout << "\n \n Achei o " << g << " !";
    else
        cout << ":(";
    getchar();

    int i, novoAleatorio;

    for(i=1 ; i <= 10 ; i++){
        novoAleatorio = rand()%1000;
        tabela.inserirItem(novoAleatorio);
    }
    tabela.imprimirTabela();
    getchar();
    tabela.imprimirItens();
    cout << "\n\n Total de itens na tabela: " << tabela.retornarNumeroItens();
    getchar();

    return 0;
}
