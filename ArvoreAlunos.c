#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno *esquerdo;
    struct Aluno *direito;
} Aluno;    

Aluno* inserirAluno(Aluno* raiz, char nome[], int matricula, float nota) {
    if (raiz == NULL) {
        Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = novo->direito = NULL;
        return novo;
    }

    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    } else {
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    }

    return raiz;
}


Aluno* buscarAluno(Aluno* raiz, char nome[]) {
    if (raiz == NULL) return NULL;

    int cmp = strcmp(nome, raiz->nome);
    if (cmp == 0) return raiz;
    if (cmp < 0) return buscarAluno(raiz->esquerdo, nome);
    else return buscarAluno(raiz->direito, nome);
}

void calcularMedia(Aluno* raiz, float *soma, int *quantidade) {
    if (raiz == NULL) return;

    *soma += raiz->nota;
    (*quantidade)++;
int main() {
    Aluno* raiz = NULL;
    int op;
    char nome[50];
    int matricula;
    float nota;

    do {
        printf("\n1 - Inserir aluno\n2 - Buscar aluno por nome\n3 - Média das notas\n0 - Sair\n");
        scanf("%d", &op);
        getchar(); // limpar o buffer

        switch(op) {
            case 1:
                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Matrícula: ");
                scanf("%d", &matricula);
                printf("Nota: ");
                scanf("%f", &nota);
                raiz = inserirAluno(raiz, nome, matricula, nota);
                break;
            case 2:
                printf("Nome para buscar: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                Aluno* encontrado = buscarAluno(raiz, nome);
                if (encontrado) {
                    printf("Encontrado: %s, Matrícula: %d, Nota: %.2f\n", encontrado->nome, encontrado->matricula, encontrado->nota);
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            case 3:
                printf("Média das notas: %.2f\n", mediaNotas(raiz));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
        }

    } while (op != 0);

    return 0;
}
    calcularMedia(raiz->esquerdo, soma, quantidade);
    calcularMedia(raiz->direito, soma, quantidade);
}

float mediaNotas(Aluno* raiz) {
    float soma = 0.0;
    int quantidade = 0;
    calcularMedia(raiz, &soma, &quantidade);
    if (quantidade == 0) return 0.0;
    return soma / quantidade;
}

