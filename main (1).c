#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXCOMPUT 100 // define o máximo de computadores
#define MAXINTERV 100 // define o máximo de intervenções

// Criação de uma Estrutura para representar um Computador Portátil
struct ComputadorPortatil {
    int id;
    char designacao[50];
    char colaborador[50];
    char dataAtribuicao[20];
    char estado[20];
    float valor;
};

// Criação de uma estrutura para representar uma Intervenção
struct Intervencao {
    char descricao[100];
    float custo;
    int id;
};

// Criação de uma estrutura para representar o Gestor de Computadores
struct GestorComputadores {
    struct ComputadorPortatil computadores[MAXCOMPUT];
    struct Intervencao intervencoes[MAXINTERV];
    int totalComputadores;
    int intervencoesSolicitadas;
    int intervencoesEfetuadas;
};

// Função para adicionar um novo Computador portátil
void adicionarComputador(struct GestorComputadores *gestor) {
    // Verifica se o limite de computadores não foi alcançado
    if (gestor->totalComputadores < MAXCOMPUT) {

        // Solicita informações ao usuário

        printf("Insira o número de Identificação: ");
        scanf("%d", &gestor->computadores[gestor->totalComputadores].id);

        printf("Insira a designação: ");
        scanf("%s", gestor->computadores[gestor->totalComputadores].designacao);

        printf("Insira o nome do colaborador: ");
        scanf(" %[^\n]s", gestor->computadores[gestor->totalComputadores].colaborador);

        printf("Insira a data de Atribuição (DD/MM/AAAA): ");
        scanf("%s", gestor->computadores[gestor->totalComputadores].dataAtribuicao);

        printf("Digite o estado do computador (operacional, por intervencionar, avariado): ");
        scanf("%s", gestor->computadores[gestor->totalComputadores].estado);

        printf("Digite o valor do equipamento (€): ");
        scanf("%f", &gestor->computadores[gestor->totalComputadores].valor);

        // Atualiza o número total de computadores
        gestor->totalComputadores++;

        printf("Novo computador registado com sucesso.\n");
    } else {
        printf("Limite de computadores atingido. Não é possivel adicionar mais computadores.\n");
    }
}

// Criação de uma função para adicionar uma nova intervenção
void criarIntervencao(struct GestorComputadores *gestor) {
    // Verifica se o limite de intervenções solicitadas não foi atingido
    if (gestor->intervencoesSolicitadas < MAXINTERV) {
        // Solicita informações ao usuário
        printf("Insira a descrição da intervenção: ");
        scanf(" %[^\n]s", gestor->intervencoes[gestor->intervencoesSolicitadas].descricao);

        printf("Digite o custo da intervenção (€): ");
        scanf("%f", &gestor->intervencoes[gestor->intervencoesSolicitadas].custo);

        // Atualiza a quantidade de intervenções solicitadas
        gestor->intervencoesSolicitadas++;

        printf("Intervenção registrada com sucesso.\n");
    } else {
        printf("Limite de intervenções solicitadas alcançado. Não é possível solicitar mais intervenções.\n");
    }
}

// Criação de uma função para listar Computadores
void listarComputadores(struct GestorComputadores * gestor) {
    printf("Listagem de Dados de todos os Computadores:\n");
    for(int i = 0; i < gestor -> totalComputadores; ++i) {
        printf("ID: %d\n", gestor -> computadores[i].id);
        printf("Designação: %s\n", gestor -> computadores[i].designacao);
        printf("Colaborador: %s\n", gestor -> computadores[i].colaborador);
        printf("Data de Atribuição: %s\n", gestor -> computadores[i].dataAtribuicao);
        printf("Estado: %s\n", gestor -> computadores[i].estado);
        printf("Valor: %.2f\n", gestor -> computadores[i].valor);
        printf("Intervenções Solicitadas: %d\n", gestor -> intervencoesSolicitadas);
        printf("Intervenções Efetuadas: %d\n", gestor -> intervencoesEfetuadas);
        printf("------------------------------\n");
    }
}


// Criação de uma função para listar Intervenções
void listarIntervencoes(struct GestorComputadores * gestor) {
    printf("Listagem de Dados de todas as intervenções Solicitadas:\n");
    for (int i = 0; i < gestor -> intervencoesSolicitadas; ++i) {
        printf("Descrição: %s\n", gestor -> intervencoes[i].descricao);
        printf("Custo: %.2f €\n", gestor -> intervencoes[i].custo);
        printf("------------------------------\n");
    }
    
}


// Criação de uma função para verificar dados de Computador por Solicitacao
void dadosComputadorPorSolicitacao(struct GestorComputadores *gestor) {
    int numeroSolicitacao;
    printf("Insira o número de identificação da solicitação: ");
    scanf("%d", &numeroSolicitacao);

    if (numeroSolicitacao >= 0 && numeroSolicitacao < gestor->intervencoesSolicitadas) {
        int idComputador = gestor->intervencoes[numeroSolicitacao].id;
        printf("Dados do Computador correspondente à solicitação %d:\n", numeroSolicitacao);
        printf("ID: %d\n", gestor->computadores[idComputador].id);
        printf("Designação: %s\n", gestor->computadores[idComputador].designacao);
        printf("Colaborador: %s\n", gestor->computadores[idComputador].colaborador);
        printf("Data de Atribuição: %s\n", gestor->computadores[idComputador].dataAtribuicao);
        printf("Estado: %s\n", gestor->computadores[idComputador].estado);
        printf("Valor: %.2f €\n", gestor->computadores[idComputador].valor);
        printf("Intervenções Solicitadas: %d\n", gestor->intervencoesSolicitadas);
        printf("Intervenções Efetuadas: %d\n", gestor->intervencoesEfetuadas);
    } else {
        printf("Número de solicitação inválido.\n");
    }
}


int mostrarMenu(void) {
    int escolha;

    printf("\nGestão de Computadores Portáteis\n");
    printf("-----------------------------------\n");
    printf("1. Novo Computador\n");
    printf("2. Solicitar intervenção\n");
    printf("3. Registar intervenção\n"); // Nota: A função para registrar intervenção não foi fornecida no código acima.
    printf("4. Listar Computadores\n");
    printf("5. Listar Intervenções\n");
    printf("6. Ver Dados de Computador por Solicitação\n"); // Esta opção foi adicionada baseada na função dadosComputadorPorSolicitacao
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    return escolha;
}

// Função principal que utiliza o menu interativo
int main(void) {
    struct GestorComputadores gestor = {0}; // Inicializa o gestor com zeros
    int opcao;

    do {
        opcao = mostrarMenu();

        switch (opcao) {
            case 1:
                adicionarComputador(&gestor);
                break;
            case 2:
                criarIntervencao(&gestor);
                break;
            case 3:
                // registarIntervencao(&gestor); // Implemente esta função se necessário
                break;
            case 4:
                listarComputadores(&gestor);
                break;
            case 5:
                listarIntervencoes(&gestor);
                break;
            case 6:
                dadosComputadorPorSolicitacao(&gestor);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
        }
        // Limpar o buffer de entrada após a leitura para evitar que entradas inválidas afetem a próxima leitura
        while (getchar() != '\n');

    } while (opcao != 0);

    return 0;
}
