#include <iostream>

using namespace std;

#define produtos_totais 5 // Marcador utilizado para indicar quantos produtos a máquina terá

bool estoque_produto = false; // variável tipada e inicializada em falso para verificar se há estoque do produto a ser comprado. Optamos pela variável pela variável global, pois será acessada em mais de uma função.

int operacao_compra = 0, senha, operacao_adm = 0; // variáveis tipadas e inicializadas para verificar qual operação foi escolhida no modo compra e modo administrador, e senha para acesso ao modo admnistrador.Optamos pelas variáveis globais, pois serão acessadas em mais de uma função.

float troco = 0, total_vendas = 0, dinheiro_inserido = 0; // variáveis tipadas e inicializadas determinar o valor inserido pelo cliente no momento da compra e o troco a ser devolvido, se existir, e também o total de vendas realizado pela maquina. Optamos pelas variáveis globais, pois serão acessadas em mais de uma função.

struct Produto // Struct criada para estruturar o padrão de produtos que serão vendidos na máquina
{
    int codigo;
    string descricao;
    float preco;
    float quantidade;
};

Produto lista[produtos_totais]; // Vetor criado para armazenar a lista de produtos a serem vendidos

int mostra_produtos(); // Inicialização de todas as funções que serão usadas no programa
int reposicao_estoque();
void inventario();
void faturamento();
void modo_administrador();
float calculo_troco();
void abatimento_estoque();
float calculo_total_vendas();
void compra_efetuada_com_troco();
void compra_efetuada_sem_troco();
int operacao_vendas();
void troca_pagina();

int main()
{
    // Criação de todos os vetores utilizando a struct criada acima, para armazenar as caracteristicas dos produtos que serão vendidos
    lista[0].codigo = 1; 
    lista[0].descricao = "Agua";
    lista[0].preco = 3;
    lista[0].quantidade = 2;

    lista[1].codigo = 2;
    lista[1].descricao = "Refrigerante ";
    lista[1].preco = 4.75;
    lista[1].quantidade = 2;

    lista[2].codigo = 3;
    lista[2].descricao = "Chocolate";
    lista[2].preco = 3.5;
    lista[2].quantidade = 2;

    lista[3].codigo = 4;
    lista[3].descricao = "Bolacha";
    lista[3].preco = 3.25;
    lista[3].quantidade = 2;

    lista[4].codigo = 5;
    lista[4].descricao = "Salgadinho";
    lista[4].preco = 4.79;
    lista[4].quantidade = 2;

    do
    {
        mostra_produtos(); // Função que lista os produtos disponíveis na máquina

        switch (operacao_compra) // Switch que define qual opção foi selecionada na máquina
        {

        case 0:
            operacao_vendas();
            break;
        case 1:
            operacao_vendas();
            break;
        case 2:
            operacao_vendas();
            break;
        case 3:
            operacao_vendas();
            break;
        case 4:
            operacao_vendas();
            break;
        case 7:
            modo_administrador();
            break;

        case 8:
            cout << "Para desligar a máquina de vendas, informe a senha: ";
            cin >> senha;
            if (senha != 1234)
            {
                operacao_compra = 0;
                cout << "Senha incorreta, tente novamente." << endl;
                break;
            }
            else
            {
                cout << "As atividades da máquina de vendas estão sendo encerradas, até mais!" << endl;
                break;
            }
        default:
            cout << "Opção inválida, selecione novamente!" << endl;
        }
    } while (operacao_compra != 8);
    system("read");
    return 0;
}

int reposicao_estoque() // Função que pode ser utilizada para repor os produtos faltantes ou mais vendidos da máquina
{
    int produto_selecionado = 0; // tipagem e inicilização da variável do produto a ser reabastecido
    float nova_qtdade = 0;       // tipagem e inicilização da variável da quantidade do produto a ser reabastecido

    while (produto_selecionado != 99) // laço de repetição criado para exibir um menu de escolha ao administrador
    {
        cout << "\n\n\n----------------------------- REPOSIÇÃO DE ESTOQUE ----------------------------- \n\n";
        for (int i = 0; i < produtos_totais; i++) // Lista os produtos vendidos na máquina e que podem ser reabastecidos
        {
            cout << lista[i].codigo << " - " << lista[i].descricao << endl;
        }
        cout
            << "9 - VOLTAR AO MENU PRINCIPAL" << endl;

        cout << "\n\nDigite o código do produto que deseja repor: ";
        cin >> produto_selecionado;

        if (produto_selecionado == 9) // Se "9" for selecionado ele volta para o menu principal do administrador
        {
            break;
        }
        else if (produto_selecionado > produtos_totais) // Se o administrador digitar um número que não existe na lista, será exibida uma mensagem informando o ocorrido.
        {
            cout << "O código informado não existe, tente novamente.";
            continue;
        }

        produto_selecionado -= 1; // substração de um, pois o vetor inicia na posição zero, mas no Menu os produtos iniciam em "1"

        cout << "Digite a nova quantidade: ";
        cin >> nova_qtdade;

        lista[produto_selecionado].quantidade += nova_qtdade; // Soma a quantidade adicionada a quantidade que já havia em sistema

        cout << "\n\nOPERAÇÃO EFETUADA COM SUCESSO!\n\n"; // Mensagem informando que a operação foi realizada.
        cout << "Foram adicionadas " << nova_qtdade << " unidades no estoque do produto " << lista[produto_selecionado].descricao << endl;
        cout << "A quantidade atualizada é de " << lista[produto_selecionado].quantidade << " unidades." << endl;
        cout << "\nPressione 'ENTER' para realizar nova reposição" << endl;

        system("read || pause");
        troca_pagina();
    };
    return 0;
}

void inventario() // Lista a quantidade de cada produto disponível para venda na máquina
{
    cout << "\n\n\n----------------------------- INVENTÁRIO ----------------------------- \n\n";
    cout << "O estoque atual possui os seguintes produtos e quantidades: " << endl;

    for (int i = 0; i < produtos_totais; i++) // laço de repetição criado acessar cada um dos itens e suas respectivas quantidades.
    {
        cout << lista[i].codigo << " - " << lista[i].descricao << " ----------------------- " << lista[i].quantidade << " unidade(s)." << endl;
    }
    cout << "\nPressione 'ENTER' para retornar ao painel do administrador" << endl;

    system("read || pause");
    troca_pagina();
}

void faturamento() // Calcula o quanto a máquina ja faturou e ainda pode faturar
{
    float vendas_futuras = 0; // tipagem e inicilização da variável que calcula as vendas futuras da máquina

    for (int i = 0; i < produtos_totais; i++) // laço de repetição criado acessar cada um dos itens e suas respectivas quantidades e preços, realizando um operação matematica para identificar o faturamento com as vendas que ainda podem ser realizadas.
    {
        vendas_futuras += lista[i].preco * lista[i].quantidade; 
    }

    cout << "\n\n\n----------------------------- FATURAMENTO -----------------------------\n\n";
    cout << "Total faturado com as vendas já realizadas: R$ " << total_vendas << endl; // Esse valor será obtido ao final de cada venda, como pode ser melhor compreendido no operacao_vendas
    cout << "Total a ser faturado com vendas futuras: R$ " << vendas_futuras << endl;
    cout << "\nPressione 'ENTER' para retornar ao painel do administrador" << endl;

    system("read || pause");
    troca_pagina();
}

void modo_administrador()
{
    cout << "Você está no Modo Administrador. \n\nPor favor, digite a senha: "; // Para maior segurança, para entrar no modo administrador é necessário inserir a senha (1234)
    cin >> senha;

    if (senha != 1234)
    {
        cout << "Senha incorreta, tente novamente.";
    }
    else
    {

        troca_pagina(); // Função que limpa o código na tela
        do // laço de repetição criado para exibir menu do modo administrador, com as opções disponiveis.
        {
            cout << "\n\n\n----------------------------- Bem vindo ao Modo Administrador! -----------------------------\n\n";
            cout << "1 - Repor o estoque" << endl;
            cout << "2 - Realizar Inventário" << endl;
            cout << "3 - Faturamento da máquina" << endl;
            cout << "9 - SAIR DO MODO ADMINISTRADOR" << endl;
            cout << "\n\nDigite o código do operação que deseja realizar: ";
            cin >> operacao_adm;

            switch (operacao_adm)
            {
            case 1:
                troca_pagina();
                reposicao_estoque();
                break;

            case 2:
                troca_pagina();
                inventario();
                break;

            case 3:
                troca_pagina();
                faturamento();
                break;

            case 9:
                troca_pagina();
                cout << "\nRetornando ao modo de usuário, até mais!" << endl;
                break;

            default:
                cout << "\nOpção inválida, selecione novamente!";
            }

        } while (operacao_adm != 9);
    }
}

void compra_efetuada_com_troco() // Função que retorna a mensagem padrão caso o cliente tenha troco a receber na compra do produto
{
    cout << "\n****  Compra realizada com suceso! **** " << endl;
    cout << "\n**** O seu troco é de R$ " << troco << " **** " << endl;
    cout << "\n**** Retire o seu produto! **** " << endl;
    cout << "\n **** Pressione 'ENTER' para realizar um nova compra! **** " << endl;
    system("read || pause");
    troca_pagina();
}

void compra_efetuada_sem_troco() // Função que retorna a mensagem padrão caso o cliente não tenha troco a receber na compra do produto
{
    cout << "\n****  Compra realizada com suceso! **** " << endl;
    cout << "\n**** Retire o seu produto! **** " << endl;
    cout << "\n **** Pressione 'ENTER' para realizar um nova compra! **** " << endl;
    system("read || pause");
    troca_pagina();
}

bool verifica_estoque(int operacao_compra) // Função que verifica se o produto escolhido pelo cliente tem estoque positivo
{
    estoque_produto = lista[operacao_compra].quantidade >= 1;
    return estoque_produto;
}

float calculo_troco(float dinheiro_inserido, int operacao_compra) // Função que recebe o dinheiro inserido pelo cliente e calculo o valor de seu troco.
{
    troco = dinheiro_inserido - lista[operacao_compra].preco;
    return troco;
}

void abatimento_estoque(int operacao_compra) // Função que diminiu uma unidade da quantidade total do produto comprado pelo cliente
{
    lista[operacao_compra].quantidade -= 1;
}

int mostra_produtos() // Função que lista os produtos disponíveis na máquina
{

    cout << "\n\n\n----------------------------- Bem vindo a máquina de vendas automáticas FATEC-RP -----------------------------\n\n\n";
    for (int i = 0; i < produtos_totais; i++) //laço de repetição criado para exibir os produtos disponiveis para comprar e seus respectivo valores, além das opções do modo administrador e desligar a máquina.
    {
        cout << lista[i].codigo << " - " << lista[i].descricao << " ----------------------- "
             << " R$ " << lista[i].preco << endl;
    }
    cout << "8 - ADMINISTRADOR" << endl;
    cout << "9 - DESLIGAR" << endl;
    cout << "\n\nDigite o código do produto que deseja comprar: ";
    cin >> operacao_compra;
    operacao_compra -= 1; // Substração realizado, visto que os vetores dos produtos iniciam em "0", e a lista dos produtos exibido ao cliente inicia em "1".
    troca_pagina(); 
    return operacao_compra;
}

float calculo_total_vendas(int operacao_compra) // Função que calcula o quanto a máquina já vendeu, sendo requisitada após o pagamento de cada venda
{
    total_vendas += lista[operacao_compra].preco;
    return total_vendas;
}

int operacao_vendas() // Função que efetua todas as etapas (e funções respectivas) durante a compra de um produto
{

    verifica_estoque(operacao_compra);

    if (estoque_produto == false) // Caso o retorno da função verifica estoque seja falso, significa que o produto não está disponível para venda, o que será informado ao usuário.
    {
        cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
    }
    else
    {
        cout << "Produto selecionado: " << lista[operacao_compra].descricao << endl; // será informado ao usuário o produto que ele selecionou.
        cout << "Insira o dinheiro na máquina: "; 
        cin >> dinheiro_inserido;

        if (dinheiro_inserido < lista[operacao_compra].preco) //verificação criada para identificar se o valor inserido pelo cliente é suficiente para pagamento
        {
            do //laço de repetição utilizado para que o cliente insira o valor correto. O laço será executado até que o cliente insira o valor correto.
            {
                cout << "O valor inserido é insulficiente para pagamento, por favor insira o valor correto: ";
                cin >> dinheiro_inserido;

            } while (dinheiro_inserido < lista[operacao_compra].preco);
        }

        calculo_troco(dinheiro_inserido, operacao_compra);
        abatimento_estoque(operacao_compra);
        calculo_total_vendas(operacao_compra);

        if (troco == 0)
        {
            compra_efetuada_sem_troco();
        }
        else

        {
            compra_efetuada_com_troco();
        }
    }

    return 0;
}

void troca_pagina() // Função que limpa o código na tela
{
    system("cls || clear"); // Limpa o código na tela, dando a impressão que uma nova página foi inicializada.
}