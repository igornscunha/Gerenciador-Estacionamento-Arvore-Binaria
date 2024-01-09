#include <stdio.h>
#include <stdlib.h>

////////////////////
// Arquivo necessario
#include "arvoreBinaria.h"

int numeroDePesquisa = 0;



estacionamentoBinario* criarEInserirVeiculos(estacionamento* listaVeiculo, estacionamentoBinario *arvoreVeiculo, veiculo* c){
		
	inserirVeiculo(listaVeiculo, c);
	arvoreVeiculo = inserirVeiculoNaArvore(arvoreVeiculo, c);
	
	return arvoreVeiculo;
}

void buscaVeiculo(int placa, estacionamento* lista, estacionamentoBinario** arvore){
		
	numeroDePesquisa++;
	
	retirarVeiculo(placa, lista);
	buscaRemoveVeiculo(&(*arvore), placa);
	
	if(idVeiculo <=(lista->tamanhoEstacionamento/2)) printf("Veiculo placa: %d saiu pelo portão 1\n\n", placa);
	else printf("Veiculo placa: %d saiu pelo portão 2\n\n", placa);
}

void melhorBusca(){
	float mediaPilha = numeroDeComparacaoPilha / numeroDePesquisa;
	float mediaBinaria = numeroDeComparacaoBinaria / numeroDePesquisa;
	
	printf("Resultado:\n Pilha: %d --- Média: %f\n Árvore Binária: %d --- Média: %f\n\n", numeroDeComparacaoPilha, mediaPilha, numeroDeComparacaoBinaria, mediaBinaria);
}

int main (){

	
	estacionamento *lEstacionamento = criarListaEstacionamento();
	estacionamentoBinario* aEstacionamento = NULL;
	lEstacionamento->tamanhoEstacionamento = 6;
	
	veiculo *c1 = criarVeiculo(321);
	veiculo *c2 = criarVeiculo(123);
	veiculo *c3 = criarVeiculo(404);
	veiculo *c4 = criarVeiculo(501);
	veiculo *c5 = criarVeiculo(005);
	veiculo *c6 = criarVeiculo(999);
	
	
	/*Caso 1*/
	/*
	aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c1);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c2);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c3);
	aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c4);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c5);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c6);
    
    printf("\n[VEICULOS]\n");
	exibirArvoreEmOrdem(aEstacionamento);
	printf("\n\n");
	buscaVeiculo(999, lEstacionamento, &aEstacionamento);
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    buscaVeiculo(123, lEstacionamento, &aEstacionamento);
	printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    */
	/*Caso 2*/
	
	aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c1);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c2);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c3);
    
    printf("\n[VEICULOS]\n");
	exibirArvoreEmOrdem(aEstacionamento);
	printf("\n\n");
	buscaVeiculo(404, lEstacionamento, &aEstacionamento);
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c4);
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c5);
    printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    
	buscaVeiculo(005, lEstacionamento, &aEstacionamento);
	printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    
    aEstacionamento = criarEInserirVeiculos(lEstacionamento, aEstacionamento, c6);
	printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
	
	buscaVeiculo(999, lEstacionamento, &aEstacionamento);
	printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    
    buscaVeiculo(501, lEstacionamento, &aEstacionamento);
	printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
    
	buscaVeiculo(321, lEstacionamento, &aEstacionamento);
	printf("\n[VEICULOS]\n");
    exibirArvoreEmOrdem(aEstacionamento);
    printf("\n\n");
	
	
    
    
    melhorBusca();

	printf("Sou euuuuu!\n");
	
	return 0;
}
