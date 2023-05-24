#include <iostream>

using namespace std;

int calcule_valor_transacao();
int verifica_disponibilidade_produto();

int main()
{
    int operacao = 0, quantia_inserida = 0;

    do
    {
        cout << "-------Bem vindo a máquina de vendas automáticas FATEC-RP-----------" << endl;
        cout << "Digite o número do produto que deseja comprar:" << endl;
        cout << "1 - Água ---------- R$ 3,50" << endl;
        cout << "2 - Refrigerante ---------- R$ 4,00" << endl;
        cout << "3 - Chocolate ---------- R$ 3,00" << endl;
        cout << "4 - Bolacha ---------- R$ 3,25" << endl;
        cout << "5 - Salgadinho ---------- R$ 4,50" << endl;
        cout << "9 - SAIR" << endl;
        cin >> operacao;

        cout << "Informe a quantia em dinheiro inserida na máquina:" << endl;
        cin >> quantia_inserida;

        calculo_transacao()

    } while (operacao != 9);

    system("read");
    return 0;
}

int calcule_valor_transacao(int valor_produto, int quantia_inserida, int troco)
{
    troco = quantia_inserida - valor_produto;

    return troco;
}

int verifica_disponibilidade_produto(int produto)
{
}
