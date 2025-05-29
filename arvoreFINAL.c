#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *esquerda, *direita;
} node;

typedef struct {
    node *raiz;
    int tam;
} arvore;

void inseriEsquerda(node *n, int conteudo) {
    if (n->esquerda == NULL) {
        node *novo = (node *)malloc(sizeof(node));
        novo->valor = conteudo;
        novo->esquerda = NULL;
        novo->direita = NULL;
        n->esquerda = novo;
    } else {
        if (conteudo < n->esquerda->valor) {
            inseriEsquerda(n->esquerda, conteudo);
        } else if (conteudo > n->esquerda->valor) {
            inseriDireita(n->esquerda, conteudo);
        }
    }
}

void inseriDireita(node *n, int conteudo) {
    if (n->direita == NULL) {
        node *novo = (node *)malloc(sizeof(node));
        novo->valor = conteudo;
        novo->esquerda = NULL;
        novo->direita = NULL;
        n->direita = novo;
    } else {
        if (conteudo < n->direita->valor) {
            inseriEsquerda(n->direita, conteudo);
        } else if (conteudo > n->direita->valor) {
            inseriDireita(n->direita, conteudo);
        }
    }
}
void inseri(arvore *arv, int conteudo) {
    if (arv->raiz == NULL) {
        node *novo = (node *)malloc(sizeof(node));
        novo->valor = conteudo;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    } else {
        if (conteudo < arv->raiz->valor) {
            inseriEsquerda(arv->raiz, conteudo);
        } else {
            inseriDireita(arv->raiz, conteudo);
        }
    }
}


node* inseriNova(node *raiz, int conteudo){
	if(raiz==NULL){
			node *novo = (node*)malloc(sizeof(node));
			novo->valor = conteudo;
			novo->esquerda = NULL;
			novo->direita = NULL;
			return novo;
	}else{
		if(conteudo < raiz->valor){
		
		 	raiz->esquerda = inseriNova(raiz->esquerda, conteudo);}
		if (conteudo > raiz->valor)	{
		
			 	raiz->direita = inseriNova(raiz->direita, conteudo);
		
	}}
	return raiz;}

void imprimir(node *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

node*remover(node *raiz, int key){
	if(raiz == NULL){
		printf("Valor n�o encontrado!\n");
		return NULL;
	}else{
		if(raiz->valor==key){
				if(raiz->esquerda==NULL && raiz->direita==NULL){
					free(raiz);
					return NULL;
				}else 
				{
					if (raiz->esquerda!=NULL || raiz->direita!=NULL){
						node * aux;
						if(raiz->esquerda!=NULL){
							aux = raiz->esquerda;
						}
						else{
							aux = raiz->direita;
						}
						
				free(raiz);
					return aux;
						}
				}
		}else{
			if(key < raiz->valor){
				raiz->esquerda = remover(raiz->esquerda, key);
			}else{
				raiz->direita = remover(raiz->direita, key);
			}
			return raiz;
		}
	}
}

int tam(node *raiz){
	if(raiz == NULL){
		return 0;
	
	}else{
		return 1 + tam(raiz->esquerda) + tam(raiz->direita);
	}
}

int busca(node *raiz, int key){
	if(raiz==NULL){
		return -1; 
	}else{
		if(raiz->valor == key){
			return raiz->valor;
		}
		else{
			if(key < raiz->valor){
	
			return busca(raiz->esquerda,key);
		}else {
			return busca(raiz->direita, key);
		}
		}
	}
	
	
}

node* buscarNo(node *raiz, int key){
	if(raiz==NULL){
		return NULL; 
	}else{
		if(raiz->valor == key){
			return raiz->valor;
		}
		else{
			if(key < raiz->valor){
	
			return buscaNo(raiz->esquerda,key);
		}else {
			return buscaNo(raiz->direita, key);
		}
		}
	}

int altura(node *raiz){
    if (raiz == NULL || raiz->direita == NULL && raiz->esquerda == NULL){
        return 0;
    }else{
        int esq = 1 + altura(raiz->esquerda);
        int dir = 1 + altura(raiz->direita);
    if (esq > dir){
        return esq;}
        else{return dir;}}

}

int subaltura(node *raiz, int key){
    node *node = buscarNO(raiz, key);
    if(node){
    return altura(node):}
    else{
    return -1;}

}

int main()
{
    int op, conteudo;
    arvore arv;
    arv.raiz = NULL;
    node *raiz =NULL;    
    do{
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - busca\n4 - remover\n5 - Altura\n6 - Altura da sub-arvore\n");
        scanf("%d", &op);
        switch(op){
    case 0:
        printf("\n saindo...\n");
        break;
    case 1:
    printf("\n digite um valor: ");
    scanf("%d", &conteudo);
    arv.raiz = inseriNova(arv.raiz,conteudo);
    break;
    case 2:
    imprimir(arv.raiz);
    printf("\n");
    printf("tamanho: %d\n", tam(arv.raiz));
    break;
    case 3:
    	printf("qual valor quer que busque? \n");
    	scanf("%d", &conteudo);
    	printf("o valor : %d\n", busca(arv.raiz, conteudo));
    	
    	break;
    case 4: 
    printf("Qual valor deeja remover: \n");
    scanf("%d", &conteudo);
    arv.raiz = remover(arv.raiz, conteudo);
    break;
    case 5:
    printf("Altura da arvore eh: %d \n", altura(arv.raiz));
    break;
    case 6:
    printf("qual valor quer descobrir a altura? \n");
    	scanf("%d", &conteudo);
        printf("A altura do valor %d eh %d", conteudo, alturasubarvore(arv.raiz, conteudo));
        break;
    default:
    printf("\n opcao invalida");
    }
    }while(op != 0);        
}
