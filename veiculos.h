#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int numeroDeComparacaoPilha = 0;

////////////////////////////// Estrutura Pilha
typedef struct Veiculo{
	
	int id;
	int placa;
	struct Veiculo *prox;
	
}veiculo;

typedef struct Estacionamento{
	
	int tamanhoEstacionamento;
	int quantCarros;
	veiculo *topoVeiculo;

}estacionamento;

estacionamento* criarListaEstacionamento(){
	estacionamento *lista = (estacionamento*) malloc(sizeof(estacionamento));
	lista->quantCarros = 0;
	lista->topoVeiculo = NULL;
	lista->tamanhoEstacionamento = 0;
	/*printf("Para iniciar, informe quantas vagas possui no estacionamento:\n");
	scanf("%d", &lista->tamanhoEstacionamento);
	*/
	return lista;
}


///////////////
///////////////////////////////////// Cria veiculo
veiculo* criarVeiculo(int placa){
	
	veiculo *c = (veiculo*) malloc(sizeof(veiculo));
	c->id = 0;
	c->placa = placa;
	c->prox = NULL;
	
	return c;
}



void inserirVeiculo(estacionamento *lista, veiculo *c){
	
	veiculo *aux;
	
	if(lista->quantCarros < lista->tamanhoEstacionamento){
		
		if(lista->quantCarros == 0){
			
			lista->topoVeiculo = c;		
			lista->topoVeiculo->prox = NULL;
			
		}else{
			aux = lista->topoVeiculo;
			c->prox = aux;
			lista->topoVeiculo = c;
			
		}
		
		lista->quantCarros++;
		lista->topoVeiculo->id = lista->quantCarros;
		
		//printf("\nveiculo inserido\nQuantidade de veiculos %d\n", lista->quantCarros);
	
	}else{
		printf("\nLotacao no maximo, impossivel adicionar\n\n");
	}
	
}

/*

void criarEInserirVeiculo(estacionamento* listaVeiculo){
	int placa = 0;
	veiculo *aux = NULL;
	
	printf("Informe o numero da placa do veiculo:\n");
	scanf("%d", &placa);
	
	aux = criarVeiculo(placa);
	inserirVeiculo(listaVeiculo, aux);
	
	
}
*/


// busca e retira o veiculo
void retirarVeiculo(int placa, estacionamento *pilhaEstacionamento){
	
	veiculo* proximo = NULL;
	veiculo* atual = NULL;
	estacionamento* rua = criarListaEstacionamento();
	rua->tamanhoEstacionamento = pilhaEstacionamento->tamanhoEstacionamento;
	
	////////Desempilhando na rua
	while(pilhaEstacionamento->topoVeiculo->placa != placa){
		
		numeroDeComparacaoPilha++;
		proximo = pilhaEstacionamento->topoVeiculo->prox;
		atual =	pilhaEstacionamento->topoVeiculo;
		atual->prox = NULL;
		
		
		
		inserirVeiculo(rua, atual);
		
		
		pilhaEstacionamento->topoVeiculo = proximo;
		pilhaEstacionamento->quantCarros--;
		
	}
	
	numeroDeComparacaoPilha++;
	proximo = pilhaEstacionamento->topoVeiculo->prox;
	atual = pilhaEstacionamento->topoVeiculo;
	atual->prox = NULL;
	
	pilhaEstacionamento->topoVeiculo = proximo;
	
	////atualiza a posicao no estacionamento
	if(pilhaEstacionamento->topoVeiculo != NULL) pilhaEstacionamento->topoVeiculo->id--;
	
	
	pilhaEstacionamento->quantCarros--;
	
	
	////////// Reempilhando no estacionamento
	while(rua->topoVeiculo != NULL){
		
		proximo = rua->topoVeiculo->prox;
		atual = rua->topoVeiculo;
		atual->prox = NULL;
		////atualiza a posicao no estacionamento
		atual->id--;
		inserirVeiculo(pilhaEstacionamento, atual);
		rua->quantCarros--;
		rua->topoVeiculo = proximo;
		
	}

}
/*
void imprimirVeiculo(veiculo *c){
	printf("Placa: %d\n", c->placa);
		
}

void imprimirListaVeiculo(estacionamento *lista){
	printf("\n");
	veiculo *aux = lista->topoVeiculo;
	
	for(int i=0; i < lista->quantCarros; i++){
		imprimirVeiculo(aux);
		aux = aux->prox;
	}
	printf("\n");
}

*/

