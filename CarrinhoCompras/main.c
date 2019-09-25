#include <stdio.h>
#include <stdlib.h>
#include </home/aluno/NetBeansProjects/CarinhoCompras/Produto.c>
#define N 3

void encontrarProdutos(Produto *carrinhoCompras,int *indexMaisCaro,int *indexMaisBarato){
    Produto *produto = NULL;
    
    for (int i = 0; i < N; i++) {
        produto = &carrinhoCompras[i];
        if(*indexMaisBarato == -1 || produto->preco < carrinhoCompras[*indexMaisBarato].preco){
            *indexMaisBarato = i;
        }else if (*indexMaisCaro == -1 || produto->preco > carrinhoCompras[*indexMaisCaro].preco){
            *indexMaisCaro = i;
        }
    }
}    

int main() {
    Produto carrinhoCompras[N];
    
    int indexMaisCaro = -1;
    int indexMaisBarato = -1;
    
    carrinhoCompras[0].nome = "Liquidificador";
    carrinhoCompras[0].preco = 250;
    
    carrinhoCompras[1].nome = "Geladeira";
    carrinhoCompras[1].preco = 450;
    
    carrinhoCompras[2].nome = "Jogo de Pratos";
    carrinhoCompras[2].preco = 70;
    
    encontrarProdutos(carrinhoCompras, &indexMaisCaro, &indexMaisBarato);
    
    printf("Produto mais barato: %s\n", carrinhoCompras[indexMaisBarato].nome);
    printf("Produto mais caro: %s\n", carrinhoCompras[indexMaisCaro].nome);
    
    return (EXIT_SUCCESS);
}

