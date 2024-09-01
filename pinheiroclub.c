#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nomeDependente[100];
    char parentescoDependente[100];
    char emailDependente[100];
    double cartaoDependente;
} Dependente;

typedef struct{
    char categoria[20];
} Categoria;

typedef struct{
    char nomeCandidato[100];
    char enderecoCandidato[100];
    char bairroCandidato[100];
    char emailCandidato[100];
    double cepCandidato;
    double telefoneCandidato;
} Candidato;

typedef struct{
    Candidato candidato;
    Categoria categoria;
    Dependente dependentes[5]; // Array para até 5 dependentes.
    int num_dependentes;       // Contador de dependentes.
    double cartaoSocio;
} Socio;

Candidato candidatos[100];  // Array para armazenar até 100 candidatos.
Socio socios[100];  // Array para armazenar até 100 sócios.
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

int main(){
    int opcao;
    char nome_procurado[100];

    while(1){
        printf("======= SISTEMA DE GERENCIA DO PINHEIRO SPORT CLUB =======\n");
        printf("1 - Registrar candidato.\n");
        printf("2 - Listar todos os candidatos.\n");
        printf("3 - Consultar candidato especifico.\n");
        printf("4 - Registrar socio.\n");
        printf("5 - Listar todos os socios.\n");
        printf("6 - Consultar socio especifico.\n");
        printf("7 - Sair do Sistema.\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
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
                printf("======= VOCE SAIU DO SISTEMA =======\n");
                return 0;
            default:
                printf("======= OPCAO INVALIDA ======\n");
        }
    }

    return 0;
}

Candidato registrarCandidato(){
    Candidato nomeC;

    printf("Digite o nome completo do candidato %d: ", num_candidato + 1);
    fgets(nomeC.nomeCandidato, 100, stdin);

    printf("Digite o endereco completo do candidato %d: ", num_candidato + 1);
    fgets(nomeC.enderecoCandidato, 100, stdin);

    printf("Digite o bairro do candidato %d: ", num_candidato + 1);
    fgets(nomeC.bairroCandidato, 100, stdin);

    printf("Digite o email completo do candidato %d: ", num_candidato + 1);
    fgets(nomeC.emailCandidato, 100, stdin);

    printf("Digite o CEP do candidato %d: ", num_candidato + 1);
    scanf("%lf", &nomeC.cepCandidato);
    getchar();

    printf("Digite o telefone do candidato %d: ", num_candidato + 1);
    scanf("%lf", &nomeC.telefoneCandidato);
    getchar();

    return nomeC;
}

void listarCandidatos(){
    if(num_candidato == 0) printf("======= NENHUM CANDIDATO CADASTRADO ======\n");
    for(int i = 0; i < num_candidato; i++){
        printf("___________________________________________________\n");
        printf("Nome do candidato %d: %s", i+1, candidatos[i].nomeCandidato);
        printf("Endereco do candidato %d: %s", i+1, candidatos[i].enderecoCandidato);
        printf("Bairro do candidato %d: %s", i+1, candidatos[i].bairroCandidato);
        printf("Email do candidato %d: %s", i+1, candidatos[i].emailCandidato);
        printf("CEP do candidato %d: %.0lf\n", i+1, candidatos[i].cepCandidato);
        printf("Telefone do candidato %d: %.0lf\n", i+1, candidatos[i].telefoneCandidato);
        printf("___________________________________________________\n\n");
    }
}

void consultarCandidato(Candidato candidatos[], int num_candidatos, char nome_procurado[]){
    int encontrado = 0;

    for(int i = 0; i < num_candidatos; i++){
        if(strcmp(candidatos[i].nomeCandidato, nome_procurado) == 0){
            printf("___________________________________________________\n");
            printf("======= CANDIDATO ENCONTRADO =======\n");
            printf("Nome do candidato %d: %s", i+1, candidatos[i].nomeCandidato);
            printf("Endereco do candidato %d: %s", i+1, candidatos[i].enderecoCandidato);
            printf("Bairro do candidato %d: %s", i+1, candidatos[i].bairroCandidato);
            printf("Email do candidato %d: %s", i+1, candidatos[i].emailCandidato);
            printf("CEP do candidato %d: %.0lf\n", i+1, candidatos[i].cepCandidato);
            printf("Telefone do candidato %d: %.0lf\n", i+1, candidatos[i].telefoneCandidato);
            printf("___________________________________________________\n\n");
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("======= CANDIDATO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
    }
}

Socio registrarSocio(){
    Socio novoSocio;
    char nome_procurado[100];
    int encontrado = 0, categoria, depen;

    printf("Digite o nome do candidato que deseja registrar como socio: ");
    fgets(nome_procurado, 100, stdin);

    for(int i = 0; i < num_candidato; i++){
        if(strcmp(candidatos[i].nomeCandidato, nome_procurado) == 0){
            novoSocio.candidato = candidatos[i];  // Copiar informações do candidato

            printf("Deseja atribuir uma categoria ao socio?\n 1 - Sim\n 2 - Nao\n");
            scanf("%d", &categoria);
            getchar();
            
            if(categoria == 1){
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

                if (depen == 1 && novoSocio.num_dependentes < 5) {
                    novoSocio.dependentes[novoSocio.num_dependentes] = registrarDependente();
                    novoSocio.num_dependentes++;
                } else {
                    break;
                }
            }

            for(int j = i; j < num_candidato - 1; j++){
                candidatos[j] = candidatos[j + 1]; // Deslocar todos os candidatos subsequentes para a esquerda
            }
            num_candidato--; // Reduzir o número total de candidatos
        	printf("======= QUANTIDADE DE CANDIDATOS ATUALIZADA =======\n");

            printf("======= SOCIO REGISTRADO COM SUCESSO =======\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("======= CANDIDATO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
    }

    return novoSocio;
}

void listarSocios(){
    if(num_socio == 0) printf("======= NENHUM SOCIO CADASTRADO ======\n");
    for(int i = 0; i < num_socio; i++){
        printf("___________________________________________________\n");
        printf("Nome do socio %d: %s", i+1, socios[i].candidato.nomeCandidato);
        printf("Endereco do socio %d: %s", i+1, socios[i].candidato.enderecoCandidato);
        printf("Bairro do socio %d: %s", i+1, socios[i].candidato.bairroCandidato);
        printf("Email do socio %d: %s", i+1, socios[i].candidato.emailCandidato);
        printf("CEP do socio %d: %.0lf\n", i+1, socios[i].candidato.cepCandidato);
        printf("Telefone do socio %d: %.0lf\n", i+1, socios[i].candidato.telefoneCandidato);
        printf("Numero do cartao de socio %d: %.0lf\n", i+1, socios[i].cartaoSocio);
        printf("Categoria do socio %d: %s", i+1, socios[i].categoria.categoria);

        if (socios[i].num_dependentes > 0) {
            printf("DEPENDENTES DO SOCIO %d:\n", i+1);
            for (int j = 0; j < socios[i].num_dependentes; j++) {
                printf("Dependente %d:\n", j+1);
                printf("Nome: %s", socios[i].dependentes[j].nomeDependente);
                printf("Parentesco: %s", socios[i].dependentes[j].parentescoDependente);
                printf("Email: %s", socios[i].dependentes[j].emailDependente);
                printf("Cartao: %.0lf\n", socios[i].dependentes[j].cartaoDependente);
            }
        }else{
            printf("SEM DEPENDENTES\n");
        }

        printf("___________________________________________________\n\n");
    }
}

void consultarSocio(Socio socios[], int num_socios, char nome_procurado[]){
    int encontrado = 0;

    for(int i = 0; i < num_socios; i++){
        if(strcmp(socios[i].candidato.nomeCandidato, nome_procurado) == 0){
            printf("___________________________________________________\n");
            printf("======= SOCIO ENCONTRADO =======\n");
            printf("Nome do socio %d: %s", i+1, socios[i].candidato.nomeCandidato);
            printf("Endereco do socio %d: %s", i+1, socios[i].candidato.enderecoCandidato);
            printf("Bairro do socio %d: %s", i+1, socios[i].candidato.bairroCandidato);
            printf("Email do socio %d: %s", i+1, socios[i].candidato.emailCandidato);
            printf("CEP do socio %d: %.0lf\n", i+1, socios[i].candidato.cepCandidato);
            printf("Telefone do socio %d: %.0lf\n", i+1, socios[i].candidato.telefoneCandidato);
            printf("Numero do cartao de socio %d: %.0lf\n", i+1, socios[i].cartaoSocio);
            printf("Categoria do socio %d: %s", i+1, socios[i].categoria.categoria);

            if (socios[i].num_dependentes > 0) {
                printf("DEPENDENTES DO SOCIO %d:\n", i+1);
                for (int j = 0; j < socios[i].num_dependentes; j++) {
                    printf("Dependente %d:\n", j+1);
                    printf("Nome: %s", socios[i].dependentes[j].nomeDependente);
                    printf("Parentesco: %s", socios[i].dependentes[j].parentescoDependente);
                    printf("Email: %s", socios[i].dependentes[j].emailDependente);
                    printf("Cartao: %.0lf\n", socios[i].dependentes[j].cartaoDependente);
                }
            }

            printf("___________________________________________________\n\n");
            encontrado = 1;
            break;
        }else{
            printf("SEM DEPENDENTES\n");
        }
        
    }

    if(!encontrado){
        printf("======= SOCIO COM O NOME '%s' NAO ENCONTRADO =======.\n", nome_procurado);
    }
}

Categoria registrarCategoria(){
    Categoria novaCategoria;
    int opcao;

    printf("Escolha a categoria do socio:\n");
    printf("1 - Ouro\n");
    printf("2 - Prata\n");
    printf("3 - Bronze\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 1:
            strcpy(novaCategoria.categoria, "Ouro\n");
            break;
        case 2:
            strcpy(novaCategoria.categoria, "Prata\n");
            break;
        case 3:
            strcpy(novaCategoria.categoria, "Bronze\n");
            break;
    }

    return novaCategoria;
}

Dependente registrarDependente(){
    Dependente novoDependente;

    printf("Digite o nome completo do dependente: ");
    fgets(novoDependente.nomeDependente, 100, stdin);

    printf("Digite o parentesco do dependente: ");
    fgets(novoDependente.parentescoDependente, 100, stdin);

    printf("Digite o email do dependente: ");
    fgets(novoDependente.emailDependente, 100, stdin);

    printf("Digite o numero do cartao do dependente: ");
    scanf("%lf", &novoDependente.cartaoDependente);
    getchar();

    return novoDependente;
}


