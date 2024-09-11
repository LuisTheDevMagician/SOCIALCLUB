#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENSALIDADES 12 // Número máximo de mensalidades permitida
#define MAX_DEPENDENTES 5 // Número máximo de dependentes permitidos
#define MAX_CANDIDATOS 100  // Número máximo de candidatos permitidos
#define MAX_SOCIOS 100 // Número máximo de sócios permitidos

// Estrutura para representar uma mensalidade
typedef struct {
    double dia1, mes1, ano1; // Data de vencimento da mensalidade
    double valorMensalidade; // Valor da mensalidade
    double dia2, mes2, ano2; // Data de pagamento da mensalidade
    double jurosMensalidade; // Valor dos juros da mensalidade
    double valorPagoMensalidade; // Valor pago da mensalidade
    double calculoD; // Cálculo relacionado à data
    double calculoV; // Cálculo relacionado ao valor
    char mensalidadeQuitada[4]; // Status de quitação da mensalidade ("Sim" ou "Nao")
} Mensalidade;

// Estrutura para representar um dependente
typedef struct {
    char nomeDependente[100]; // Nome do dependente
    char parentescoDependente[100];  // Parentesco do dependente com o sócio
    char emailDependente[100]; // Email do dependente
    double cartaoDependente; // Número do cartão do dependente
} Dependente;

// Estrutura para representar uma categoria
typedef struct {
    char categoria[20]; // Categoria do sócio
} Categoria;

// Estrutura para representar um candidato
typedef struct {
    char nomeCandidato[100]; // Nome do candidato
    char enderecoCandidato[100];  // Endereço do candidato
    char bairroCandidato[100]; // Bairro do candidato
    char emailCandidato[100]; // Email do canditado
    double cepCandidato; // CEP do candidato
    double telefoneCandidato; // Telefone do candidato
} Candidato;

// Estrutura para representar um sócio
typedef struct {
    Mensalidade mensalidade[MAX_MENSALIDADES];  // Array de mensalidades do sócio
    Candidato candidato; // Informações do candidato associado
    Categoria categoria; // Categoria do sócio
    Dependente dependentes[MAX_DEPENDENTES]; // Array de dependentes do sócio
    int num_dependentes; // Número de dependentes
    int numMensalidades;  // Número de mensalidades registradas
    double cartaoSocio; // Número do cartão do sócio
} Socio;

// Arrays globais para armazenar candidatos e sócios
Candidato candidatos[MAX_CANDIDATOS]; // Array de candidatos
Socio socios[MAX_SOCIOS];  // Array de sócios
int num_candidato = 0;  // Contador de candidatos
int num_socio = 0; // Contador de sócios

// Funções declaradas antes da main
Candidato registrarCandidato();
void listarCandidatos();
void consultarCandidato(char nome_procurado[]);
Socio registrarSocio();
void listarSocios();
void consultarSocio(char nome_procurado[]);
Categoria registrarCategoria();
Dependente registrarDependente();
void registrarMensalidade();
void listarMensalidades();
void consultarMensalidade(char nome_procurado[]);
void calcularJuros(char nome_procurado[]);
void quitarMensalidade(char nome_procurado[]);




int main() {
    int opcao;
    char nome_procurado[100]; // Buffer para receber o nome procurado

    // Loop do menu principal do sistema
    while (1) {
        printf("======= SISTEMA DE GERENCIA DO PINHEIRO SPORT CLUB =======\n");
        printf("1 - Registrar candidato.\n");
        printf("2 - Consultar candidato especifico.\n");
        printf("3 - Registrar socio.\n");
        printf("4 - Consultar socio especifico.\n");
        printf("5 - Registrar Mensalidade.\n");
        printf("6 - Listar Mensalidades.\n");
        printf("7 - Consultar Mensalidade.\n");
        printf("8 - Quitar Mensalidade.\n");
        printf("9 - Sair do Sistema.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Leitura da opção escolhida pelo usuário
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                candidatos[num_candidato] = registrarCandidato(); // Registrar novo candidato
                num_candidato++; // Incrementar contador de candidatos
                break;
            case 2:
                listarCandidatos(); // Lista os candidatos
                if(num_candidato>0){
                printf("Digite o nome do candidato a ser consultado: ");
                fgets(nome_procurado, 100, stdin); // Recebe o nome procurado
                consultarCandidato(nome_procurado); // Consulta um candidato em específico
                break;
                }
                break;
            case 3:
                listarCandidatos(); // Lista os candidatos
                if(num_candidato>0){
                socios[num_socio] = registrarSocio();// Registra um novo sócio
                num_socio++; // Incrementa o número de sócios
                break;
                }
                break;
            case 4:
                listarSocios();
                if(num_socio>0){
                printf("Digite o nome do socio a ser consultado: ");
                fgets(nome_procurado, 100, stdin);
                consultarSocio(nome_procurado);
                break;
                }
                break;
            case 5:
                listarSocios();
                if(num_socio>0){
                registrarMensalidade(); // Registra uma nova mensalidade
                break;
                }
                break;
            case 6:
                listarMensalidades(); // Lista as mensalidades
                break;
            case 7:
                listarSocios();
                if(num_socio>0){
                printf("Digite o nome do socio que deseja consultar a mensalidade: ");
                fgets(nome_procurado, 100, stdin);
                consultarMensalidade(nome_procurado); // Consulta todas as informações de uma mensalidade
                break;
                }
                break;
            case 8:
                listarSocios();
                if(num_socio>0){
                printf("Digite o nome do socio que deseja Quitar a mensalidade: ");
                fgets(nome_procurado, 100, stdin);
                quitarMensalidade(nome_procurado); // Quita completamente a mensalidade
                break;
                }
                break;
            case 9:
                printf("======= VOCE SAIU DO SISTEMA =======\n");
                return 0;
            default:
                printf("======= OPCAO INVALIDA ======\n");
        }
    }
}

// Captura os dados de um candidato (nome, endereço, bairro, e-mail, CEP, telefone) e retorna um novo candidato.
Candidato registrarCandidato() {
    Candidato nomeC; // variavel local que irá armazenar todas as informações do candidato

    printf("Digite o nome completo do candidato: ");
    fgets(nomeC.nomeCandidato, 100, stdin);

    printf("Digite o endereco completo do candidato: ");
    fgets(nomeC.enderecoCandidato, 100, stdin);

    printf("Digite o bairro do candidato: ");
    fgets(nomeC.bairroCandidato, 100, stdin);

    printf("Digite o email completo do candidato: ");
    fgets(nomeC.emailCandidato, 100, stdin);

    printf("Digite o CEP do candidato (Apenas Numeros): ");
    scanf("%lf", &nomeC.cepCandidato);
    getchar();

    printf("Digite o telefone do candidato (Apenas Numeros): ");
    scanf("%lf", &nomeC.telefoneCandidato);
    getchar();

    return nomeC; // Retorna um novo candidato
}

// Lista todos os candidatos registrados no sistema, mostrando nome e telefone de cada um.
void listarCandidatos() {
    if (num_candidato == 0) {
        printf("======= NENHUM CANDIDATO CADASTRADO ======\n");
    } else {
        for (int i = 0; i < num_candidato; i++) {
            printf("___________________________________________________\n");
            printf("Nome do candidato: %s", candidatos[i].nomeCandidato);
            printf("Telefone do candidato: %.0lf\n", candidatos[i].telefoneCandidato);
            printf("___________________________________________________\n\n");
        }
    }
}

//Busca e exibe as informações completas de um candidato específico pelo nome. 
void consultarCandidato(char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_candidato; i++) {
        if (strcmp(candidatos[i].nomeCandidato, nome_procurado) == 0) {
            printf("___________________________________________________\n");
            printf("======= CANDIDATO ENCONTRADO =======\n");
            printf("Nome do candidato: %s", candidatos[i].nomeCandidato);
            printf("Endereco do candidato: %s", candidatos[i].enderecoCandidato);
            printf("Bairro do candidato: %s", candidatos[i].bairroCandidato);
            printf("Email do candidato: %s", candidatos[i].emailCandidato);
            printf("CEP do candidato: %.0lf\n", candidatos[i].cepCandidato);
            printf("Telefone do candidato: %.0lf\n", candidatos[i].telefoneCandidato);
            printf("___________________________________________________\n\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= CANDIDATO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
    }
}

// Registra um novo sócio a partir de um candidato existente. Permite atribuir uma categoria e dependentes ao sócio e remove o candidato da lista de candidatos após o registro.
Socio registrarSocio() {
    Socio novoSocio;
    char nome_procurado[100];
    int encontrado = 0, categoria, depen;

    printf("Digite o nome do candidato que deseja registrar como socio: ");
    fgets(nome_procurado, 100, stdin);

    for (int i = 0; i < num_candidato; i++) {
        if (strcmp(candidatos[i].nomeCandidato, nome_procurado) == 0) {
            novoSocio.candidato = candidatos[i];  // Copiar informações do candidato

            // Remover o candidato da lista e reorganizar os outros candidatos
            for (int j = i; j < num_candidato - 1; j++) {
                candidatos[j] = candidatos[j + 1];
            }
            num_candidato--; // Reduzir o número de candidatos


            printf("Deseja atribuir uma categoria ao socio?\n 1 - Sim\n 2 - Nao\n");
            scanf("%d", &categoria);
            getchar();

            if (categoria == 1) {
                novoSocio.categoria = registrarCategoria(); // Registrar a categoria
            } else {
                strcpy(novoSocio.categoria.categoria, "Sem categoria\n"); // Se não quiser registrar
            }

            printf("Digite o numero do cartao de socio (Apenas Numeros): ");
            scanf("%lf", &novoSocio.cartaoSocio);
            getchar();

            // Inicializar o número de dependentes
            novoSocio.num_dependentes = 0;

            while (1) {
                printf("Deseja atribuir dependentes ao socio?\n 1 - Sim\n 2 - Nao\n");
                scanf("%d", &depen);
                getchar();

                if (depen == 1 && novoSocio.num_dependentes < MAX_DEPENDENTES) {
                    novoSocio.dependentes[novoSocio.num_dependentes] = registrarDependente();
                    novoSocio.num_dependentes++;
                } else {
        
                    break;
                }
            }

            // Inicializar o número de mensalidades
            novoSocio.numMensalidades = 0;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= CANDIDATO COM O NOME '%s' NAO ENCONTRADO =======\n", nome_procurado);
        return novoSocio;
    }

    printf("___________________________________________________\n");
    printf("======= SOCIO REGISTRADO COM SUCESSO =======\n");
    printf("Nome do socio: %s", novoSocio.candidato.nomeCandidato);
    printf("Endereco do socio: %s", novoSocio.candidato.enderecoCandidato);
    printf("Bairro do socio: %s", novoSocio.candidato.bairroCandidato);
    printf("Email do socio: %s", novoSocio.candidato.emailCandidato);
    printf("CEP do socio: %.0lf\n", novoSocio.candidato.cepCandidato);
    printf("Telefone do socio: %.0lf\n", novoSocio.candidato.telefoneCandidato);
    printf("___________________________________________________\n\n");

    return novoSocio;
}

// Exibe a lista de sócios registrados no sistema.
void listarSocios() {
    if (num_socio == 0) {
        printf("======= NENHUM SOCIO CADASTRADO =======\n");
    } else {
        for (int i = 0; i < num_socio; i++) {
            printf("___________________________________________________\n");
            printf("Nome do socio: %s", socios[i].candidato.nomeCandidato);
            printf("___________________________________________________\n\n");
        }
    }
}

// Exibe todas as informações detalhadas de um sócio, incluindo dados pessoais e dependentes, se houver.
void consultarSocio(char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            printf("___________________________________________________\n");
            printf("======= SOCIO ENCONTRADO =======\n");
            printf("Nome do socio: %s", socios[i].candidato.nomeCandidato);
            printf("Endereco do socio: %s", socios[i].candidato.enderecoCandidato);
            printf("Bairro do socio: %s", socios[i].candidato.bairroCandidato);
            printf("Email do socio: %s", socios[i].candidato.emailCandidato);
            printf("CEP do socio: %.0lf\n", socios[i].candidato.cepCandidato);
            printf("Telefone do socio: %.0lf\n", socios[i].candidato.telefoneCandidato);
            printf("Categoria do socio: %s", socios[i].categoria.categoria);
            printf("___________________________________________________\n\n");

            // Listar dependentes, se houver
            if (socios[i].num_dependentes > 0) {
                printf("Dependentes:\n");
                for (int j = 0; j < socios[i].num_dependentes; j++) {
                    printf("Nome: %s", socios[i].dependentes[j].nomeDependente);
                    printf("Parentesco: %s", socios[i].dependentes[j].parentescoDependente);
                    printf("Email: %s", socios[i].dependentes[j].emailDependente);
                    printf("Cartao: %.0lf\n", socios[i].dependentes[j].cartaoDependente);
                    printf("\n");
                }
            } else {
                printf("Nenhum dependente cadastrado.\n");
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======\n", nome_procurado);
    }
}

// Captura e retorna o nome de uma categoria para ser atribuída a um sócio.
Categoria registrarCategoria() {
    Categoria novaCategoria;

    printf("Digite o nome da categoria a ser atribuida ao socio: ");
    fgets(novaCategoria.categoria, 20, stdin);

    return novaCategoria;
}

//  Captura e retorna os dados de um dependente (nome, parentesco, e-mail, número do cartão).
Dependente registrarDependente() {
    Dependente novoDependente;

    printf("Digite o nome completo do dependente: ");
    fgets(novoDependente.nomeDependente, 100, stdin);

    printf("Digite o parentesco do dependente: ");
    fgets(novoDependente.parentescoDependente, 100, stdin);

    printf("Digite o email do dependente: ");
    fgets(novoDependente.emailDependente, 100, stdin);

    printf("Digite o numero do cartao de dependente (Apenas Numeros): ");
    scanf("%lf", &novoDependente.cartaoDependente);
    getchar();

    return novoDependente;
}

// Registra uma nova mensalidade para um sócio, capturando a data de vencimento, o valor, e definindo a mensalidade como "não quitada".
void registrarMensalidade() {
    char nome_procurado[100];
    int encontrado = 0;

    printf("Digite o nome do socio para registrar uma mensalidade: ");
    fgets(nome_procurado, 100, stdin);

    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades < MAX_MENSALIDADES) {
                Mensalidade novaMensalidade;

                printf("Digite a data de vencimento da mensalidade (dia/mes/ano): ");
                scanf("%lf/%lf/%lf", &novaMensalidade.dia1, &novaMensalidade.mes1, &novaMensalidade.ano1);
                getchar();

                printf("Digite o valor da mensalidade: ");
                scanf("%lf", &novaMensalidade.valorMensalidade);
                getchar();

                novaMensalidade.valorPagoMensalidade = 0;

                strcpy(novaMensalidade.mensalidadeQuitada, "Nao");

                // Adiciona a nova mensalidade ao array de mensalidades do socio
                socios[i].mensalidade[socios[i].numMensalidades] = novaMensalidade;
                socios[i].numMensalidades++;

                printf("======= MENSALIDADE REGISTRADA COM SUCESSO =======\n");
            } else {
                printf("======= LIMITE DE MENSALIDADES ALCANCADO =======\n");
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======\n", nome_procurado);
    }
}

// Lista todas as mensalidades registradas de todos os sócios, incluindo a data de vencimento, valor, e o status de quitação.
void listarMensalidades() {
    if (num_socio == 0) {
        printf("======= NENHUM SOCIO CADASTRADO =======\n");
    } else {
        for (int i = 0; i < num_socio; i++) {
            if (socios[i].numMensalidades > 0) {
                printf("Mensalidades do socio: %s", socios[i].candidato.nomeCandidato);
                for (int j = 0; j < socios[i].numMensalidades; j++) {
                    printf("Mensalidade %d:\n", j + 1);
                    printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia1, socios[i].mensalidade[j].mes1, socios[i].mensalidade[j].ano1);
                    printf("Valor: %.2lf\n", socios[i].mensalidade[j].valorMensalidade);
                    printf("Mensalidade quitada: %s\n", socios[i].mensalidade[j].mensalidadeQuitada);
                }
            } else {
                printf("O socio %snao possui mensalidades registradas.\n", socios[i].candidato.nomeCandidato);
            }
        }
    }
}

// Exibe as mensalidades de um sócio específico, mostrando detalhes como data de vencimento, valor, e status de quitação.
void consultarMensalidade(char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades > 0) {
                printf("Mensalidades do socio: %s\n", socios[i].candidato.nomeCandidato);
                for (int j = 0; j < socios[i].numMensalidades; j++) {
                    printf("Mensalidade %d:\n", j + 1);
                    printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia1, socios[i].mensalidade[j].mes1, socios[i].mensalidade[j].ano1);
                    printf("Valor: %.2lf\n", socios[i].mensalidade[j].valorMensalidade);
                    printf("Mensalidade quitada: %s\n", socios[i].mensalidade[j].mensalidadeQuitada);
                    if (strcmp(socios[i].mensalidade[j].mensalidadeQuitada, "Sim") == 0){
                    printf("Data de pagamento: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia2, socios[i].mensalidade[j].mes2, socios[i].mensalidade[j].ano2);
                    printf("Valor pago: %.2lf\n", socios[i].mensalidade[j].valorPagoMensalidade);
                    }
                }
            } else {
                printf("O socio %s nao possui mensalidades registradas.\n", socios[i].candidato.nomeCandidato);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======\n", nome_procurado);
    }
}

// Calcula os juros de uma mensalidade atrasada com base na data de vencimento e na data de pagamento fornecida.
void calcularJuros(char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades > 0) {
                printf("Mensalidades do socio: %s\n", socios[i].candidato.nomeCandidato);
                for (int j = 0; j < socios[i].numMensalidades; j++) {
                    if(socios[i].mensalidade[j].valorPagoMensalidade <= 0){ // Verifica se a mensalidade já foi paga ou não
                    printf("Mensalidade %d:\n", j + 1);
                    printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia1, socios[i].mensalidade[j].mes1, socios[i].mensalidade[j].ano1);
                    printf("Valor: %.2lf\n", socios[i].mensalidade[j].valorMensalidade);
                    printf("Mensalidade quitada: %s\n", socios[i].mensalidade[j].mensalidadeQuitada);
                    printf("-------------------------------------------------\n");
                    }
                }
            }
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
        return;
    }

    int opcao = 0;
    printf("Qual mensalidade voce deseja calcular os juros: ");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado

    for (int i = 0; i < num_socio; i++) {
        for (int j = opcao - 1; j < socios[i].numMensalidades; j++) {
            printf("Mensalidade %d:\n", j + 1);
            printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia1, socios[i].mensalidade[j].mes1, socios[i].mensalidade[j].ano1);
            printf("Valor: %.2lf\n", socios[i].mensalidade[j].valorMensalidade);

            printf("Digite a data de pagamento (dia/mes/ano): ");
            scanf("%lf/%lf/%lf", &socios[i].mensalidade[j].dia2, &socios[i].mensalidade[j].mes2, &socios[i].mensalidade[j].ano2);
            getchar(); // Limpar o buffer do teclado

            socios[i].mensalidade[j].jurosMensalidade = 1.25; //Juros fiox a 25% ao mês
            // Calcula o valor a ser pago já com os juros
            socios[i].mensalidade[j].valorPagoMensalidade = (((socios[i].mensalidade[j].dia2 + (socios[i].mensalidade[j].mes2 * 30) + (socios[i].mensalidade[j].ano2 * 365)) - (socios[i].mensalidade[j].dia1 + (socios[i].mensalidade[j].mes1 * 30) + (socios[i].mensalidade[j].ano1 * 365))) / 30.0) * socios[i].mensalidade[j].jurosMensalidade * socios[i].mensalidade[j].valorMensalidade;

            printf("Com uma taxa de juros de 25%% ao mes o valor a ser pago e: %.2lf\n", socios[i].mensalidade[j].valorPagoMensalidade);
            printf("Data de pagamento registrada: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia2, socios[i].mensalidade[j].mes2, socios[i].mensalidade[j].ano2);
            break;
        }
        break;
    }
}

// Permite quitar uma mensalidade específica de um sócio.
void quitarMensalidade(char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades > 0) {
                for (int j = 0; j < socios[i].numMensalidades; j++) {
                    printf("Mensalidade %d:\n", j + 1);
                    printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia1, socios[i].mensalidade[j].mes1, socios[i].mensalidade[j].ano1);
                    printf("Valor: %.2lf\n", socios[i].mensalidade[j].valorMensalidade);
                    printf("Mensalidade quitada: %s\n", socios[i].mensalidade[j].mensalidadeQuitada);

                    // Verifica se a mensalidade já foi quitada
                    if (strcmp(socios[i].mensalidade[j].mensalidadeQuitada, "Sim") == 0) {
                        printf("Esta mensalidade ja foi quitada. Nao e possivel calcular juros ou quitá-la novamente.\n");
                        continue; // Pula para a próxima mensalidade (se houver)
                    }

                    // Caso não esteja quitada, calcular os juros antes de quitar
                    calcularJuros(nome_procurado);

                    printf("Deseja quitar esta mensalidade? (1 - Sim / 2 - Nao): ");
                    int opcao;
                    scanf("%d", &opcao);
                    getchar(); // Limpar o buffer do teclado

                    if (opcao == 1) {
                        strcpy(socios[i].mensalidade[j].mensalidadeQuitada, "Sim");

                        printf("Data de pagamento registrada: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia2, socios[i].mensalidade[j].mes2, socios[i].mensalidade[j].ano2);
                        printf("======= MENSALIDADE QUITADA COM SUCESSO =======\n");
                    }else{
                         printf("======= MENSALIDADE NAO FOI QUITADA =======\n");
                         break;
                    }
                }
            } else {
                printf("O socio %s nao possui mensalidades registradas.\n", socios[i].candidato.nomeCandidato);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======\n", nome_procurado);
    }
}


