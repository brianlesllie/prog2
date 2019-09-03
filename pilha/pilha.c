struct{
  lista_enc_t *lista;
  }
pilha_t *criar_pilha(){
  pilha_t*p=malloc(sizeof(pilha_t));
    if(...)
  p->lista=criar_lista();
  return p;
}
void push(void *dado, pilha_t *pilha){
  no_t *meu_no=criar_no(dado);
  add_cabeca(pilha->lista,meu_no);
}

void *pop(pilha_t *pilha){



int main(){
  pilha_t *p=criar_pilha()
  push("juco",p);
