#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <fstream>
using namespace std;

struct Valor
{
	int id;
	double preco;
	double carrinho;
};

void gerar_arquivo_carrinho(double soma, int qtd[], string produto_nome[], Valor pr[])
{
    // pega a pasta do usuário (Windows)
    char* userProfile = getenv("USERPROFILE");
    if (userProfile == NULL) {   // <-- Usa NULL no lugar de nullptr
        cout << "Nao foi possivel encontrar a pasta do usuario. Arquivo nao criado." << endl;
        return;
    }

	cout << "Caminho detectado: " << userProfile << "\\Desktop\\carrinho.txt" << endl;
    string path = string(userProfile) + "\\Desktop\\carrinho.txt";

    ofstream arquivo;
    arquivo.open(path.c_str()); // compatível com qualquer versão

    if (!arquivo.is_open())
    {
        cout << "Erro ao criar o arquivo no Desktop! Path: " << path << endl;
        return;
    }

    arquivo << "====== CARRINHO DO CLIENTE ======\n\n";

    for (int i = 0; i < 4; i++)
    {
        if (qtd[i] > 0)
        {
            double subtotal = qtd[i] * pr[i].preco;

            arquivo << produto_nome[i]
                    << " - " << qtd[i] << " unidades"
                    << " - Subtotal: R$ " << fixed << setprecision(2) << subtotal
                    << "\n";
        }
    }

    arquivo << "\nTOTAL = R$ " << fixed << setprecision(2) << soma << "\n";
    arquivo << "=================================\n";

    arquivo.close();

    cout << "Arquivo criado no Desktop com sucesso!\n";
    Sleep(2000);
}

void android()
{
	cout << "##   ##  #######  ####       ####    #####   ##   ##  #######" << endl;
	cout << "##   ##   ##   #   ##       ##  ##  ##   ##  ### ###   ##   #" << endl;
	cout << "##   ##   ## #     ##      ##       ##   ##  #######   ## #" << endl;
	cout << "## # ##   ####     ##      ##       ##   ##  #######   ####" << endl;
	cout << "#######   ## #     ##   #  ##       ##   ##  ## # ##   ## #" << endl;
	cout << "### ###   ##   #   ##  ##   ##  ##  ##   ##  ##   ##   ##   #" << endl;
	cout << "##   ##  #######  #######    ####    #####   ##   ##  #######" << endl;
	cout << "                                                             " << endl;
	cout << "                         -o          o-         " << endl;
	cout << "                          +hydNNNNdyh+          " << endl;
	cout << "                        +mMMMMMMMMMMMMm+        " << endl;
	cout << "                      ´dMM  NMMMMMMN  MMd´      " << endl;
	cout << "                      hMMMMMMMMMMMMMMMMMMh      " << endl;
	cout << "                  ..  yyyyyyyyyyyyyyyyyyyy  ..  " << endl;
	cout << "                .mMMm`MMMMMMMMMMMMMMMMMMMM`mMMm." << endl;
	cout << "                :mMMm-MMMMMMMMMMMMMMMMMMMM-mMMm:" << endl;
	cout << "                :mMMm-MMMMMMMMMMMMMMMMMMMM-mMMm:" << endl;
	cout << "                :mMMm-MMMMMMMMMMMMMMMMMMMM-mMMm:" << endl;
	cout << "                :mMMm-MMMMMMMMMMMMMMMMMMMM-mMMm:" << endl;
	cout << "                :mMMm-MMMMMMMMMMMMMMMMMMMM-mMMm:" << endl;
	cout << "                 +yy+ MMMMMMMMMMMMMMMMMMMM +yy+ " << endl;
	cout << "                      mMMMMMMMMMMMMMMMMMMm      " << endl;
	cout << "                       /++MMMMh++hMMMM++/       " << endl;
	cout << "                          MMMMo  oMMMM          " << endl;
	cout << "                          MMMMo  oMMMM          " << endl;
	cout << "                          oNMm-  -mMNs          " << endl;
}

void menu()
{
	cout << "            Bem Vindo            " << endl;
	cout << "==================================" << endl;
	cout << "| Voce e cliente ou funcionario? |" << endl;
	cout << "|1 - Cliente                     |" << endl;
	cout << "|2 - Funcionario                 |" << endl;
	cout << "|3 - Grupo                       |" << endl;
	cout << "|4 - logoff                      |" << endl;
	cout << "==================================" << endl;
}

void menufuncionario()
{
	cout << "==============================" << endl;
	cout << "|    O que deseja fazer?     | " << endl;
	cout << "|1 - Adicionar ao estoque    |" << endl;
	cout << "|2 - Checar o estoque        |" << endl;
	cout << "|3 - Atualizacao             |" << endl;
	cout << "|4 - Remover produtos        |" << endl;
	cout << "|5 - voltar                  |" << endl;
	cout << "==============================" << endl;
}
void mostrar_carrinho(double &soma, int qtd_prod, int qtd[], string produto_nome[], Valor pr[])
{
	system("cls");
	cout << "==============================" << endl;
	cout << "        MEU CARRINHO          " << endl;
	cout << "==============================" << endl;

	if (qtd_prod == 0)
	{
		cout << "Carrinho vazio!" << endl;
		cout << "==============================" << endl;
		Sleep(2000);
		return;
	}
	else
	{
		soma = 0.0;
		cout << "                                " << endl;
		if(qtd[0] != 0)
		{
			cout << produto_nome[0] << " - " << qtd[0] << " unidades" << endl;
		}
		if(qtd[1] != 0)
		{
			cout << produto_nome[1] << " - " << qtd[1] << " unidades" << endl;
		}
		if(qtd[2] != 0)
		{
			cout << produto_nome[2] << " - " << qtd[2] << " unidades" << endl;
		}
		if(qtd[3] != 0)
		{
			cout << produto_nome[3] << " - " << qtd[3] << " unidades" << endl;
		}
		for (int i = 0; i < 4; i++)
		{
			if (qtd[i] != 0)
			{
				double subtotal = qtd[i] * pr[i].preco;
				cout << produto_nome[i] << " - " << qtd[i]
					 << " unid. = R$ " << fixed << setprecision(2) << subtotal << endl;
				soma += subtotal;
			}
		}
		cout << "Total = R$ " << fixed << setprecision(2) << soma << endl;
		cout << "==============================" << endl;
	}
	int um = 0;
	cout << "Pressione 1 para voltar ao menu: ";
	cin >> um;
	while(um != 1)
	{
		cout << "Inválido, tente novamente: ";
		cin >> um;
	}
}
int main()
{
	android();
	Valor pr[100];
	pr[0].preco = 3663.00;
	pr[1].preco = 1192.40;
	pr[2].preco = 1287.99;
	pr[3].preco = 859.90;
	int qtd_prod = 0;
	int remover[2] = {0, 0};
	double soma = 0.0;
	int qtd[4] = {0, 0, 0, 0}; // CONTADOR INDIVIDUAL DE CADA PRODUTO
	string produto_nome[] = {"Galaxy A16", "Redmi 14c", "Galaxy S23", "Redmi Note 14"};
	cout << fixed << setprecision(2);
	int identificador, select, produto = 0, estoque[100], adicionar, quantidade;
	double valor;
	for(int i = 0; i < 4; i++)
	{
		estoque[i] = 0;
	}
	string senha = "Admin", entrada, pr1 = "Galaxy A16", pr2 = "Redmi 14c", pr3 = "Galaxy S23", pr4 = "Redmi Note 14";
	while(true)
	{
		menu();
		cout << "Digite o numero: ";
		cin >> identificador;
		bool primeira_compra = true;
		if (identificador == 1)
		{
			do
			{
				system("cls"); // INÍCIO DO MENU FIXO LIMPANDO A ULTIMA TELA
				cout << "                                " << endl;
				cout << "==============================" << endl;
				cout << "                                " << endl; // LINHA QUE MUDA: Título
				if (primeira_compra)
				{
					cout << "    O que deseja comprar?     " << endl;
					primeira_compra = false; // Define que a próxima iteração não será a primeira
				}
				else
				{
					cout << "    Deseja comprar novamente?   " << endl; // FIM DA LINHA QUE MUDA
				}
				cout << "                                " << endl;
				cout << "1-Galaxy A16.......R$" << pr[0].preco << endl;
				cout << "2-Redmi 14c........R$" << pr[1].preco << endl;
				cout << "3-Galaxy S23.......R$" << pr[2].preco << endl;
				cout << "4-Redmi Note 14....R$" << pr[3].preco << endl;
				cout << "5-Mostrar carrinho" << endl;
				cout << "6-finalizar compra" << endl;
				cout << "==============================" << endl; //FIM DO MENU FIXO
				cout << "Digite o numero: ";
				cin >> produto;
				if (produto >= 1 && produto <= 4)
				{
					switch (produto)
					{
					case 1:
						qtd[0]++;
						break;
					case 2:
						qtd[1]++;
						break;
					case 3:
						qtd[2]++;
						break;
					case 4:
						qtd[3]++;
						break;
					}
					qtd_prod++;
					cout << produto_nome[produto - 1] << " adicionado ao carrinho!" << endl;
					Sleep(2000);
					primeira_compra = false;
				}
				else if(produto == 5)
				{
					mostrar_carrinho(soma, qtd_prod, qtd, produto_nome, pr);
					primeira_compra = false;
				}
				else if(produto == 6)
				{
					soma = 0;
					for(int i = 0; i < 4; i++)
					{
						soma += qtd[i] * pr[i].preco;
					}

					gerar_arquivo_carrinho(soma, qtd, produto_nome, pr);
					break;
				}

				else
				{
					cout << "Opção inválida. Digite de 1 a 6." << endl;
					Sleep(2000); // DA 2 SEGUNDOS PRA LIMPAR A TELA
				}
			}
			while(produto != 6);
			cout << "Compra finalizada! Obrigado." << endl;
		}
		else if (identificador == 2)
		{
			while (true)
			{
				cout << "Digite a senha: ";
				cin >> entrada;

				if (entrada != senha)
				{
					cout << "Senha incorreta" << endl;
				}
				else
				{
					break;
				}
			}
			while(true)
			{
				menufuncionario();
				cout << "Digite o numero: ";
				cin >> select;
				if(select == 1)
				{
					while(true)
					{
						cout << "                           " << endl;
						cout << "============ESTOQUE===========" << endl;
						cout << "                         " << endl;
						cout << "O que deseja atualizar?  " << endl;
						cout << "                         " << endl;
						cout << "1-Galaxy A16 = " << estoque[0]  << endl;
						cout << "2-Redmi 14c = " << estoque[1]  << endl;
						cout << "3-Galaxy S23 = " << estoque[2]  << endl;
						cout << "4-Redmi Note 14 = " << estoque[3]  << endl;
						cout << "5-voltar" << endl;
						cout << "==============================" << endl;
						cout << "                           " << endl;
						cout << "Digite o numero: ";
						cin >> adicionar;
						cout << "                           " << endl;
						if(adicionar == 1)
						{
							cout << "Quantos: ";
							cin >> quantidade;
							estoque[0] += quantidade;
						}
						else if(adicionar == 2)
						{
							cout << "Quantos: ";
							cin >> quantidade;
							estoque[1] += quantidade;
						}
						else if(adicionar == 3)
						{
							cout << "Quantos: ";
							cin >> quantidade;
							estoque[2] += quantidade;
						}
						else if(adicionar == 4)
						{
							cout << "Quantos: ";
							cin >> quantidade;
							estoque[3] += quantidade;
						}
						else
						{
							break;
						}
					}
				}
				else if(select == 2)
				{
					cout << "                           " << endl;
					cout << "=========ESTOQUE==========" << endl;
					cout << pr1 << " = " << estoque[0] << endl;
					cout << pr2 << " = " << estoque[1] << endl;
					cout << pr3 << " = " << estoque[2] << endl;
					cout << pr4 << " = " << estoque[3] << endl;
					cout << "==========================" << endl;
					cout << "                           " << endl;
				}
				else if(select == 3)
				{
					while(1)
					{
						cout << "                           " << endl;
						cout << "========NOVAS_OFERTAS======" << endl;
						cout << "1 - Galaxy A16" << " = " << pr[0].preco << endl;
						cout << "2 - Redmi 14c" << " = " << pr[1].preco << endl;
						cout << "3 - Galaxy S23" << " = " << pr[2].preco << endl;
						cout << "4 - Redmi Note 14" << " = " << pr[3].preco << endl;
						cout << "5 - voltar" << endl;
						cout << "===========================" <<  endl;
						cout << "                           " << endl;
						cout << "Digite o id: ";
						cin >> identificador;
						if(identificador == 5)
						{
							break;
						}
						else if(identificador == 1)
						{
							cout << "Digite o novo valor: ";
							cin >> valor;
							pr[0].preco = valor;
						}
						else if(identificador == 2)
						{
							cout << "Digite o novo valor: ";
							cin >> valor;
							pr[1].preco = valor;
						}
						else if(identificador == 3)
						{
							cout << "Digite o novo valor: ";
							cin >> valor;
							pr[2].preco = valor;
						}
						else
						{
							cout << "Digite o novo valor: ";
							cin >> valor;
							pr[3].preco = valor;
						}
					}
				}
				else if(select == 4)
				{
					while(1)
					{
						cout << "======REMOVER=======" << endl;
						for(int i = 0; i < 4; i++)
						{
							if(estoque[i] > 0)
							{
								cout << produto_nome[i] << endl;

							}
						}
						cout << "                           " << endl;
						cout << "1 - Deseja remover" << endl;
						cout << "2 - Voltar" << endl;
						cout << "                           " << endl;
						cout << "====================" << endl;
						cout << "                           " << endl;
						cin >> identificador;
						if (identificador == 1)
						{
							for(int i = 0; i < 4; i++)
							{
								cout << "Qual produto?" << endl;
								cout << "1 - " << pr1 << endl;
								cout << "2 - " << pr2 << endl;
								cout << "3 - " << pr3 << endl;
								cout << "4 - " << pr4 << endl;
								cin >> identificador;
								if(identificador == 1)
								{
									estoque[0] = 0;
								}
								else if(identificador == 2)
								{
									estoque[1] = 0;
								}
								else if(identificador == 3)
								{
									estoque[2] = 0;
								}
								else if(identificador == 4)
								{
									estoque[3] = 0;
								}
								break;
							}
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					break;
				}

			}

		}
		else if (identificador == 3)
		{
			cout << "                           " << endl;
			cout << "Mario Avelino - 2306 - GEC" << endl;
			cout << "Luiz Felipe - 1114 - GEA" << endl;
			cout << "                           " << endl;
		}
		else if(identificador == 4)
		{
			break;
		}
	}
	return 0;
}
