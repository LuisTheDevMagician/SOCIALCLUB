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
void consultarCandidato(Candidato candidatos[], int num_candidatos, char nome_procurado[]);
Socio registrarSocio();
void listarSocios();
void consultarSocio(Socio socios[], int num_socios, char nome_procurado[]);
Categoria registrarCategoria();
Dependente registrarDependente();
void registrarMensalidade();
void listarMensalidades();
void consultarMensalidade(Socio socios[], int num_socios, char nome_procurado[]);

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
        printf("10 - Sair do sistema.\n");
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
                consultarCandidato(candidatos, num_candidato, nome_procurado);
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
                consultarSocio(socios, num_socio, nome_procurado);
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
                consultarMensalidade(socios, num_socio, nome_procurado);
                break;
            case 10:
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

void consultarCandidato(Candidato candidatos[], int num_candidatos, char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_candidatos; i++) {
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
        printf("======= CANDIDATO NAO ENCONTRADO =======\n");
    }

    return novoSocio;
}

void listarSocios() {
    if (num_socio == 0) {
        printf("======= NENHUM SOCIO CADASTRADO ======\n");
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
            printf("Cartao do socio: %.0lf\n", socios[i].cartaoSocio);

            // Listar dependentes, se houver
            if (socios[i].num_dependentes > 0) {
                printf("Dependentes:\n");
                for (int j = 0; j < socios[i].num_dependentes; j++) {
                    printf("  Nome: %s", socios[i].dependentes[j].nomeDependente);
                    printf("  Parentesco: %s", socios[i].dependentes[j].parentescoDependente);
                    printf("  Email: %s", socios[i].dependentes[j].emailDependente);
                    printf("  Cartao: %.0lf\n", socios[i].dependentes[j].cartaoDependente);
                }
            } else {
                printf("Nao possui dependentes.\n");
            }

            printf("___________________________________________________\n\n");
        }
    }
}

void consultarSocio(Socio socios[], int num_socios, char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socios; i++) {
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
            printf("Cartao do socio: %.0lf\n", socios[i].cartaoSocio);

            // Listar dependentes, se houver
            if (socios[i].num_dependentes > 0) {
                printf("Dependentes:\n");
                for (int j = 0; j < socios[i].num_dependentes; j++) {
                    printf("  Nome: %s", socios[i].dependentes[j].nomeDependente);
                    printf("  Parentesco: %s", socios[i].dependentes[j].parentescoDependente);
                    printf("  Email: %s", socios[i].dependentes[j].emailDependente);
                    printf("  Cartao: %.0lf\n", socios[i].dependentes[j].cartaoDependente);
                }
            } else {
                printf("Nao possui dependentes.\n");
            }

            printf("___________________________________________________\n\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
    }
}

Categoria registrarCategoria() {
    Categoria novaCategoria;
    printf("Digite a categoria do socio: ");
    fgets(novaCategoria.categoria, 20, stdin);
    return novaCategoria;
}

Dependente registrarDependente() {
    Dependente nomeD;

    printf("Digite o nome completo do dependente: ");
    fgets(nomeD.nomeDependente, 100, stdin);

    printf("Digite o parentesco do dependente: ");
    fgets(nomeD.parentescoDependente, 100, stdin);

    printf("Digite o email completo do dependente: ");
    fgets(nomeD.emailDependente, 100, stdin);

    printf("Digite o numero do cartao do dependente: ");
    scanf("%lf", &nomeD.cartaoDependente);
    getchar();

    return nomeD;
}

void registrarMensalidade() {
    char nome_procurado[100];
    int encontrado = 0;

    printf("Digite o nome do socio para registrar a mensalidade: ");
    fgets(nome_procurado, 100, stdin);


    for (int i = 0; i < num_socio; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades < MAX_MENSALIDADES) {
                Mensalidade novaMensalidade;

                printf("Digite a data de vencimento (dd mm aaaa): ");
                scanf("%lf %lf %lf", &novaMensalidade.dia1, &novaMensalidade.mes1, &novaMensalidade.ano1);

                printf("Digite o valor da mensalidade: ");
                scanf("%lf", &novaMensalidade.valorMensalidade);

                printf("Digite a data de pagamento (dd mm aaaa): ");
                scanf("%lf %lf %lf", &novaMensalidade.dia2, &novaMensalidade.mes2, &novaMensalidade.ano2);

                printf("Digite os juros aplicados: ");
                scanf("%lf", &novaMensalidade.jurosMensalidade);

                printf("Digite o valor pago: ");
                scanf("%lf", &novaMensalidade.valorPagoMensalidade);

                // Cálculo de atraso e saldo
            novaMensalidade.calculoD = (novaMensalidade.dia2 + (novaMensalidade.mes2 * 30) + (novaMensalidade.ano2 * 365)) - (novaMensalidade.dia1 + (novaMensalidade.mes1 * 30) + (novaMensalidade.ano1 * 365));
            novaMensalidade.calculoV = novaMensalidade.valorPagoMensalidade - novaMensalidade.valorMensalidade;

            if(novaMensalidade.calculoD == 0 && novaMensalidade.calculoV == 0){
                strcpy(novaMensalidade.mensalidadeQuitada, "Sim");
            }else{
                strcpy(novaMensalidade.mensalidadeQuitada, "Nao");
            }

                socios[i].mensalidade[socios[i].numMensalidades] = novaMensalidade;
                socios[i].numMensalidades++;

                printf("======= MENSALIDADE REGISTRADA COM SUCESSO =======\n");
            } else {
                printf("======= LIMITE DE MENSALIDADES ATINGIDO =======\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO NAO ENCONTRADO =======\n");
    }
}

void listarMensalidades() {
    if (num_socio == 0) {
        printf("======= NENHUM SOCIO CADASTRADO ======\n");
        return;
    }

    for (int i = 0; i < num_socio; i++) {
        if (socios[i].numMensalidades > 0) {
            printf("Mensalidades do socio: %s", socios[i].candidato.nomeCandidato);
            for (int j = 0; j < socios[i].numMensalidades; j++) {
                Mensalidade m = socios[i].mensalidade[j];
                printf("Mensalidade %d:\n", j + 1);
                printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", m.dia1, m.mes1, m.ano1);
                printf("Valor: %.2lf\n", m.valorMensalidade);
                printf("Data de pagamento: %.0lf/%.0lf/%.0lf\n", m.dia2, m.mes2, m.ano2);
                printf("Juros: %.2lf\n", m.jurosMensalidade);
                printf("Valor pago: %.2lf\n", m.valorPagoMensalidade);
                printf("Mensalidade quitada: %s\n", m.mensalidadeQuitada);
                printf("Atraso em dias: %.0f\n", m.calculoD);
                printf("Diferenca de valor: %.2lf\n", m.calculoV);
                printf("-------------------------------------------------\n");
            }
        } else {
            printf("O socio %s nao possui mensalidades registradas.\n", socios[i].candidato.nomeCandidato);
        }
        printf("=================================================\n");
    }
}

void consultarMensalidade(Socio socios[], int num_socios, char nome_procurado[]) {
    int encontrado = 0;

    for (int i = 0; i < num_socios; i++) {
        if (strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0) {
            if (socios[i].numMensalidades > 0) {
                printf("Mensalidades do socio: %s", socios[i].candidato.nomeCandidato);
                for (int j = 0; j < socios[i].numMensalidades; j++) {
                    Mensalidade m = socios[i].mensalidade[j];
                    printf("Mensalidade %d:\n", j + 1);
                    printf("Data de vencimento: %.0lf/%.0lf/%.0lf\n", m.dia1, m.mes1, m.ano1);
                    printf("Valor: %.2lf\n", m.valorMensalidade);
                    printf("Data de pagamento: %.0lf/%.0lf/%.0lf\n", m.dia2, m.mes2, m.ano2);
                    printf("Juros: %.2lf\n", m.jurosMensalidade);
                    printf("Valor pago: %.2lf\n", m.valorPagoMensalidade);
                    printf("Mensalidade quitada: %s\n", m.mensalidadeQuitada);
                    printf("Atraso em dias: %.0lf\n", m.calculoD);
                    printf("Diferenca de valor: %.2lf\n", m.calculoV);
                    printf("-------------------------------------------------\n");
                }
            } else {
                printf("O socio %s nao possui mensalidades registradas.\n", socios[i].candidato.nomeCandidato);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
    }
}
