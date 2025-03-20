#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Valor para representar água no tabuleiro
#define AGUA 0

// Valor para representar uma parte de um navio no tabuleiro
#define NAVIO 3

// Valor para representar uma área afetada por uma habilidade
#define HABILIDADE 5

// Tamanho das matrizes de habilidade
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Função para criar a matriz de habilidade em forma de cone
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= i && j < TAMANHO_HABILIDADE - i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor a habilidade ao tabuleiro
void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = linha + i - offset;
            int y = coluna + j - offset;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona o primeiro navio horizontalmente
    int linhaNavio1 = 2;
    int colunaNavio1 = 2;
    posicionarNavioHorizontal(tabuleiro, linhaNavio1, colunaNavio1);

    // Posiciona o segundo navio verticalmente
    int linhaNavio2 = 5;
    int colunaNavio2 = 5;
    posicionarNavioVertical(tabuleiro, linhaNavio2, colunaNavio2);

    // Cria as matrizes de habilidade
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Define os pontos de origem para as habilidades
    int linhaHabilidade1 = 4;
    int colunaHabilidade1 = 4;

    int linhaHabilidade2 = 7;
    int colunaHabilidade2 = 7;

    int linhaHabilidade3 = 1;
    int colunaHabilidade3 = 7;

    // Sobrepõe as habilidades ao tabuleiro
    sobreporHabilidade(tabuleiro, habilidadeCone, linhaHabilidade1, colunaHabilidade1);
    sobreporHabilidade(tabuleiro, habilidadeCruz, linhaHabilidade2, colunaHabilidade2);
    sobreporHabilidade(tabuleiro, habilidadeOctaedro, linhaHabilidade3, colunaHabilidade3);

    // Exibe o tabuleiro com os navios e as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}