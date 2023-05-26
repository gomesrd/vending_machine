#include <iostream>

using namespace std;

int calcule_valor_transacao();
int verifica_disponibilidade_produto();
int lista_invetario();
int lista_faturamento();
int verifica_administrador();

int main()
{
    int operacao = 0, quantia_inserida = 0;
    int senha, opcoes; //Variaveis adm

    do
    {
        cout << "-------Bem vindo a máquina de vendas automáticas FATEC-RP-----------" << endl;
        cout << "Digite o número do produto que deseja comprar:" << endl;
        cout << "1 - Água ---------- R$ 3,50" << endl;
        cout << "2 - Refrigerante ---------- R$ 4,00" << endl;
        cout << "3 - Chocolate ---------- R$ 3,00" << endl;
        cout << "4 - Bolacha ---------- R$ 3,25" << endl;
        cout << "5 - Salgadinho ---------- R$ 4,50" << endl;
        cout << "99 - ADMINISTRADOR" << endl;
        cout << "9 - SAIR" << endl;
        cin >> operacao;

        if (operacao = 99)
        {  
            cout << "Senha: ";  //Senha para acesssar o modo administrador: 1234
            cin >> senha;
            
                if (senha == 1234)
                {
                    cout << "1 - LISTAR INVETÁRIO" << endl;
                    cout << "2 - REPOSIÇÃO DE PRODUTOS" << endl;
                    cout << "3 - FATURAMENTO" << endl;
                    cin >> opcoes;

                        switch (opcoes)
                        {
                            case: 1                              

                            case: 2

                            case: 3
                        }
                }
                else
                {
                    //Voltar para o inicio do programa
                }
        }

        else
        {
            verifica_disponibilidade_produto();

            cout << "Informe a quantia em dinheiro inserida na máquina:" << endl;

            cin >> quantia_inserida;

            calcule_valor_transacao();

            cout << "O seu troco é de R$ " << endl;
        }
    } while (operacao != 9);

    system("read");
    return 0;
}

// FUNÇÃO RESPONSÁVEL POR VERIFICAR SE O PRODUTO SELECIONADO ESTÁ DISPONÍVEL NO ESTOQUE
int verifica_administrador();

// FUNÇÃO RESPONSÁVEL POR VERIFICAR SE O PRODUTO SELECIONADO ESTÁ DISPONÍVEL NO ESTOQUE
int verifica_disponibilidade_produto(int produto)
{
    // buscar
}

// FUNÇÃO RESPONSÁVEL POR RECEBER O VALOR INSERIDO NA MÁQUINA, VERIFICAR O VALOR DO PRODUTO COMPRADO E CALCULAR O TROCO
int calcule_valor_transacao(int valor_produto, int quantia_inserida, int troco)
{
    troco = quantia_inserida - valor_produto;

    return troco;
}

// FUNÇÃO RESPONSÁVEL POR REPOR OS PRODUTOS QUE ESTÃO EM FALTA NO ESTOQUE
int reposicao_produto()
{
}

// FUNÇÃO RESPONSÁVEL POR LISTAR O INVETÁRIO DE PRODUTOS
int lista_invetario()
{
}

// FUNÇÃO RESPONSÁVEL POR LISTAR O FATURAMENTO DA MÁQUINA DE VENDAS
int lista_faturamento()
{
}
