#include <stdio.h>
#include <stdlib.h>

int numDeLancamento(int somaFaces0, int somaFaces1); // Utilizada!
int numFaceSorteada();
int somaDasFaces(int dado1, int dado2, int soma); // Utlizada!
int somaDasFacesDoDado1(int primeiroDado, int somarDado1); // Utilizada!
int somaDasFacesDos2Dados();
int vaiAoJogo(int dinheiroApostado, int numLancamento, int somaFaces0, int somaDado1, int somaFaces0PC, int somaDado1PC, int primeiroDadoPC); // Utilizada!
int quantDeDinheiroDoJogador(); // Utilizada!
int quantDeDinheiroParaUmaRodada(int dinheiroDoJogador); // Utilizada!
int actualizarDinheiro(int dinheiroDoJogdor, int dinheiroApostado, int condicao); // Utilizada!
int verificarDinheiro(int dinheiroDoJogador); // Utilizada!
void mostrarDadosRodada(int dinheiroApostado, int numLancJogador, int somaDasFacesJog, int somaDado1Jog, int numLancPC, int somaDasFacesPC, int somaDado1PC, int condicao); //Utilizada!
void mostrarNaTelaOsDados(int numeroDeJogos, int valorVencidoJog, int valorVencidoPC, int dinheiroDoJogador);
void regrasDoJogo(); // Utilizada!

//Minhas Funçóes
void iniciarJogo();
int dado1();
int dado2();
int lancamentoJogador(int primeiroDado, int somarFaces);
int lancamentoOpcional(int primeiroDado, int somarFaces);
int lancamentoComputador(int primeiroDadoComputador, int somarFaces);
int finalizarJogo();

int somaDasFaces(int dado1, int dado2, int soma)
{
	soma = dado1 + dado2 + soma;
	
	return soma;
}

int numDeLancamento(int somaFaces0, int somaFaces1)
{
	if(somaFaces0 == somaFaces1)
		return 2;
	else
		return 3;
}

int actualizarDinheiro(int dinheiroDoJogdor, int dinheiroApostado, int condicao)
{
	int dinheiroActualizado;
	
	if(condicao == 0)
		 dinheiroActualizado = dinheiroDoJogdor - dinheiroApostado;
	else if(condicao == 1)
			dinheiroActualizado = dinheiroDoJogdor + dinheiroApostado;
		else
			dinheiroActualizado = dinheiroDoJogdor;
	
	return dinheiroActualizado;
}

int quantDeDinheiroDoJogador()
{
	int dinheiro;
	while(1)
	{
		printf("\nDigite a sua quantidade de dinheiro(kz):");
		scanf("%d", &dinheiro);
		if(dinheiro >= 10) return dinheiro;
		printf("Valor muito baixo!!!");
	}
}

void regrasDoJogo()
{
	printf("\nResta 22, e um jogo feito por duas pessoas, so que agora uma e voce e a outra e o  computador.\n");
	printf("O objectivo desse jogo e conseguir acumular o maior numero de pontos mais proximmo de 22, mas que\nnao  ultrapasse esse valor.\n");
	printf("\nCada jogador tem direito, se quiser a fazer tres lancamentos. Em cada lancamento ele lanca dois dados que estao identificados\n");
	printf("primeiro dado e segundo dado, e soma as faces sorteadas.\n\n");
	printf("Regrasdo do jogo: se o valor acumulado for:\n\n");
	printf("- Maior do que 22 pontos (o jogo termina e o jogador perde)");
	printf("\n- Superior a 11 e inferior ou igual a 22 pontos (vai a jogo)");
	printf("\n- inferior a 11 pontos passa o jogo para o outro jogador.");
	printf("\n\nVai ao jogo:\n\n");
	printf("- Ganha quem tiver maior pontuacao;");
	printf("\n- Se a pontuacao for igual, ganha o jogador que fizer o menor numero de lancamentos;");
	printf("\n- Se o numero de lancamento for igual, ganha o jogador que tiver o maior numero de pontos no primeiro dado;");
	printf("\n- Se o numero de pontos no primeiro dado for igual o jogo esta empatado.\n\n");
}

void iniciarJogo()
{
	printf("****************************** RESTA 22 ******************************\n");
	int escolha;
	int terminar = 0;
	
	while(terminar == 0)
	{
		printf("Clique:\n1- Para comecar o jogo					2- Para regras do jogo\n");
		scanf("%d", &escolha);
		if(escolha == 1)
			terminar = 1;
		else if(escolha == 2)
			{
				regrasDoJogo();
				terminar = 1;
			}
			else printf("\nErro: Chave inalida!!!");
	}
}

int quantDeDinheiroParaUmaRodada(int dinheiroDoJogador)
{
	int dinheiroApostado;
	while(1)
	{
		printf("\nDigite a sua quantidade de dinheiro para esta rodada(kz):");
		scanf("%d", &dinheiroApostado);
		
		if(dinheiroApostado <= dinheiroDoJogador)
			if(dinheiroApostado <= 1000)
				if(dinheiroApostado >= 5)
					return dinheiroApostado;
				else
					printf("\nValor muito baixo!!!");
			else
				printf("\nNao pode apostar este valor!!!");
		else
			printf("\nSaldo insuficiente para apostar!!!");
	}
}

int dado1()
{
	int face;
	
	while(1)
	{
		face = (rand() % 100)/10;
		if(face > 0)
			if(face < 7)
				return face;
	}
}
	
int dado2()
{
	int face;
	
	while(1)
	{
		face = (rand() % 100)/15;
		if(face > 0)
			if(face < 7)
				return face;
	}
}	
	
int lancamentoJogador(int primeiroDado, int somarFaces)
{
	int segundoDado;
	
	int terminar = 0;
	int clique;
	int total;
	
	while(terminar == 0)
	{
		printf("\nClique no 1, para efectuar lancamento: ");
		scanf("%d", &clique);
		if(clique == 1)
		{
			segundoDado = dado2();
	
			printf("\nPrimeiro Dado: %d", primeiroDado);
			printf("\nSegundoo Dado: %d", segundoDado);
			
			somarFaces = somaDasFaces(primeiroDado, segundoDado, somarFaces);
			
			total = primeiroDado + segundoDado;
			printf("\nTotal: %d\n", total);
			
			terminar = 1;	
		}
	}
	return somarFaces;
}

int lancamentoOpcional(int primeiroDado, int somarFaces)
{
	int segundoDado;
	int terminar = 0;
	int clique;
	int total;
	
	while(terminar == 0)
	{
		printf("\nClique:\n1- Para efectuar lancamento					2- Para passar a jogada ao computador\n");
		scanf("%d", &clique);
		if(clique == 1)
		{
			segundoDado = dado2();
	
			printf("\nPrimeiro Dado: %d", primeiroDado);
			printf("\nSegundoo Dado: %d\n", segundoDado);
			
			somarFaces = somaDasFaces(primeiroDado, segundoDado, somarFaces);
			
			total = primeiroDado + segundoDado;
			printf("\nTotal: %d\n", total);
			
			terminar = 1;	
		}
		else if(clique == 2)
				terminar = 1;
	}
	
	return somarFaces;
}

int lancamentoComputador(int primeiroDadoComputador, int somarFaces)
{
	int segundoDado, total;
	
	segundoDado = dado2();
	
	printf("\nPrimeiro Dado: %d", primeiroDadoComputador);
	printf("\nSegundoo Dado: %d\n", segundoDado);
	
	somarFaces = somaDasFaces(primeiroDadoComputador, segundoDado, somarFaces);
	
	total = primeiroDadoComputador + segundoDado;
	printf("\nTotal: %d\n", total);
	
	return somarFaces;
}

int somaDasFacesDoDado1(int primeiroDado, int somarDado1)
{
	somarDado1 = somarDado1 + primeiroDado;
	
	return somarDado1;
}

void mostrarDadosRodada(int dinheiroApostado, int numLancJogador, int somaDasFacesJog, int somaDado1Jog, int numLancPC, int somaDasFacesPC, int somaDado1PC, int condicao)
{
	printf("\n****************************** Dados da Rodada ******************************\n");
	
	printf("\nDados do jogador nesta rodada:");
	printf("\nO valor apostado: %d", dinheiroApostado);
	printf("\nO numero de lancamento dos dados: %d", numLancJogador);
	printf("\nO valor acumulado dos dados: %d", somaDasFacesJog);
	printf("\nO valor acumulado do primeiro dado: %d", somaDado1Jog);
	
	printf("\n\nDados do computador nesta rodada:");
	printf("\nO valor apostado: %d", dinheiroApostado);
	printf("\nO numero de lancamento dos dados: %d", numLancPC);
	printf("\nO valor acumulado dos dados: %d", somaDasFacesPC);
	printf("\nO valor acumulado do primeiro dado: %d", somaDado1PC);
	
	if(condicao == 0)
		printf("\n			Vencedor: Computador					Valor Ganho: %d\n", dinheiroApostado);
	else if(condicao == 1)
		printf("\n			Vencedor: Jogador					Valor Ganho: %d\n", dinheiroApostado);
		else
			printf("\n			A rodada terminou empatada					Valor Ganho: %d\n", dinheiroApostado);	
}

int vaiAoJogo(int dinheiroApostado, int numLancamento, int somaFaces0, int somaDado1, int somaFaces0PC, int somaDado1PC, int primeiroDadoPC)
{
	printf("\nRodada do Computador:\n");
				
				printf("\nPrimeira jogada do Compuador:");
				primeiroDadoPC = dado1();
				somaFaces0PC = lancamentoComputador(primeiroDadoPC, somaFaces0PC);
				somaDado1PC = somaDasFacesDoDado1(primeiroDadoPC, somaDado1PC);
				
				printf("\nSegunda jogada do Compuador:");
				primeiroDadoPC = dado1();
				somaFaces0PC = lancamentoComputador(primeiroDadoPC, somaFaces0PC);
				somaDado1PC = somaDasFacesDoDado1(primeiroDadoPC, somaDado1PC);
				
				printf("\nTerceira jogada do Compuador:");
				primeiroDadoPC = dado1();
				somaFaces0PC = lancamentoComputador(primeiroDadoPC, somaFaces0PC);
				somaDado1PC = somaDasFacesDoDado1(primeiroDadoPC, somaDado1PC);
				
				if(somaFaces0PC > 22)
				{
					mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 1);
					return 1;
				}
				else if((22 - somaFaces0) < (22 - somaFaces0PC))
					{   
						mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 1);
						return 1;
					}   
					else if((22 - somaFaces0) == (22 - somaFaces0PC))
							if(numLancamento == 3)
								if(somaDado1 == somaDado1PC)	
								{
									mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, -1);
									return -1;
								}
								else if(somaDado1 > somaDado1PC)
									{
										mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 1);
										return 1;
									}
									else
									{
										mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 0);
										return 0;
									}
							else if(numLancamento < 3)
								{
									mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 1);
									return 1;
								}
								else
								{
									mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 0);
									return 0;
								}
						else
						{
							mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 3, somaFaces0PC, somaDado1PC, 0);
							return 0;
						}
}

int verificarDinheiro(int dinheiroDoJogador)
{
	if(dinheiroDoJogador < 5)
	{
		printf("\nLamentamos, mas ja nao tem dinheiro suficiente para fazer qualquer aposta!!!");
		return 1;
	}
	else
		return 0;
}

int finalizarJogo()
{
	int terminar;
	while(1)
	{
		printf("\nDeseja continuar a jogar?\n0- Continuar					1- Sair\n");
		scanf("%d", &terminar);
		if(terminar == 0) return 0;
		else if(terminar == 1) return 1;
			else
				printf("\nOpcao invalida!!!");
	}
}

void mostrarNaTelaOsDados(int numeroDeJogos, int valorVencidoJog, int valorVencidoPC, int dinheiroDoJogador)
{
	printf("\n****************************** Estatisticas dos Jogos ******************************\n");
	printf("Numero de jogos: %d\n", numeroDeJogos);
	printf("Quanto venceu o Jogador: %d\n", valorVencidoJog);
	printf("Quanto venceu o Computador: %d\n", valorVencidoPC);
	printf("\nO seu saldo e de: %dkz\n", dinheiroDoJogador);
}

int main()
{
	srand(time(NULL));
	
	int terminar = 0;
	int contadorDeJogo = 0;
	int vencedor;
	
	// Variáveis do Jogador
	int dinheiroDoJogador, dinheiroApostado;
	int primeiroDado, somaFaces0, somaFaces1;
	int numLancamento, somaDado1;
	int dinheiroVencido = 0;
	
	// Variáveis do computador
	int dinheiroDoComputador = 0;
	int primeiroDadoPC, somaFaces0PC;
	int somaDado1PC;
	
	somaFaces0 = 0;
	somaDado1 = 0;
	
	somaFaces0PC = 0;
	somaDado1PC = 0;
	
	iniciarJogo();
	
	printf("\nVamos comecar o jogo!!!");
	
	dinheiroDoJogador = quantDeDinheiroDoJogador();
	
	while(terminar == 0)
	{
		vencedor = -1;
		
		dinheiroApostado = quantDeDinheiroParaUmaRodada(dinheiroDoJogador);
	
		printf("\nRodada do Jogador:\n");
		primeiroDado = dado1();
		somaFaces0 = lancamentoJogador(primeiroDado, somaFaces0);
		somaDado1 = somaDasFacesDoDado1(primeiroDado, somaDado1);
		
		primeiroDado = dado1();
		somaFaces0 = lancamentoJogador(primeiroDado, somaFaces0);
		somaDado1 = somaDasFacesDoDado1(primeiroDado, somaDado1);
		
		somaFaces1 = somaFaces0;
		
		if(somaFaces0 >= 11)
			if(somaFaces0 <= 22)
			{
				primeiroDado = dado1();
				somaFaces0 = lancamentoOpcional(primeiroDado, somaFaces0);
		
				numLancamento = numDeLancamento(somaFaces0, somaFaces1);
		
				if(numLancamento == 3)
					somaDado1 = somaDasFacesDoDado1(primeiroDado, somaDado1);
						
				if(somaFaces0 > 22)
				{
					mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 0, 0, 0, 0);
					dinheiroDoJogador = actualizarDinheiro(dinheiroDoJogador, dinheiroApostado, 0);
					dinheiroDoComputador += dinheiroApostado;
				}
				else
					vencedor = vaiAoJogo(dinheiroApostado, numLancamento, somaFaces0, somaDado1, somaFaces0PC, somaDado1PC, primeiroDadoPC);
			}
			else
			{
				mostrarDadosRodada(dinheiroApostado, numLancamento, somaFaces0, somaDado1, 0, 0, 0, 0);
				dinheiroDoJogador = actualizarDinheiro(dinheiroDoJogador, dinheiroApostado, 0);
				dinheiroDoComputador += dinheiroApostado;
			}
		else
			vencedor = vaiAoJogo(dinheiroApostado, 2, somaFaces0, somaDado1, somaFaces0PC, somaDado1PC, primeiroDadoPC);
				
		if(vencedor == 0)
		{
			dinheiroDoComputador += dinheiroApostado;
			dinheiroDoJogador -= dinheiroApostado;
		}	
		else if(vencedor == 1)
			{
				dinheiroVencido += dinheiroApostado;
				dinheiroDoJogador += dinheiroApostado;
			}
			
		somaFaces0 = 0;
		somaDado1 = 0;
	
		somaFaces0PC = 0;
		somaDado1PC = 0;
		
		contadorDeJogo++;
		
		terminar = finalizarJogo();
		
		if(terminar == 0)
			terminar = verificarDinheiro(dinheiroDoJogador);
			
	}
	
	mostrarNaTelaOsDados(contadorDeJogo, dinheiroVencido, dinheiroDoComputador, dinheiroDoJogador);
	
	system("pause");
	return 0;
}