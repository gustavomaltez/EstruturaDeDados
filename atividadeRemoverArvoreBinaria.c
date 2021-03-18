#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *pai;
    struct no *esq;
    struct no *dir;
} NO;

NO *raiz = NULL;

NO *busca(int x, NO *aux)
{
    if (aux == NULL)
    {
        return NULL; //vazia
    }
    else if (x == aux->chave)
    {
        return aux; //encontrei :D
    }
    else if (x < aux->chave)
    { //buscar no lado esq
        if (aux->esq != NULL)
        {
            return busca(x, aux->esq);
        }
        else
        {               //esq esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
    else
    { //buscar no lado dir
        if (aux->dir != NULL)
        {
            return busca(x, aux->dir);
        }
        else
        {               //dir esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
}

void add(int x)
{
    NO *resp = busca(x, raiz);

    if (resp == NULL || resp->chave != x)
    { // vazia ou eu posso adicionar
        NO *novo = malloc(sizeof(NO));
        novo->chave = x;
        novo->pai = resp;
        novo->esq = NULL;
        novo->dir = NULL;

        if (resp == NULL)
        { //add na raiz
            raiz = novo;
        }
        else
        {
            if (x < resp->chave)
            {
                resp->esq = novo;
            }
            else
            {
                resp->dir = novo;
            }
        }
    }
    else
    { //nao posso deixar add novamente pq neste caso
        //havera chaves duplicadas
        printf("Add inválida. Chave duplicada");
    }
}

NO *remover(NO *raiz, int valorARemover)
{

    // Faz a busca na arvore
    NO *aux = busca(valorARemover, raiz);
    NO *noRemovido = malloc(sizeof(NO));

    if (aux == NULL)
    { // Verifica se o valor existe
        printf("\n[ERRO] Esse valor nao existe na arvore!\n");
        return NULL;
    }
    else
    {
        if (aux->chave == valorARemover)
        { //Caso a chave for igual o valor a remover, então ele existe

            //Verifica o se o nó é uma folha
            if (aux->esq == NULL && aux->dir == NULL)
            {
                
                //Verifica se filho (aux) está sendo apontado pelo ponteiro esq ou dir
                // E posteriormente define o ponteiro para NULL
                if (valorARemover > aux->pai->chave)
                {
                    aux->pai->dir = NULL;
                }
                else if (valorARemover < aux->pai->chave)
                {
                    aux->pai->esq = NULL;
                }

                //Faz uma cópia das informações de aux para nó removido
                //Essa etapa é importante pois fazendo apenas noRemovido = aux
                //Ao dar um free(aux), estaremos limpando também as informações de noRemovido
                memcpy(noRemovido, aux, sizeof(NO));
                free(aux);
            }
            else //O Nó não é uma folha
            {   
                if (aux->esq != NULL && aux->dir == NULL)
                { //Nó possui um filho do lado esquerdo

                    //Verifica se os filhos do nó devem ir para o lado esquerdo ou direito do pai
                    if (aux->chave < aux->pai->chave)
                    {
                        aux->pai->esq = aux->esq;
                    }
                    else if (aux->chave > aux->pai->chave)
                    {
                        aux->pai->dir = aux->esq;
                    }

                    //Faz uma cópia das informações de aux para nó removido
                    //Essa etapa é importante pois fazendo apenas noRemovido = aux
                    //Ao dar um free(aux), estaremos limpando também as informações de noRemovido
                    memcpy(noRemovido, aux, sizeof(NO));
                    free(aux);
                }

                if (aux->esq == NULL && aux->dir != NULL)
                { //Nó possui um filho do lado direito

                    //Verifica se os filhos do nó devem ir para o lado esquerdo ou direito do pai
                    if (aux->chave < aux->pai->chave)
                    {
                        aux->pai->esq = aux->dir;
                    }
                    else if (aux->chave > aux->pai->chave)
                    {
                        aux->pai->dir = aux->dir;
                    }

                    //Faz uma cópia das informações de aux para nó removido
                    //Essa etapa é importante pois fazendo apenas noRemovido = aux
                    //Ao dar um free(aux), estaremos limpando também as informações de noRemovido
                    memcpy(noRemovido, aux, sizeof(NO));
                    free(aux);
                }

                if (aux->esq != NULL && aux->dir != NULL)
                { //Nó tem dois filhos

                    //Busca o menor dos maiores
                    NO *m = aux->dir;

                    while (m->esq != NULL)
                    {
                        m = m->esq;
                    }
                    
                    //Faz uma cópia das informações de aux para nó removido
                    //Essa etapa é importante pois fazendo apenas noRemovido = aux
                    //Ao dar um free(aux), estaremos limpando também as informações de noRemovido
                    memcpy(noRemovido, aux, sizeof(NO));


                    //Verifica o se o nó é uma folha
                    if (m->esq == NULL && m->dir == NULL)
                    {
                        //Verifica se filho (m) está sendo apontado pelo ponteiro esq ou dir
                        // E posteriormente define o ponteiro para NULL
                        if (valorARemover > m->pai->chave)
                        {
                            m->pai->dir = NULL;
                        }
                        else if (valorARemover < m->pai->chave)
                        {
                            m->pai->esq = NULL;
                        }

                    }
                    
                    if (m->esq == NULL && m->dir != NULL)//Nó possui um filho do lado direito
                    { 
                        // Nesse caso, o m->chave sempre vai ser maior que o m->pai->chave
                        // Visto que estamos buscando o menor dos MAIORES logo, se é o menor
                        // dos MAIORES então m->chave sempre vai ser MAIOR que m->pai->chave
                        m->pai->dir = m->dir;
                    }
                    
                    //Substitui o nó a ser removido pelo menor dos maiores
                    aux->chave = m->chave;

                    free(m);
                }
            }

            //Retorna o nó removido
            return noRemovido;
        }
        else
        { //Se a chave for diferente do valor a remover, então ele não existe
            printf("[ERRO] Esse valor nao existe na arvore!");
            return NULL;
        }
    }
}

NO *busca_arvore(int x)
{
    NO *resp = busca(x, raiz);
    if (resp == NULL)
    {
        //valor nao foi encontrado
        return NULL;
    }
    else
    {
        //encontrei :D
        if (resp->chave == x)
        {
            return resp;
        }
        else
        {
            return NULL;
        }
    }
}

void in_ordem(NO *aux)
{

    if (aux->esq != NULL)
    {
        in_ordem(aux->esq);
    }
    printf("%d ", aux->chave);
    if (aux->dir != NULL)
    {
        in_ordem(aux->dir);
    }
}

int main()
{
    add(11);
    add(8);
    add(12);
    add(7);
    add(9);
    add(10);
    add(6);
    add(13);
    add(30);
    add(20);
    add(25);
    add(44);
    add(27);
    in_ordem(raiz);

    
    printf("\nREMOVIDO: %d", remover(raiz, 8)->chave);
    printf("\nREMOVIDO: %d", remover(raiz, 25)->chave);
    printf("\nREMOVIDO: %d", remover(raiz, 6)->chave);
    printf("\nREMOVIDO: %d", remover(raiz, 13)->chave);
    printf("\n");
    in_ordem(raiz);
    return 0;
}
