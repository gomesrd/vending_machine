#include <iostream>

using namespace std;

#define produtos_totais 5

bool estoque_produto = false;
int senha, operacao_compra = 0, operacao_adm = 0, troco = 0;
float total_vendas = 0, dinheiro_inserido = 0, vendas_futuras = 0;

struct Produto
{
    int codigo;
    string descricao;
    float preco;
    float quantidade;
};

Produto lista[5];

void troca_pagina();

int mostra_produtos()
{

    cout << "\n\n\n----------------------------- Bem vindo a máquina de vendas automáticas FATEC-RP -----------------------------\n\n\n";
    for (int i = 0; i < produtos_totais; i++)
    {
        cout << lista[i].codigo << " - " << lista[i].descricao << " ----------------------- "
             << " R$ " << lista[i].preco << endl;
    }
    cout << "8 - ADMINISTRADOR" << endl;
    cout << "9 - DESLIGAR" << endl;
    cout << "\n\nDigite o código do produto que deseja comprar: ";
    cin >> operacao_compra;
    operacao_compra -= 1;

    troca_pagina();
    return operacao_compra;
}

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

int main()
{
    lista[0].codigo = 1;
    lista[0].descricao = "Agua";
    lista[0].preco = 3;
    lista[0].quantidade = 0;

    lista[1].codigo = 2;
    lista[1].descricao = "Refrigerante ";
    lista[1].preco = 4.75;
    lista[1].quantidade = 0;

    lista[2].codigo = 3;
    lista[2].descricao = "Chocolate";
    lista[2].preco = 3.5;
    lista[2].quantidade = 0;

    lista[3].codigo = 4;
    lista[3].descricao = "Bolacha";
    lista[3].preco = 3.25;
    lista[3].quantidade = 0;

    lista[4].codigo = 5;
    lista[4].descricao = "Salgadinho";
    lista[4].preco = 4.79;
    lista[4].quantidade = 0;

    do
    {
        mostra_produtos();

        switch (operacao_compra)
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

int reposicao_estoque()
{
    int produto_selecionado = 0;
    float nova_qtdade = 0;

    while (produto_selecionado != 99)
    {
        cout << "\n\n\n----------------------------- REPOSIÇÃO DE ESTOQUE ----------------------------- \n\n";
        for (int i = 0; i < produtos_totais; i++)
        {
            cout << lista[i].codigo << " - " << lista[i].descricao << endl;
        }
        cout
            << "9 - VOLTAR AO MENU PRINCIPAL" << endl;

        cout << "\n\nDigite o código do produto que deseja repor: ";
        cin >> produto_selecionado;

        if (produto_selecionado == 9)
        {
            break;
        }
        else if (produto_selecionado > produtos_totais)
        {
            cout << "O código informado não existe, tente novamente.";
            continue;
        }

        produto_selecionado -= 1;

        cout << "Digite a nova quantidade: ";
        cin >> nova_qtdade;

        lista[produto_selecionado].quantidade += nova_qtdade;

        cout << "\n\nOPERAÇÃO EFETUADA COM SUCESSO!\n\n";
        cout << "Foram adicionadas " << nova_qtdade << " unidades no estoque do produto " << lista[produto_selecionado].descricao << endl;
        cout << "A quantidade atualizada é de " << lista[produto_selecionado].quantidade << " unidades." << endl;
        cout << "\nPressione 'ENTER' para realizar nova reposição" << endl;

        system("read || pause");
        troca_pagina();
    };
    return 0;
}

void inventario()
{
    cout << "\n\n\n----------------------------- INVENTÁRIO ----------------------------- \n\n";
    cout << "O estoque atual possui os seguintes produtos e quantidades: " << endl;
    for (int i = 0; i < produtos_totais; i++)
    {
        cout << lista[i].codigo << " - " << lista[i].descricao << " ----------------------- " << lista[i].quantidade << " unidade(s)." << endl;
    }
    cout << "\nPressione 'ENTER' para retornar ao painel do administrador" << endl;

    system("read || pause");
    troca_pagina();
}

void faturamento()

{
    for (int i = 0; i < produtos_totais; i++)
    {
        vendas_futuras += lista[i].preco * lista[i].quantidade;
    }

    cout << "\n\n\n----------------------------- FATURAMENTO -----------------------------\n\n";
    // vendas_futuras = qtdade_agua * preco_agua;
    cout << "Total faturado com as vendas já realizadas: R$ " << total_vendas << endl;
    cout << "Total a ser faturado com vendas futuras: R$ " << vendas_futuras << endl;
    cout << "\nPressione 'ENTER' para retornar ao painel do administrador" << endl;

    system("read || pause");
    troca_pagina();
}

void modo_administrador()
{
    cout << "Você está no Modo Administrador. \n\nPor favor, digite a senha: ";
    cin >> senha;

    if (senha != 1234)
    {
        cout << "Senha incorreta, tente novamente.";
    }
    else
    {

        troca_pagina();
        do
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

void compra_efetuada_com_troco()
{
    cout << "\n****  Compra realizada com suceso! **** " << endl;
    cout << "\n**** O seu troco é de R$ " << troco << " **** " << endl;
    cout << "\n**** Retire o seu produto! **** " << endl;
    cout << "\n **** Pressione 'ENTER' para realizar um nova compra! **** " << endl;
    system("read || pause");
    troca_pagina();
}

void compra_efetuada_sem_troco()
{
    cout << "\n****  Compra realizada com suceso! **** " << endl;
    cout << "\n**** Retire o seu produto! **** " << endl;
    cout << "\n **** Pressione 'ENTER' para realizar um nova compra! **** " << endl;
    system("read || pause");
    troca_pagina();
}

bool verifica_estoque(int operacao_compra)
{
    estoque_produto = lista[operacao_compra].quantidade >= 1;
    return estoque_produto;
}

float calculo_troco(float dinheiro_inserido, int operacao_compra)
{
    troco = dinheiro_inserido - lista[operacao_compra].preco;
    return troco;
}

void abatimento_estoque(int operacao_compra)
{
    lista[operacao_compra].quantidade -= 1;
}

float calculo_total_vendas(int operacao_compra)
{
    total_vendas += lista[operacao_compra].preco;
    return total_vendas;
}

int operacao_vendas()
{

    verifica_estoque(operacao_compra);

    if (estoque_produto == false)
    {
        cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
    }
    else
    {
        cout << "Produto selecionado: " << lista[operacao_compra].descricao << endl;
        cout << "Insira o dinheiro na máquina: ";
        cin >> dinheiro_inserido;

        if (dinheiro_inserido < lista[operacao_compra].preco)
        {
            do
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

void troca_pagina()
{
    system("cls || clear");
}