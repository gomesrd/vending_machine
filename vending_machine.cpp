#include <iostream>

using namespace std;

bool verifica_estoque = false;
int operacao, troco = 0, qtdade_agua = 2;
float preco_agua = 3, dinheiro_inserido = 0;

void modo_vendas()
{
}

void modo_administrador()
{
    cout << "Bem vindo ao modo administrador!" << endl;
    cout << "1 - Repor o estoque" << endl;
    cout << "2 - Realizar Inventário" << endl;
    cout << "3 - Faturamento da máquina" << endl;
}

int main()
{
    do
    {
        cout << "-------Bem vindo a máquina de vendas automáticas FATEC-RP-----------\n";
        cout << "1 - Água ------------------ R$ 3,00" << endl;
        cout << "2 - Refrigerante ---------- R$ 4,00" << endl;
        cout << "3 - Chocolate ------------- R$ 3,00" << endl;
        cout << "4 - Bolacha --------------- R$ 3,25" << endl;
        cout << "5 - Salgadinho ------------ R$ 4,50" << endl;
        cout << "8 - ADMINISTRADOR" << endl;
        cout << "9 - SAIR" << endl;
        cout << "Digite o código do produto que deseja comprar: ";
        cin >> operacao;

        switch (operacao)
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
                cout << "Não há estoque do produto selecionado, selecione outro produto.\n\n\n";
                break;
            }
            if (dinheiro_inserido < preco_agua)
            {
                do
                {
                    cout << "O valor inserido é insulficiente para pagamento, por favorinsira o valor correto:";
                    cin >> dinheiro_inserido;

                } while (dinheiro_inserido < preco_agua);

                troco = dinheiro_inserido - preco_agua;
                qtdade_agua = qtdade_agua - 1;
                cout << "Ainda restam " << qtdade_agua << endl;

                if (troco == 0)
                {
                    cout << "****Retire o seu produto!****\n\n\n";
                }
                else
                {

                    cout << "****O seu troco é de R$ " << troco << "****" << endl;
                    cout << "****Compra realizada com suceso! Retire o seu produto!****\n\n\n";
                }
            }

            else
            {
                troco = dinheiro_inserido - preco_agua;
                qtdade_agua = qtdade_agua - 1;
                cout << "Ainda restam " << qtdade_agua << endl;

                if (troco == 0)
                {
                    cout << "****Retire o seu produto!****\n\n\n";
                }
                else
                {

                    cout << "****O seu troco é de R$ " << troco << "****" << endl;
                    cout << "****Compra realizada com suceso! Retire o seu produto!****\n\n\n";
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
            cout << "Opção inválida, selecione novamente!\n\n\n"
                 << endl;
        }

    } while (operacao != 9);
    system("read");
    return 0;
}