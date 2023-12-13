#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void generate_worst_case(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generate_average_case(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
}

void generate_best_case(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("\n==============MENU==============\n");
        printf("1. Pior Caso\n");
        printf("2. Medio Caso\n");
        printf("3. Melhor Caso\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Saindo do programa.\n");
            break;
        }

        printf("Informe o tamanho da lista: ");
        scanf("%d", &n);

        int arr[n];

        switch (choice) {
            case 1:
                generate_worst_case(arr, n);
                break;
            case 2:
                generate_average_case(arr, n);
                break;
            case 3:
                generate_best_case(arr, n);
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
                continue;
        }

        printf("\nLista antes da ordenacao: ");
        print_array(arr, n);

        insertion_sort(arr, n);

        printf("Lista apos a ordenacao: ");
        print_array(arr, n);
    }

    return 0;
}
