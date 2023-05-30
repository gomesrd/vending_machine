#include <iostream>

using namespace std;

bool verifica_estoque = false;
int operacao_compra = 0, operacao_adm = 0, troco = 0, qtdade_agua = 10, nova_qtdade = 0;
float preco_agua = 3, dinheiro_inserido = 0, total_vendas = 0;
string produto;

void modo_administrador();

int main()
{
    do
    {
        cout << "\n\n\n-------Bem vindo a máquina de vendas automáticas FATEC-RP-----------\n\n";
        cout << "1 - Água ------------------ R$ 3,00" << endl;
        cout << "2 - Refrigerante ---------- R$ 4,00" << endl;
        cout << "3 - Chocolate ------------- R$ 3,00" << endl;
        cout << "4 - Bolacha --------------- R$ 3,25" << endl;
        cout << "5 - Salgadinho ------------ R$ 4,50" << endl;
        cout << "8 - ADMINISTRADOR" << endl;
        cout << "9 - SAIR" << endl;
        cout << "\n\nDigite o código do produto que deseja comprar: ";
        cin >> operacao_compra;

        switch (operacao_compra)
        {

        case 1:
            verifica_estoque = qtdade_agua >= 1;
            if (verifica_estoque == true)
            {
                cout << "Insira o dinheiro na máquina: ";
                cin >> dinheiro_inserido;
            }
            else
            {
                cout << "Não há estoque do produto selecionado, selecione outro produto.";
                break;
            }
            if (dinheiro_inserido < preco_agua)
            {
                do
                {
                    cout << "O valor inserido é insulficiente para pagamento, por favor insira o valor correto:";
                    cin >> dinheiro_inserido;

                } while (dinheiro_inserido < preco_agua);

                troco = dinheiro_inserido - preco_agua;
                qtdade_agua = qtdade_agua - 1;
                total_vendas = total_vendas + preco_agua;

                cout << "Ainda restam " << qtdade_agua << endl;

                if (troco == 0)
                {
                    cout << "\n\n****Compra realizada com suceso! \n Retire o seu produto!****";
                }
                else
                {

                    cout << "\n\n****O seu troco é de R$ " << troco << "****" << endl;
                    cout << "\n\n****Compra realizada com suceso! \n Retire o seu produto!****";
                }
            }

            else
            {
                troco = dinheiro_inserido - preco_agua;
                qtdade_agua = qtdade_agua - 1;
                cout << "Ainda restam " << qtdade_agua << endl;

                if (troco == 0)
                {
                    cout << "****\n\nCompra realizada com suceso! \nRetire o seu produto!****";
                }
                else
                {

                    cout << "****\n\nO seu troco é de R$ " << troco << "****" << endl;
                    cout << "****\n\nCompra realizada com suceso! \nRetire o seu produto!****";
                }
            }
            break;

        case 8:
            modo_administrador();
            break;

        case 9:
            cout << "Obrigado pela visita, até mais!" << endl;
            break;

        default:
            cout << "Opção inválida, selecione novamente!" << endl;
        }

    } while (operacao_compra != 9);
    system("read");
    return 0;
}

void modo_administrador()
{
    float vendas_futuras;
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
            cout << "\n\n\n-------REPOSIÇÃO DE ESTOQUE-------\n\n";
            cout << "Digite o nome do produto que deseja repor: ";
            cin >> produto;
            cout << "Digite a quantidade que será reposta: ";
            cin >> nova_qtdade;
            qtdade_agua = qtdade_agua + nova_qtdade;
            cout << "\n\nPERAÇÃO EFETUADA COM SUCESSO!\n\n";
            cout << "Foram adicionadas " << nova_qtdade << " unidades no estoque do produto " << produto << "." << endl;
            cout << "O novo saldo é de  " << qtdade_agua << " unidades.";
            break;

        case 2:
            cout << "\n\n\n-------INVENTÁRIO-------\n\n";
            cout << "O estoque atual possui os seguintes produtos e quantidades: " << endl;
            cout << "01. Agua: " << qtdade_agua << " unidades.";
            break;

        case 3:
            cout << "\n\n\n-------FATURAMENTO-------\n\n";
            vendas_futuras = qtdade_agua * preco_agua;
            cout << "Total faturado com as vendas realizadas: R$ " << total_vendas << endl;
            cout << "Total a ser faturado com vendas futuras: R$ " << vendas_futuras << endl;
            break;

        case 9:
            cout << "Retornando ao modo de usuário, até mais!" << endl;
            break;

        default:
            cout << "Opção inválida, selecione novamente!";
        }

    } while (operacao_adm != 9);
}
