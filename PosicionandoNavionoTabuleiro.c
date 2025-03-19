#include <stdio.h>

#define TAM_TABULEIRO 10  // Tamanho do tabuleiro
#define TAM_NAVIO 3      // Tamanho dos navios

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Validação para garantir que o navio não ultrapasse os limites
    if (coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;  // Marca as posições com o valor 3
        }
    } else {
        printf("Posicionamento horizontal do navio fora dos limites.\n");
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Validação para garantir que o navio não ultrapasse os limites
    if (linha + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;  // Marca as posições com o valor 3
        }
    } else {
        printf("Posicionamento vertical do navio fora dos limites.\n");
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (representando água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas para os navios
    int linhaHorizontal = 2, colunaHorizontal = 3; // Posição inicial do navio horizontal
    int linhaVertical = 5, colunaVertical = 6;     // Posição inicial do navio vertical

    // Posiciona os navios
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);

    // Exibe o tabuleiro
    printf("Tabuleiro após o posicionamento dos navios:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
