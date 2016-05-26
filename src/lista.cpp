#include "lista.h"

/* Testa se lista está vazia */
bool lista::vazia(){
  return (prim==NULL);
}

/* Insere elemento no início da lista. */
void lista::insere(const int& novo){
  elo *p;
  p = new elo(novo);
  p->prox=prim;
  prim = p;

}

/* Remove da lista o primeiro elemento com valor igual a "novo". Ret. true se removeu. */
bool lista::remove(const int& elem){
  elo *p, *ant;

  for(p=prim; ((p!=NULL) && (p->dado!=elem)); p=p->prox)
    ant=p;

  if (p==NULL) return false;
  if (p==prim) prim=prim->prox;
  else ant->prox=p->prox;
  delete p;
  return true;
}

/* Ret. o tamanho da lista */
int lista::tamanho() const {
  int tam=0;
  elo *p;

  for(p=prim;p!=NULL; p=p->prox)
    tam++;
  return tam;
}

/* Imprime todos os elementos da lista */
void lista::imprime() const {
  elo *p;
// cout << " L : ";
  for(p=prim;p!=NULL; p=p->prox)
  {
    cout << p->dado;
  if (p -> prox)  cout << " , " ;
  }
}


lista::~lista(){
  elo *p=prim;
  while(prim!=NULL)
  {
    p=prim->prox;
    delete prim;
prim=p;
  }
}


/* Retorna o numero do elemento na lista */
bool lista::busca(int elem){
  elo *p;
  int i;
  if (! vazia()){
    for(i = 1, p = prim; (p!=NULL); i++, p=p->prox){
      if (p->dado == elem)
        return true;
    }
    //cout << "Nao existe elemento " << elem << " na Lista\n";
    return false;
  }
  return false;
}

