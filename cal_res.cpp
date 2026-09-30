#include <iostream>
#include <iomanip>
#include <windows.h> // Necessário para aceitar acentos e UTF-8 no Windows

using namespace std;

// ===============================
// 1. TENSÃO NORMAL (σ = F / A)
// ===============================
void tensaoNormal() {
    double forca, area, tensao;

    cout << "\n===== TENSÃO NORMAL =====\n";
    cout << "Digite a força aplicada (N): ";
    cin >> forca;

    cout << "Digite a área da seção (mm²): ";
    cin >> area;

    if (area <= 0) {
        cout << "Erro: A área deve ser maior que zero!\n";
        return;
    }

    tensao = forca / area;

    cout << fixed << setprecision(2);
    cout << "Tensão normal (σ) = " << tensao << " MPa\n";
}

// ===============================
// 2. TENSÃO DE CISALHAMENTO (τ = F / A)
// ===============================
void tensaoCisalhante() {
    double forca, area, tensao;

    cout << "\n===== TENSÃO DE CISALHAMENTO =====\n";
    cout << "Digite a força de cisalhamento (N): ";
    cin >> forca;

    cout << "Digite a área da seção (mm²): ";
    cin >> area;

    if (area <= 0) {
        cout << "Erro: A área deve ser maior que zero!\n";
        return;
    }

    tensao = forca / area;

    cout << fixed << setprecision(2);
    cout << "Tensão de cisalhamento (τ) = " << tensao << " MPa\n";
}

// ===============================
// MENU DE TENSÃO
// ===============================
void menuTensao() {
    int opcao;
    do {
        cout << "\n===== TENSÃO =====\n";
        cout << "1) Normal (σ = F / A)\n";
        cout << "2) Cisalhante (τ = F / A)\n";
        cout << "3) Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                tensaoNormal(); 
                break;
            case 2: 
                tensaoCisalhante(); 
                break;
            case 3: 
                cout << "Voltando...\n"; 
                break;
            default: 
                cout << "Opção inválida!\n";
        }
    } while (opcao != 3);
}

// ===============================
// 3. DEFORMAÇÃO NORMAL (ε = ΔL / L)
// ===============================
void deformacaoNormal() {
    double deltaL, comprimentoInicial, deformacao;

    cout << "\n===== DEFORMAÇÃO NORMAL =====\n";
    cout << "Digite a variação do comprimento (ΔL em mm): ";
    cin >> deltaL;

    cout << "Digite o comprimento inicial (L em mm): ";
    cin >> comprimentoInicial;

    if (comprimentoInicial <= 0) {
        cout << "Erro: O comprimento inicial deve ser maior que zero!\n";
        return;
    }

    deformacao = deltaL / comprimentoInicial;

    cout << fixed << setprecision(4);
    cout << "Deformação normal (ε) = " << deformacao << " (adimensional)\n";
    cout << fixed << setprecision(2);
    cout << "Deformação normal em porcentagem = " << deformacao * 100 << "%\n";
}

// ===============================
// 4. DEFORMAÇÃO DE CISALHAMENTO (γ = Δx / h)
// ===============================
void deformacaoCisalhante() {
    double deltaX, altura, deformacao;

    cout << "\n===== DEFORMAÇÃO DE CISALHAMENTO =====\n";
    cout << "Digite o deslocamento (Δx em mm): ";
    cin >> deltaX;

    cout << "Digite a altura do elemento (h em mm): ";
    cin >> altura;

    if (altura <= 0) {
        cout << "Erro: A altura deve ser maior que zero!\n";
        return;
    }

    deformacao = deltaX / altura;

    cout << fixed << setprecision(4);
    cout << "Deformação de cisalhamento (γ) = " << deformacao << " radianos\n";
    cout << fixed << setprecision(2);
    cout << "Deformação de cisalhamento em porcentagem = " << deformacao * 100 << "%\n";
}

// ===============================
// MENU DE DEFORMAÇÃO
// ===============================
void menuDeformacao() {
    int opcao;
    do {
        cout << "\n===== DEFORMAÇÃO =====\n";
        cout << "1) Normal (ε = ΔL / L)\n";
        cout << "2) Cisalhamento (γ = Δx / h)\n";
        cout << "3) Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                deformacaoNormal(); 
                break;
            case 2: 
                deformacaoCisalhante(); 
                break;
            case 3: 
                cout << "Voltando...\n"; 
                break;
            default: 
                cout << "Opção inválida!\n";
        }
    } while (opcao != 3);
}

// ===============================
// MENU PRINCIPAL
// ===============================
int main() {
    // Configura o console do Windows para exibir acentos e UTF-8 corretamente
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcao;

    do {
        cout << "\n====================================\n";
        cout << " CALCULADORA DE RESISTÊNCIA\n";
        cout << "====================================\n";
        cout << "1) Tensão\n";
        cout << "2) Deformação\n";
        cout << "3) Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                menuTensao();
                break;
            case 2:
                menuDeformacao();
                break;
            case 3:
                cout << "\nPrograma encerrado.\n";
                break;
            default:
                cout << "\nOpção inválida! Tente novamente.\n";
        }

    } while (opcao != 3);

    return 0;
}