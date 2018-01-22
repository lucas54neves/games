
// Bibliotecas
#include <iostream>
#include <string>
#include <fstream>   
#include <locale.h>
#include <stdlib.h>

using namespace std;

// Registro para o game
struct game
{
	char nome[100];
	int anoLancamento;
	char plataforma[100];
	char descricao[700];
};

// Subprogramas secundários
// Subprograma para ler o arquivo de dados
game* lerArquivo(int* tamanho) {
	ifstream entrada;
	entrada.open("saida.dat", ios::binary);
	game* bloco;
  	if (entrada) {
		entrada.seekg (0, entrada.end);
		int tam = entrada.tellg();
		entrada.seekg (0, entrada.beg);
		bloco = new game [tam/sizeof(game)];		
		int qtd = tam/sizeof(game);
		for (int i = 0; i < qtd; i++) {
			entrada.read (reinterpret_cast<char *> (&bloco[i]), sizeof(game)); 
		}   
		entrada.close();
		*tamanho = qtd;
	} else {
		cout << "Erro na abertura do arquivo.";
	}
	return bloco;
}
// Subprograma para a impressão à tela de um vetor de game 
void print (game dadosGame[], int quant) {
	cout << "_______________________________________________" << endl;
	for (int i = 0; i < quant; i++) {
		cout << "Nome: " << dadosGame[i].nome << endl;
		cout << "Ano de Lançamento: " << dadosGame[i].anoLancamento << endl;
		cout << "Plataforma: " << dadosGame[i].plataforma << endl;
		cout << "Descricao: " << dadosGame[i].descricao << endl;
		cout << "_______________________________________________" << endl;
	}
}
// Subprograma para inserir os dados de um jogo (somente 1 por chamada)
void insercaoDados () {
	game* jogo = new game [1];
	
	cout << "Nome do jogo: ";
	cin.ignore();
	cin.getline(jogo[0].nome, 100);
	cout << "Ano de Lançamento: ";
	cin >> jogo[0].anoLancamento;
	cin.ignore();
	cout << "Plataforma: ";
	cin.getline(jogo[0].plataforma, 100);
	cout << "Descrição: ";
	cin.getline(jogo[0].descricao, 700);

	ofstream saida("saida.dat", ios::binary|ios::app);
	saida.write ((const char *) (&jogo[0]), sizeof(game));
	saida.close();
	
	cout << "Inserido com sucesso!" << endl;
}
// Subprograma para a atualização dos dados cadastrados
void atualizacaoDados () {}
// Subprograma para uma busca de um ou mais jogos dado um certo ano requisitado pelo usuário
void buscaDados (game dadosGame[], int limite) {
	int anoBuscado, j = 0;
	game aux[limite];
	cout << "Digite o ano que deseja buscar: ";
	cin >> anoBuscado;
	for (int i = 0; i < limite; i++) {
		if (dadosGame[i].anoLancamento == anoBuscado) {
			aux[j++] = dadosGame[i];
		}
	}
	print(aux, j);
}
// Subprograma para a ordenação dos dados cadastrados
void ordenacaoDadosCadastrados (game dadosGame[], int limite)
{
	game aux;
	for (int i = 0; i < limite - 1; i++)
	{
		for (int j = 0; j < limite - 1; j++)
		{
			if (dadosGame[j].anoLancamento > dadosGame[j+1].anoLancamento)
			{
				aux = dadosGame[j];
				dadosGame[j] = dadosGame[j+1];
				dadosGame[j+1] = aux;
			}
		}
	}
}

// Subprograma principal
int main () {
	setlocale(LC_ALL, "Portuguese");
	int opcao=-1;
	game *dadosGame;
	int tam;
	
	while (opcao!=0) {
		system("clear");
		cout << "Entre com a operação desejada" << endl
			 << "1 para inserção de dados" << endl
			 << "2 para atualização de dados" << endl
			 << "3 para busca de dados" << endl
			 << "4 para listagem dos dados cadastrados em ordem crescente" << endl
			 << "0 para sair" << endl;
		cin >> opcao;
		switch (opcao) {
			case 1:
				insercaoDados();
				break;
			case 2:
				atualizacaoDados();
				break;
			case 3:
				dadosGame = lerArquivo(&tam);
				buscaDados(dadosGame, tam);
				break;
			case 4:
				dadosGame = lerArquivo(&tam);
				ordenacaoDadosCadastrados(dadosGame, tam);
				print(dadosGame, tam);
				break;
			case 5:
				dadosGame = lerArquivo(&tam);
				print(dadosGame, tam);
				break;
			case 0:
				return 0;
			default:
				cout << "Teste para opção não cadastrada" << endl;
		}
		cout << "Pressione qualquer botão para continuar." << endl;
		getchar();
	}
}
