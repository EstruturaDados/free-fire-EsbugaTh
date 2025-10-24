#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura que representa um componente da torre
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// Exibe todos os componentes formatados
void mostrarComponentes(Componente componentes[], int n) {
    printf("\n--- Componentes da Torre ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               componentes[i].nome,
               componentes[i].tipo,
               componentes[i].prioridade);
    }
}

// Ordena por nome usando Bubble Sort
int bubbleSortNome(Componente componentes[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (strcmp(componentes[j].nome, componentes[j + 1].nome) > 0) {
                Componente temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

// Ordena por tipo usando Insertion Sort
int insertionSortTipo(Componente componentes[], int n) {
    int comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = componentes[i];
        int j = i - 1;
        while (j >= 0 && strcmp(componentes[j].tipo, chave.tipo) > 0) {
            componentes[j + 1] = componentes[j];
            j--;
            comparacoes++;
        }
        componentes[j + 1] = chave;
        comparacoes++;
    }
    return comparacoes;
}

// Ordena por prioridade usando Selection Sort
int selectionSortPrioridade(Componente componentes[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (componentes[j].prioridade < componentes[min].prioridade) {
                min = j;
            }
        }
        Componente temp = componentes[i];
        componentes[i] = componentes[min];
        componentes[min] = temp;
    }
    return comparacoes;
}

// Busca binária por nome (após ordenação por nome)
int buscaBinariaPorNome(Componente componentes[], int n, char chave[]) {
    int inicio = 0, fim = n - 1, comparacoes = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;
        int cmp = strcmp(componentes[meio].nome, chave);
        if (cmp == 0) {
            printf("\n✅ Componente-chave encontrado: %s\n", componentes[meio].nome);
            return comparacoes;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("\n❌ Componente-chave não encontrado.\n");
    return comparacoes;
}

// Mede tempo de execução de um algoritmo de ordenação
double medirTempo(int (*algoritmo)(Componente[], int), Componente componentes[], int n, int *comparacoes) {
    clock_t inicio = clock();
    *comparacoes = algoritmo(componentes, n);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// Função principal com menu interativo
int main() {
    Componente componentes[20];
    int n, opcao, comparacoes;
    double tempo;
    char chave[30];

    printf("Quantos componentes deseja cadastrar (máx 20)? ");
    scanf("%d", &n);
    getchar(); // Limpa buffer

    for (int i = 0; i < n; i++) {
        printf("\nComponente %d:\n", i + 1);
        printf("Nome: ");
        fgets(componentes[i].nome, 30, stdin);
        componentes[i].nome[strcspn(componentes[i].nome, "\n")] = '\0';

        printf("Tipo: ");
        fgets(componentes[i].tipo, 20, stdin);
        componentes[i].tipo[strcspn(componentes[i].tipo, "\n")] = '\0';

        printf("Prioridade (1 a 10): ");
        scanf("%d", &componentes[i].prioridade);
        getchar();
    }

    do {
        printf("\n--- Menu Estratégico ---\n");
        printf("1. Ordenar por Nome (Bubble Sort)\n");
        printf("2. Ordenar por Tipo (Insertion Sort)\n");
        printf("3. Ordenar por Prioridade (Selection Sort)\n");
        printf("4. Buscar componente-chave por Nome\n");
        printf("5. Mostrar componentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                tempo = medirTempo(bubbleSortNome, componentes, n, &comparacoes);
                printf("\n🔃 Ordenado por nome. Comparações: %d | Tempo: %.6f segundos\n", comparacoes, tempo);
                break;
            case 2:
                tempo = medirTempo(insertionSortTipo, componentes, n, &comparacoes);
                printf("\n🔃 Ordenado por tipo. Comparações: %d | Tempo: %.6f segundos\n", comparacoes, tempo);
                break;
            case 3:
                tempo = medirTempo(selectionSortPrioridade, componentes, n, &comparacoes);
                printf("\n🔃 Ordenado por prioridade. Comparações: %d | Tempo: %.6f segundos\n", comparacoes, tempo);
                break;
            case 4:
                printf("Digite o nome do componente-chave: ");
                fgets(chave, 30, stdin);
                chave[strcspn(chave, "\n")] = '\0';
                comparacoes = buscaBinariaPorNome(componentes, n, chave);
                printf("🔍 Comparações na busca binária: %d\n", comparacoes);
                break;
            case 5:
                mostrarComponentes(componentes, n);
                break;
        }
    } while (opcao != 0);

    printf("\n🏁 Fim da missão. Boa sorte na fuga!\n");
    return 0;
}



