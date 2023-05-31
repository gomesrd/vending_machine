#include <iostream>

using namespace std;

#define produtos_totais 5

bool verifica_estoque = false;
int operacao_compra = 0, operacao_adm = 0, troco = 0;
float total_vendas = 0, dinheiro_inserido = 0;

typedef struct
{
    int codigo;
    string descricao;
    float preco;
    int quantidade;
} Produto;

Produto lista[10];

int mostra_produtos();
void compra_realizada_com_troco();
void compra_realizada_sem_troco();
void reposicao_estoque();
void faturamento();
void inventario();
void modo_administrador();
int modo_vendas();

int main()
{

    do
    {
        mostra_produtos();

        operacao_compra = operacao_compra - 1;

        switch (operacao_compra)
        {

        case 0:

            verifica_estoque = lista[operacao_compra].quantidade >= 1;
            if (verifica_estoque == true)
            {
                cout << "Insira o dinheiro na máquina: ";
                cin >> dinheiro_inserido;
            }
            else
            {
                cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
                break;
            }
            modo_vendas();
            break;

        case 1:
            verifica_estoque = lista[operacao_compra].quantidade >= 1;
            if (verifica_estoque == true)
            {
                cout << "Insira o dinheiro na máquina: ";
                cin >> dinheiro_inserido;
            }
            else
            {
                cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
                break;
            }
            modo_vendas();
            break;
        case 2:
            verifica_estoque = lista[operacao_compra].quantidade >= 1;
            if (verifica_estoque == true)
            {
                cout << "Insira o dinheiro na máquina: ";
                cin >> dinheiro_inserido;
            }
            else
            {
                cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
                break;
            }
            modo_vendas();
            break;
        case 3:
            verifica_estoque = lista[operacao_compra].quantidade >= 1;
            if (verifica_estoque == true)
            {
                cout << "Insira o dinheiro na máquina: ";
                cin >> dinheiro_inserido;
            }
            else
            {
                cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
                break;
            }
            modo_vendas();
            break;
        case 4:
            verifica_estoque = lista[operacao_compra].quantidade >= 1;
            if (verifica_estoque == true)
            {
                cout << "Insira o dinheiro na máquina: ";
                cin >> dinheiro_inserido;
            }
            else
            {
                cout << "\nNão há estoque do produto selecionado, selecione outro produto.";
                break;
            }
            modo_vendas();
            break;

        case 7:
            modo_administrador();
            break;

        case 8:
            cout << "Obrigado pela visita, até mais!" << endl;
            break;

        default:
            cout << "Opção inválida, selecione novamente!" << endl;
        }
    } while (operacao_compra != 9);
    system("read");
    return 0;
}

int mostra_produtos()
{
    lista[0].codigo = 1;
    lista[0].descricao = "Agua";
    lista[0].preco = 3;
    lista[0].quantidade = 1;
    cout << lista[0].quantidade << endl;
    lista[1].descricao = "Refrigerante";
    lista[1].preco = 4;
    lista[1].quantidade = 1;
    lista[2].codigo = 3;
    lista[2].descricao = "Chocolate";
    lista[2].preco = 3.5;
    lista[2].quantidade = 1;
    lista[3].codigo = 4;
    lista[3].descricao = "Bolacha";
    lista[3].preco = 3;
    lista[3].quantidade = 1;
    lista[4].codigo = 5;
    lista[4].descricao = "Salgadinho";
    lista[4].preco = 5;
    lista[4].quantidade = 1;

    cout << "\n\n\n-------Bem vindo a máquina de vendas automáticas FATEC-RP-----------\n\n";
    for (int i = 0; i < produtos_totais; i++)
    {
        cout << lista[i].codigo << " - " << lista[i].descricao << " ------------------------------- R$ " << lista[i].preco << endl;
    }
    cout << "8 - ADMINISTRADOR" << endl;
    cout << "9 - SAIR" << endl;
    cout << "\n\nDigite o código do produto que deseja comprar: ";
    cin >> operacao_compra;
    return operacao_compra;
}

void compra_efetuada_com_troco()
{
    cout << "\n****Compra realizada com suceso!****";
    cout << "\n****O seu troco é de R$ " << troco << "****" << endl;
    cout << "\n ****Retire o seu produto!****";
}

void compra_efetuada_sem_troco()
{
    cout << "\n\n****Compra realizada com suceso!**** \n ****Retire o seu produto!****";
}

void modo_administrador()
{

    do
    {
        cout << "\n\n\n-------Bem vindo ao Modo Administrador!-------\n\n";
        cout << "1 - Repor o estoque" << endl;
        cout << "2 - Realizar Inventário" << endl;
        cout << "3 - Faturamento da máquina" << endl;
        cout << "9 - SAIR DO MODO ADMINISTRADOR" << endl;
        cout << "\n\nDigite o código do operação que deseja realizar: ";
        cin >> operacao_adm;

        switch (operacao_adm)
        {
        case 1:
            reposicao_estoque();
            break;

        case 2:
            inventario();
            break;

        case 3:
            faturamento();
            break;

        case 9:
            cout << "Retornando ao modo de usuário, até mais!" << endl;
            break;

        default:
            cout << "Opção inválida, selecione novamente!";
        }

    } while (operacao_adm != 9);
}

void reposicao_estoque()
{
    cout << "\n\n\n-------REPOSIÇÃO DE ESTOQUE-------\n\n";
    cout << "Digite o nome do produto que deseja repor: ";
    // cin >> n;
    cout << "Digite a quantidade que será reposta: ";
    // cin >> nova_qtdade;
    // qtdade_agua = qtdade_agua + nova_qtdade;
    cout << "\n\nOPERAÇÃO EFETUADA COM SUCESSO!\n\n";
    // cout << "Foram adicionadas " << nova_qtdade << " unidades no estoque do produto "
    // << "." << endl;
    // cout << "O novo saldo é de  " << qtdade_agua << " unidades.";
}

void inventario()
{
    cout << "\n\n\n-------INVENTÁRIO-------\n\n";
    cout << "O estoque atual possui os seguintes produtos e quantidades: " << endl;
    // cout << "01. Agua: " << qtdade_agua << " unidades.";
}

void faturamento()

{
    float vendas_futuras;
    cout << "\n\n\n-------FATURAMENTO-------\n\n";
    // vendas_futuras = qtdade_agua * preco_agua;
    cout << "Total faturado com as vendas realizadas: R$ " << total_vendas << endl;
    // cout << "Total a ser faturado com vendas futuras: R$ " << vendas_futuras << endl;
}

int modo_vendas()
{
    int abater_estoque = 0;
    if (dinheiro_inserido < lista[operacao_compra].preco)
    {
        do
        {
            cout << "O valor inserido é insulficiente para pagamento, por favor insira o valor correto:";
            cin >> dinheiro_inserido;

        } while (dinheiro_inserido < lista[operacao_compra].preco);

        troco = dinheiro_inserido - lista[operacao_compra].preco;
        abater_estoque = (lista[operacao_compra].quantidade - 1);
        lista[operacao_compra].quantidade = abater_estoque;
        total_vendas = total_vendas + lista[operacao_compra].preco;

        cout << "Ainda restam " << lista[operacao_compra].quantidade << endl;
        return lista[operacao_compra].quantidade;

        if (troco == 0)
        {
            compra_efetuada_sem_troco();
        }
        else
        {
            compra_efetuada_com_troco();
        }
        return lista[operacao_compra].quantidade;
        cout << "RETURN" << lista[operacao_compra].quantidade << endl;
    }

    else
    {
        troco = dinheiro_inserido - lista[operacao_compra].preco;
        abater_estoque = (lista[operacao_compra].quantidade - 1);
        lista[operacao_compra].quantidade = abater_estoque;
        total_vendas = total_vendas + lista[operacao_compra].preco;
        cout << "Ainda restam " << lista[operacao_compra].quantidade << endl;
        return lista[operacao_compra].quantidade;
        cout << "RETURN" << lista[operacao_compra].quantidade << endl;
    }
    if (troco == 0)
    {
        compra_efetuada_sem_troco();
    }
    else
    {
        compra_efetuada_com_troco();
    }

    return lista[operacao_compra].quantidade;
    cout << "RETURN" << lista[operacao_compra].quantidade << endl;
}
