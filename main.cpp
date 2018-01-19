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
void ordenacaoDadosCadastrados (game dadosGame[]; int limite)
{
	game aux;
	for (int x = 0; x < limite; x++)
	{
		for (int y = x + 1; y < limite; y++)
		{
			if (dadosGame[x].anoLancamento > dadosGame[y].anoLancamento)
			{
				aux.nome = dadosGame[x].nome;
				aux.anoLancamento = dadosGame[x].anoLancamento;
				aux.plataforma = dadosGame[x].plataforma;
				aux.descricao = dadosGame[x].descricao;
				dadosGame[x].nome = dadosGame[y].nome;
				dadosGame[x].anoLancamento = dadosGame[y].anoLancamento;
				dadosGame[x].plataforma = dadosGame[y].plataforma;
				dadosGame[x].descricao = dadosGame[y].descricao;
				dadosGame[y].nome = aux.nome;
				dadosGame[y].anoLancamento = aux.anoLancamento;
				dadosGame[y].plataforma = aux.plataforma;
				dadosGame[y].descricao = aux.descricao;
			}
		}
	}
}

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
					ordenacaoDadosCadastrados(dadosGame, limite);
					break;
				case 0:
					return 0;
				default:
					cout<<"Teste para opção não 
cadastrada"<<endl;
			}
	}
}
