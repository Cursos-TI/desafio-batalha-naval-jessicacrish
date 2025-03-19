#include <stdio.h>

#define TAM_TABULEIRO 10  // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3      // Tamanho dos navios

// Função para exibir o tabuleiro
// Exibe a matriz 10x10 com valores 0 (água) e 3 (parte do navio)
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Imprime o valor de cada célula, com 2 espaços para alinhamento
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n"); // Nova linha para o próximo nível do tabuleiro
    }
}

// Função para verificar se uma posição é válida para posicionar o navio
// Verifica se o navio pode ser colocado sem ultrapassar os limites e sem sobrepor outro navio
int validarPosicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    // Direção 0: Horizontal/Vertical, 1: Diagonal crescente, 2: Diagonal decrescente
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 0) {  // Horizontal
            // Verifica se o navio ultrapassa o limite da coluna
            if (coluna + i >= TAM_TABULEIRO || tabuleiro[linha][coluna + i] == 3) {
                return 0;  // Posição inválida ou já ocupada
            }
        } else if (direcao == 1) {  // Diagonal crescente
            // Verifica se o navio ultrapassa os limites do tabuleiro
            if (linha + i >= TAM_TABULEIRO || coluna + i >= TAM_TABULEIRO || tabuleiro[linha + i][coluna + i] == 3) {
                return 0;  // Posição inválida ou já ocupada
            }
        } else if (direcao == 2) {  // Diagonal decrescente
            // Verifica se o navio ultrapassa os limites do tabuleiro
            if (linha + i >= TAM_TABULEIRO || coluna - i < 0 || tabuleiro[linha + i][coluna - i] == 3) {
                return 0;  // Posição inválida ou já ocupada
            }
        }
    }
    return 1;  // Se todas as verificações passarem, a posição é válida
}

// Função para posicionar um navio na direção horizontal ou vertical
void posicionarNavioHorizontalVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Posiciona o navio horizontalmente
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;  // Marca cada célula ocupada pelo navio com o valor 3
    }
}

// Função para posicionar um navio na diagonal crescente (de cima-esquerda para baixo-direita)
void posicionarNavioDiagonalCrescente(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;  // Marca as posições ocupadas pelo navio com o valor 3
    }
}

// Função para posicionar um navio na diagonal decrescente (de cima-direita para baixo-esquerda)
void posicionarNavioDiagonalDecrescente(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;  // Marca as posições ocupadas pelo navio com o valor 3
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (representando água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 3;  // Navio horizontal
    int linhaVertical = 5, colunaVertical = 6;      // Navio vertical
    int linhaDiagonalCrescente = 0, colunaDiagonalCrescente = 0;  // Navio diagonal crescente
    int linhaDiagonalDecrescente = 6, colunaDiagonalDecrescente = 9;  // Navio diagonal decrescente

    // Verifica e posiciona os navios, caso as posições sejam válidas
    if (validarPosicao(tabuleiro, linhaHorizontal, colunaHorizontal, 0)) {
        posicionarNavioHorizontalVertical(tabuleiro, linhaHorizontal, colunaHorizontal);  // Posiciona o navio horizontal
    }

    if (validarPosicao(tabuleiro, linhaVertical, colunaVertical, 0)) {
        posicionarNavioHorizontalVertical(tabuleiro, linhaVertical, colunaVertical);  // Posiciona o navio vertical
    }

    if (validarPosicao(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente, 1)) {
        posicionarNavioDiagonalCrescente(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente);  // Posiciona o navio diagonal crescente
    }

    if (validarPosicao(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente, 2)) {
        posicionarNavioDiagonalDecrescente(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente);  // Posiciona o navio diagonal decrescente
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
