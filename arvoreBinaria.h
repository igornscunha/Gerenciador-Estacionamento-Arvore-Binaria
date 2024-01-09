#include <stdio.h>
#include "veiculos.h"

int idVeiculo = 0;
int numeroDeComparacaoBinaria = 0;

typedef struct EstacionamentoBinario{
    veiculo* automovel;         /////////// conteudo
    struct EstacionamentoBinario *esq, *dir;
}estacionamentoBinario;


estacionamentoBinario* criarArvoreEstacionamento(){
	estacionamentoBinario *arvore = (estacionamentoBinario*) malloc(sizeof(estacionamentoBinario));
    arvore->automovel = NULL;
    arvore->esq = NULL;
    arvore->dir = NULL;
	
	return arvore;
}

estacionamentoBinario* inserirVeiculoNaArvore(estacionamentoBinario* no, veiculo* c){

    if(no == NULL){
		no = criarArvoreEstacionamento();
        no->automovel = c;
    }else if (no->automovel->placa > c->placa)
    {
        /* Adiciona a esquerda */
        no->esq = inserirVeiculoNaArvore(no->esq, c);
    }else if (no->automovel->placa < c->placa)
    {
        /* Adiciona a direita */
        no->dir = inserirVeiculoNaArvore(no->dir, c);
    }

    return no;
}




estacionamentoBinario* maiorDireita(estacionamentoBinario **no){
    if((*no)->dir != NULL) 
       return maiorDireita(&(*no)->dir);
    else{
       estacionamentoBinario *aux = *no;
       if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
       }
}



void buscaRemoveVeiculo(estacionamentoBinario **no, int placa){
	if(*no == NULL){   // esta verificacao serve para caso o placa nao exista na arvore.
		printf("Numero nao existe na arvore!\n");
       
		return;
	}
	if(placa < (*no)->automovel->placa){
		numeroDeComparacaoBinaria++;
		buscaRemoveVeiculo(&(*no)->esq, placa);
	}		
	else if(placa > (*no)->automovel->placa){
			
			numeroDeComparacaoBinaria++;
			buscaRemoveVeiculo(&(*no)->dir, placa);
	}
	else{    // se nao eh menor nem maior, logo, eh a placa que estou procurando
			
		numeroDeComparacaoBinaria++;
		printf("Encontrou o veiculo\n");
		idVeiculo = (*no)->automovel->id;
		estacionamentoBinario *pAux = *no;      //auxiliar
			
		if (((*no)->esq == NULL) && ((*no)->dir == NULL)){         // se nao houver filhos...
			free(pAux);
			(*no) = NULL; 
		}
		else{     // so tem o filho da direita
			if ((*no)->esq == NULL){
				(*no) = (*no)->dir;
				pAux->dir = NULL;
				free(pAux);
				pAux = NULL;
			}
			else{            //so tem filho da esquerda
				if ((*no)->dir == NULL){
					(*no) = (*no)->esq;
					pAux->esq = NULL;
					free(pAux);
					pAux = NULL;
				}
				else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
					pAux = maiorDireita(&(*no)->esq); //
					pAux->esq = (*no)->esq;          //
					pAux->dir = (*no)->dir;
					(*no)->esq = (*no)->dir = NULL;
					free((*no)); 
					*no = pAux;
					pAux = NULL;   
				}
			}
		}
	}

}



void criarEInserirVeiculoNaArvoreBinaria(estacionamentoBinario* arvoreVeiculo, estacionamento* listaVeiculo){
	int placa = 0;
	veiculo *aux = NULL;
	
	printf("Informe o placa da placa do veiculo:\n");
	scanf("%d", &placa);
	
	aux = criarVeiculo(placa);
	inserirVeiculo(listaVeiculo, aux);
    inserirVeiculoNaArvore(arvoreVeiculo, listaVeiculo->topoVeiculo);
		
}

/// imprime a arvore
void exibirArvoreEmOrdem(estacionamentoBinario* raiz){
	if (raiz == NULL) return;
	exibirArvoreEmOrdem(raiz->esq);
	printf("%i ",raiz->automovel->placa);
	exibirArvoreEmOrdem(raiz->dir);
}
