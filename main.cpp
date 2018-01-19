// Bibliotecas
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

// Registro para o game
struct game
{
	string nome;
	int anoLancamento;
	string plataforma;
	string descricao;
};

// Subprogramas secundários
void insercaoDados () {}
void atualizacaoDados () {}
void buscaDados () {}
void listagemDadosCadastrados () {}

// Subprograma principal
int main ()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=-1, limite = 250000;
	game dadosGame[limite];
	while (opcao!=0)
	{
		cout<<"Entre com a operação desejada"<<endl
			<<"1 para inserção de dados<<endl
			<<"2 para atualização de dados""<<endl
			<<"3 para busca de dados"<<endl
			<<"4 para listagem dos dados cadastrados em ordem
crescente<<endl
			<<"0 para sair<<endl;
			cin>>opcao;
			switch (opcao)
			{
				case 1:
					insercaoDados();
					break;
				case 2:
					atualizacaoDados();
					break;
				case 3:
					buscaDados();
					break;
				case 4:
					listagemDadosCadastrados();
					break;
				case 0:
					return 0;
				default:
					cout<<"Teste para opção não 
cadastrada"<<endl;
			}
	}
}
