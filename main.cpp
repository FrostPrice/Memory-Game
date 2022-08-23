/*
// Autores: 
     -Mateus Barbosa
     -Matheus Rocha
     -Victor André Uller
     -Leonardo Beduschi Iunes
*/

#include <iostream>
#include <locale.h> 
#include <time.h>

using namespace std; 

#define TAM 4

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Para exibir acentos
    srand(time(NULL));
 
    int matPrincipal[TAM][TAM] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8}, matGabarito[TAM][TAM], matJogo[TAM][TAM] = {0}; 
    int k = TAM; // Usado para inverter a coluna ou linha de uma matriz
    
    int modoJogo; 
    int quantidadeJogadas = 0;
    int totalRodadas = TAM * 2 * 3;
    int acertos = 0; // Define a quantidade de pares que o usuário acertou


    bool jogando = false;
    bool digitando = false;

    int posicao_1_linha, posicao_1_coluna, posicao_2_linha, posicao_2_coluna;

    // Define o modo de jogo
    modoJogo = rand() % 4;

    switch (modoJogo) {    // 0 - Jogo normal, 1 - Jogo com gabarito, 2 - Jogo com gabarito e jogador, 3 - Jogo com gabarito e jogador e jogador
        case 0: // Modo de jogo: Sem modificação (Cópia)
            for (int i = 0; i < TAM; i++) { // Linhas 
                for (int j = 0; j < TAM; j++) { // Colunas
                    matGabarito[i][j] = matPrincipal[i][j]; 
                }
            }

            break;
        case 1: // Modo de jogo: Transposta da matriz principal
            for (int i = 0; i < TAM; i++) { // Linhas
                for (int j = 0; j < TAM; j++) { // Colunas
                    matGabarito[i][j] = matPrincipal[j][i]; 
                }
            }

            break;
        case 2: // Modo de jogo: Invertida por linha da matriz principal
            for (int i = 0; i < TAM ; ++i) {
                k--;
                for(int j = 0; j < TAM; j++) {
                    matGabarito[k][j] = matPrincipal[i][j];
                }
            }
            
            break; 
        case 3: // Modo de jogo: Invertida por coluna da matriz principal
            for (int i = 0; i < TAM ; ++i) { // Linhas
                k--; 
                for(int j = 0; j < TAM; j++) { // Colunas
                    matGabarito[j][k] = matPrincipal[j][i]; 
                }
            }
            
            break; // Fim do case 3
        default: // Caso não seja nenhum dos casos anteriores
            cout << "Error. Start Panicking!"; // Erro
            system("exit"); // Encerra o programa

            break; // Fim do default
    }

    jogando = true; // Começa o jogo 
    
    while(jogando) {  // Enquanto o jogo estiver rodando
        // region: --- Rodadas
        quantidadeJogadas++;

        if(quantidadeJogadas > totalRodadas){ // Se o jogo acabou
            jogando = false;
            system("clear"); // Limpa a tela 
            cout << "-------------------------\n";
            cout << "\n\tVocê perdeu :(\n"; // Mensagem de fim de jogo
            cout << "\n-------------------------\n";
            system("read -t 3");
            return 0; // Sai do jogo
        }
        // endregion: --- Rodadas

        // region: --- Mostra a Matrix Jogo
        system("clear"); // Limpa a tela
        cout << "Você está na rodada " << quantidadeJogadas << " de " << totalRodadas << endl;
        cout << "-------------------------\n";
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {  
                cout <<  matJogo[i][j] << "\t"; // Mostra a matriz jogo
            }
            cout << "\n"; // Pula uma linha
        }
        cout << "-------------------------\n";
        // endregion: --- Mostra a Matrix Jogo
       
        // region: --- Input Usuário
        digitando = true;
        while (digitando) {
            cout << "\nDigite o índice da linha para a primeira posição escolhida: "; 
            cin >> posicao_1_linha; // Recebe o índice da linha
            cout << "\nDigite o índice da coluna para a primeira posição escolhida: ";
            cin >> posicao_1_coluna; // Recebe o índice da coluna

            if ((posicao_1_linha < 0 || posicao_1_linha > TAM - 1) || (posicao_1_coluna < 0 || posicao_1_coluna > TAM - 1)) {
                cout <<  "\nEste índice na matriz não existe.\n"; // Mensagem de erro no terminal caso o usuario digite um indice que não existe na matriz.
                system("read -t 3");
            } else if (matJogo[posicao_1_linha][posicao_1_coluna] == matGabarito[posicao_1_linha][posicao_1_coluna]) {
                cout << "Posição já escolhida. Por favor, selecione outra\n";
                system("read -t 3");
            } else {
                digitando = false;
            }
        }
        // endregion: --- Input Usuário

        // region: --- Mostra a Matriz Jogo
        system("clear"); // Limpa a tela 
        cout << "Você está na rodada " << quantidadeJogadas << " de " << totalRodadas << endl;
        cout << "-------------------------\n";
        for (int i = 0; i < TAM; i++) { // Mostra a matriz jogo 
            for (int j = 0; j < TAM; j++) { 
                if (i == posicao_1_linha && j == posicao_1_coluna) { 
                    cout <<  matGabarito[posicao_1_linha][posicao_1_coluna] << "\t"; // Mostra a matriz gabarito 
                } else {
                    cout << matJogo[i][j] << "\t"; // Mostra a matriz jogo 
                }
            }
            cout << "\n"; 
        }
        cout << "-------------------------\n";
        // endregion: --- Mostra a Matriz Jogo

        // region: --- Input Usuário
        digitando = true;
        while (digitando) {
            cout << "\nDigite o índice da linha para a segunda posição escolhida: ";
            cin >> posicao_2_linha; // Recebe o índice da segunda linha
            cout << "\nDigite o índice da coluna para a segunda posição escolhida: ";
            cin >> posicao_2_coluna; // Recebe o índice da segunda coluna

            if ((posicao_2_linha < 0 || posicao_2_linha > TAM - 1) || (posicao_2_coluna < 0 || posicao_2_coluna > TAM - 1)) {
                cout <<  "\nEste índice na matriz não existe.\n"; // Mensagem de erro no terminal caso o usuario digite um indice que não existe na matriz.
                system("read -t 3");
            } else if (matJogo[posicao_2_linha][posicao_2_coluna] == matGabarito[posicao_2_linha][posicao_2_coluna] || (posicao_2_linha == posicao_1_linha && posicao_2_coluna == posicao_1_coluna)) {
                cout << "\nPosição já escolhida. Por favor, selecione outra\n"; // Mensagem de erro no terminal caso o usuario digite um indice que já havia informado antes.
                system("read -t 3");
            } else {
                digitando = false;
            }
        }
        // endregion: --- Input Usuário

        // region: --- Mostra a Matriz Jogo
        system("clear");
        cout << "Você está na rodada " << quantidadeJogadas << " de " << totalRodadas << endl;
        cout << "-------------------------\n";
        for (int i = 0; i < TAM; i++) { 
            for (int j = 0; j < TAM; j++) {
                if (i == posicao_1_linha && j == posicao_1_coluna) { 
                    cout <<  matGabarito[posicao_1_linha][posicao_1_coluna] << "\t"; // Mostra a matriz gabarito 
                } else if (i == posicao_2_linha && j == posicao_2_coluna) {
                    cout <<  matGabarito[posicao_2_linha][posicao_2_coluna] << "\t"; // Mostra a matriz gabarito
                } else { 
                    cout << matJogo[i][j] << "\t"; // Mostra a matriz jogo
                }
            }
            cout << "\n";  
        }
        cout << "-------------------------\n";
        // endregion: --- Mostra a Matriz Jogo

        if (matGabarito[posicao_1_linha][posicao_1_coluna] == matGabarito[posicao_2_linha][posicao_2_coluna]) { // Verifica se os valores selecionados são Pares
            acertos++; // Aumenta a quantidade de pares que o usuário acertou
            matJogo[posicao_1_linha][posicao_1_coluna] = matGabarito[posicao_1_linha][posicao_1_coluna];  // Se a primeira posição for igual a segunda, a primeira posição recebe o valor da segunda posição
            matJogo[posicao_2_linha][posicao_2_coluna] = matGabarito[posicao_2_linha][posicao_2_coluna];  // Se a segunda posição for igual a primeira, a segunda posição recebe o valor da primeira posição
            cout << "\tJOGADA OK\n"; // Mensagem de sucesso
        } else {
            cout << "\tJOGADA NOK\n"; // Se as posições não forem iguais, a mensagem de erro é mostrada
        }
        system("read -t 3");

        // Se a quantidade de acertos for igual a quanitdade de pares, ele ganha o jogo
        if (acertos == TAM * 2) {  
            jogando = false; // Termina o jogo
            system("clear");
            cout << "-------------------------\n";
            cout << "\n\tVocê ganhou!\n"; // Mensagem de sucesso
            cout << "\n-------------------------\n";
            system("read -t 3");
            return 0;
        }
    }    
    return 0;
}