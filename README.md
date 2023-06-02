# vending_machine

Projeto de uma máquina de vendas automática idealizado em C++ para a matéria de Algorítimo e Lógica de Programação da FATEC-RP

# Os alunos responsáveis pela elaboração do projeto foram:

    Aluno: Robson Douglas dos Santos Gomes
    RA: 2840482313007

    Aluno: Murilo Lucas da Silva Vianna
    RA: 2840482313013

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

1. Quando entrar no modo administrado, será exibida a mensagem para: a. repor produtos faltantes; b. listar um invetário dos produtos e suas quantidade; c. listar quanto a máquina já faturou e ainda pode faturar.


A. Quando quiser repor produtos, o administrador deve informar o nome do produto e a quantidade que deseja repor.


Melhorias:

1. a reposição de estoque não está funcionando - OK
2. adicionar verificação para apenas numeros com separação de ponto no pagamento
3. adicionar a opção de enter sair do menu inventario e faturamento - OK
4. adicionar senha para entrar no modo administrador - OK
5. passar as variaveis globais para o escopo das funções que a utilizam
6. Ajustar os titulos dos menus - OK
7. Opção retornar no menu reposição - OK;
8. Clear na troca de tela;