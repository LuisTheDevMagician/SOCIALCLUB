#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENSALIDADES 12
#define MAX_DEPENDENTES 5
#define MAX_CANDIDATOS 100
#define MAX_SOCIOS 100

typedef struct {
    double dia1, mes1, ano1;
    double valorMensalidade;
    double dia2, mes2, ano2;
    double jurosMensalidade;
    double valorPagoMensalidade;
    double calculoD;
    double calculoV;
    char mensalidadeQuitada[4]; // Ajustado para caber "Sim" ou "Nao"
} Mensalidade;

typedef struct {
    char nomeDependente[100];
    char parentescoDependente[100];
    char emailDependente[100];
    double cartaoDependente;
} Dependente;

typedef struct {
    char categoria[20];
} Categoria;

typedef struct {
    char nomeCandidato[100];
    char enderecoCandidato[100];
    char bairroCandidato[100];
    char emailCandidato[100];
    double cepCandidato;
    double telefoneCandidato;
} Candidato;

typedef struct {
    Mensalidade mensalidade[MAX_MENSALIDADES];
    Candidato candidato;
    Categoria categoria;
    Dependente dependentes[MAX_DEPENDENTES];
    int num_dependentes;
    int numMensalidades;
    double cartaoSocio;
} Socio;

// Arrays globais para armazenar candidatos e sócios
Candidato candidatos[MAX_CANDIDATOS];
Socio socios[MAX_SOCIOS];
int num_candidato = 0;
int num_socio = 0;

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
    char nome_procurado[100];

    while (1) {
        printf("======= SISTEMA DE GERENCIA DO PINHEIRO SPORT CLUB =======\n");
        printf("1 - Registrar candidato.\n");
        printf("2 - Listar todos os candidatos.\n");
        printf("3 - Consultar candidato especifico.\n");
        printf("4 - Registrar socio.\n");
        printf("5 - Listar todos os socios.\n");
        printf("6 - Consultar socio especifico.\n");
        printf("7 - Registrar Mensalidade.\n");
        printf("8 - Listar Mensalidades.\n");
        printf("9 - Consultar Mensalidade.\n");
        printf("10 - Quitar Mensalidade.\n");
        printf("11 - Sair do Sistema.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                candidatos[num_candidato] = registrarCandidato();
                num_candidato++;
                break;
            case 2:
                listarCandidatos();
                break;
            case 3:
                printf("Digite o nome do candidato a ser consultado: ");
                fgets(nome_procurado, 100, stdin);
                consultarCandidato(nome_procurado);
                break;
            case 4:
                socios[num_socio] = registrarSocio();
                num_socio++;
                break;
            case 5:
                listarSocios();
                break;
            case 6:
                printf("Digite o nome do socio a ser consultado: ");
                fgets(nome_procurado, 100, stdin);
                consultarSocio(nome_procurado);
                break;
            case 7:
                registrarMensalidade();
                break;
            case 8:
                listarMensalidades();
                break;
            case 9:
                printf("Digite o nome do socio que deseja consultar a mensalidade: ");
                fgets(nome_procurado, 100, stdin);
                consultarMensalidade(nome_procurado);
                break;
            case 10:
                printf("Digite o nome do socio que deseja Quitar a mensalidade: ");
                fgets(nome_procurado, 100, stdin);
                quitarMensalidade(nome_procurado);
                break;
            case 11:
                printf("======= VOCE SAIU DO SISTEMA =======\n");
                return 0;
            default:
                printf("======= OPCAO INVALIDA ======\n");
        }
    }
}

Candidato registrarCandidato() {
    Candidato nomeC;

    printf("Digite o nome completo do candidato: ");
    fgets(nomeC.nomeCandidato, 100, stdin);

    printf("Digite o endereco completo do candidato: ");
    fgets(nomeC.enderecoCandidato, 100, stdin);

    printf("Digite o bairro do candidato: ");
    fgets(nomeC.bairroCandidato, 100, stdin);

    printf("Digite o email completo do candidato: ");
    fgets(nomeC.emailCandidato, 100, stdin);

    printf("Digite o CEP do candidato: ");
    scanf("%lf", &nomeC.cepCandidato);
    getchar();

    printf("Digite o telefone do candidato: ");
    scanf("%lf", &nomeC.telefoneCandidato);
    getchar();

    return nomeC;
}

void listarCandidatos() {
    if (num_candidato == 0) {
        printf("======= NENHUM CANDIDATO CADASTRADO ======\n");
    } else {
        for (int i = 0; i < num_candidato; i++) {
            printf("___________________________________________________\n");
            printf("Nome do candidato: %s", candidatos[i].nomeCandidato);
            printf("Endereco do candidato: %s", candidatos[i].enderecoCandidato);
            printf("Bairro do candidato: %s", candidatos[i].bairroCandidato);
            printf("Email do candidato: %s", candidatos[i].emailCandidato);
            printf("CEP do candidato: %.0lf\n", candidatos[i].cepCandidato);
            printf("Telefone do candidato: %.0lf\n", candidatos[i].telefoneCandidato);
            printf("___________________________________________________\n\n");
        }
    }
}

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

Socio registrarSocio() {
    Socio novoSocio;
    char nome_procurado[100];
    int encontrado = 0, categoria, depen;

    printf("Digite o nome do candidato que deseja registrar como socio: ");
    fgets(nome_procurado, 100, stdin);

    for (int i = 0; i < num_candidato; i++) {
        if (strcmp(candidatos[i].nomeCandidato, nome_procurado) == 0) {
            novoSocio.candidato = candidatos[i];  // Copiar informações do candidato

            printf("Deseja atribuir uma categoria ao socio?\n 1 - Sim\n 2 - Nao\n");
            scanf("%d", &categoria);
            getchar();

            if (categoria == 1) {
                novoSocio.categoria = registrarCategoria(); // Registrar a categoria
            } else {
                strcpy(novoSocio.categoria.categoria, "Sem categoria\n"); // Se não quiser registrar
            }

            printf("Digite o numero do cartao de socio: ");
            scanf("%lf", &novoSocio.cartaoSocio);
            getchar();

            // Inicializar o número de dependentes
            novoSocio.num_dependentes = 0;

            while (1) {
                printf("Deseja atribuir um dependente ao socio?\n 1 - Sim\n 2 - Nao\n");
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

void listarSocios() {
    if (num_socio == 0) {
        printf("======= NENHUM SOCIO CADASTRADO =======\n");
    } else {
        for (int i = 0; i < num_socio; i++) {
            printf("___________________________________________________\n");
            printf("Nome do socio: %s", socios[i].candidato.nomeCandidato);
            printf("Endereco do socio: %s", socios[i].candidato.enderecoCandidato);
            printf("Bairro do socio: %s", socios[i].candidato.bairroCandidato);
            printf("Email do socio: %s", socios[i].candidato.emailCandidato);
            printf("CEP do socio: %.0lf\n", socios[i].candidato.cepCandidato);
            printf("Telefone do socio: %.0lf\n", socios[i].candidato.telefoneCandidato);
            printf("Categoria do socio: %s", socios[i].categoria.categoria);
            printf("___________________________________________________\n\n");
        }
    }
}

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

Categoria registrarCategoria() {
    Categoria novaCategoria;

    printf("Digite o nome da categoria a ser atribuida ao socio: ");
    fgets(novaCategoria.categoria, 20, stdin);

    return novaCategoria;
}

Dependente registrarDependente() {
    Dependente novoDependente;

    printf("Digite o nome completo do dependente: ");
    fgets(novoDependente.nomeDependente, 100, stdin);

    printf("Digite o parentesco do dependente: ");
    fgets(novoDependente.parentescoDependente, 100, stdin);

    printf("Digite o email do dependente: ");
    fgets(novoDependente.emailDependente, 100, stdin);

    printf("Digite o numero do cartao de dependente: ");
    scanf("%lf", &novoDependente.cartaoDependente);
    getchar();

    return novoDependente;
}

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
                printf("\n");
            } else {
                printf("O socio %s nao possui mensalidades registradas.\n", socios[i].candidato.nomeCandidato);
            }
        }
    }
}

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

void calcularJuros(char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades > 0) {
                printf("Mensalidades do socio: %s\n", socios[i].candidato.nomeCandidato);
                for (int j = 0; j < socios[i].numMensalidades; j++) {
                    if(socios[i].mensalidade[j].valorPagoMensalidade <= 0){
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

            socios[i].mensalidade[j].jurosMensalidade = 1.25;
            socios[i].mensalidade[j].valorPagoMensalidade = (((socios[i].mensalidade[j].dia2 + (socios[i].mensalidade[j].mes2 * 30) + (socios[i].mensalidade[j].ano2 * 365)) - (socios[i].mensalidade[j].dia1 + (socios[i].mensalidade[j].mes1 * 30) + (socios[i].mensalidade[j].ano1 * 365))) / 30.0) * socios[i].mensalidade[j].jurosMensalidade * socios[i].mensalidade[j].valorMensalidade;

            printf("Com uma taxa de juros de 25%% ao mes o valor a ser pago e: %.2lf\n", socios[i].mensalidade[j].valorPagoMensalidade);
            printf("Data de pagamento registrada: %.0lf/%.0lf/%.0lf\n", socios[i].mensalidade[j].dia2, socios[i].mensalidade[j].mes2, socios[i].mensalidade[j].ano2);
            break;
        }
        break;
    }
}

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



