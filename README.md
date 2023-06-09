# Vending Machine (Máquina de Vendas)

Projeto de uma máquina de vendas automática idealizado em C++ para a matéria de Algorítimo e Lógica de Programação da FATEC-RP

# Os alunos responsáveis pela elaboração do projeto foram:

    Aluno: Robson Douglas dos Santos Gomes
    RA: 2840482313007
    Análise e Desenvolvimento de Sistemas - FATEC-RP - 1º Semestre

    Aluno: Murilo Lucas da Silva Vianna
    RA: 2840482313013
    Análise e Desenvolvimento de Sistemas - FATEC-RP - 1º Semestre

# Branch

    Main
    Development
    Murilo
    Douglas

# Requisitos do programa

1. Quando o programa inicializar será exibido ao usuário uma lista de produtos, contendo a descrição e preço, além das opções do modo administrador e sair do programa, além de uma mensagem para que o usuário escola o produto.

2. Quando o usuário escolher o produto, será chamado uma função para verificar se há estoque do produto selecionado.

3. Caso não haja, será solicitado ao usuário que escolha outro produto.

4. Caso haja, será solicitado ao usuario para que insira o dinheiro na máquina

5. Após, será chamada uma função para calcular o valor do troco, subtraindo o valor inserido do valor do produto selecionado.

6. Caso o valor inserido seja insulficiente, será solicitado ao usuário que insira o valor correto. Caso novamente seja inserido o valor incorreto, será encerrada a venda.

7. Com o pagamento, será deduzido da quantidade total a unidade comprada pelo usuário.

8. Após, será informado o troco do usuário, bem como a mensagem para que ele retire o produto.

9. Programa inicia novamente.

MODO ADMINISTRADOR

1. Selecionado o modo administrador, será solicitado a senha. Caso correta, seguirá para o menu principal, caso contrário, retorna ao modo usuário.

2. Quando entrar no modo administrador, será exibido um meno com as seguinte opçoes: 
    a. repor produtos faltantes; 
    b. listar um invetário dos produtos e suas quantidade; 
    c. listar quanto a máquina já faturou e ainda pode faturar.


3. Quando quiser repor produtos, o administrador deve informar o código do produto e a quantidade que deseja repor.


# Melhorias já realizadas desde o início do projeto:

* Opção de reposição de estoque - Implementado
* Adicionar a opção de pressionar 'enter' sair do menu inventario e faturamento - Implementado
* Adicionar senha para entrar no modo administrador - Imprementado
* Adicionar senha para desligar a máquina - Imprementado
* Ajustar os titulos dos menus - Imprementado
* Opção retornar ao menu principal quando estiver no menu reposição - Imprementado
* Troca de tela quando houver mudança de menus - Implementado
* Passar as variaveis globais para o escopo local das funções que a utilizam
