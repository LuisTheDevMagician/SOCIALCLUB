# PROJETO CLUB SOCIAL

**Professor:** Felipe Gonçalves dos Santos  
**Aluno:** Luis Eduardo Pinheiro Martins  
**Data de entrega:** 09/09/2024

## Funções Implementadas

### `registrarCandidato()`
Captura os dados de um candidato (nome, endereço, bairro, e-mail, CEP, telefone) e retorna um novo candidato.

### `listarCandidatos()`
Lista todos os candidatos registrados no sistema, mostrando nome e telefone de cada um.

### `consultarCandidato(char nome_procurado[])`
Busca e exibe as informações completas de um candidato específico pelo nome.

### `registrarSocio()`
Registra um novo sócio a partir de um candidato existente. Permite atribuir uma categoria e dependentes ao sócio e remove o candidato da lista de candidatos após o registro.

### `listarSocios()`
Exibe a lista de sócios registrados no sistema.

### `consultarSocio(char nome_procurado[])`
Exibe todas as informações detalhadas de um sócio, incluindo dados pessoais e dependentes, se houver.

### `registrarCategoria()`
Captura e retorna o nome de uma categoria para ser atribuída a um sócio.

### `registrarDependente()`
Captura e retorna os dados de um dependente (nome, parentesco, e-mail, número do cartão).

### `registrarMensalidade()`
Registra uma nova mensalidade para um sócio, capturando a data de vencimento, o valor, e definindo a mensalidade como "não quitada".

### `listarMensalidades()`
Lista todas as mensalidades registradas de todos os sócios, incluindo a data de vencimento, valor, e o status de quitação.

### `consultarMensalidade(char nome_procurado[])`
Exibe as mensalidades de um sócio específico, mostrando detalhes como data de vencimento, valor, e status de quitação.

### `calcularJuros(char nome_procurado[])`
Calcula os juros de uma mensalidade atrasada com base na data de vencimento e na data de pagamento fornecida. A função verifica se a mensalidade já foi quitada, evitando o recálculo desnecessário, e, se ainda estiver pendente, aplica a fórmula de cálculo de juros, atualiza o valor da mensalidade e imprime os detalhes, incluindo o valor final com os juros. O valor atualizado será considerado na função `quitarMensalidade` quando o pagamento for efetuado.

### `quitarMensalidade(char nome_procurado[])`
Permite quitar uma mensalidade específica de um sócio. A função busca o sócio pelo nome, verifica se há mensalidades não quitadas, e, se houver, utiliza o valor calculado automaticamente (incluindo juros, se aplicável) para marcar a mensalidade como quitada, sem a necessidade de o usuário informar o valor pago. Ela também impede que uma mensalidade já quitada seja quitada novamente.

## Como Compilar

Utilize um compilador da linguagem C como o `gcc` diretamente no terminal, ou um editor de código que já tenha um compilador embarcado como **DEV C++** e **VS Code**.
