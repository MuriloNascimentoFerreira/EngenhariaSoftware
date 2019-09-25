

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include </home/aluno/NetBeansProjects/CarinhoCompras/Produto.c>

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testOrdemAleatorio(){
   Produto carrinhoCompras[3];
   int indexMaisCaro = -1;
   int indexMaisBarato = -1;
   carrinhoCompras[0].nome = "Liquidificador";
   carrinhoCompras[0].preco = 250;
   carrinhoCompras[1].nome = "Geladeira";
   carrinhoCompras[1].preco = 450;
   carrinhoCompras[2].nome = "Jogo de Pratos";
   carrinhoCompras[2].preco = 70;
   encontrarProdutos(carrinhoCompras, &indexMaisCaro, &indexMaisBarato);
   CU_ASSERT_EQUAL(carrinhoCompras[indexMaisBarato].nome,"Jogos de Pratos");
   CU_ASSERT_EQUAL(carrinhoCompras[indexMaisCaro].nome,"Geladeira");

}

void testOrdemDecrescente(){
   Produto carrinhoCompras[3];
   int indexMaisCaro = -1;
   int indexMaisBarato = -1;
   carrinhoCompras[1].nome = "Geladeira";
   carrinhoCompras[1].preco = 450;
   
   carrinhoCompras[0].nome = "Liquidificador";
   carrinhoCompras[0].preco = 250;

   carrinhoCompras[2].nome = "Jogo de Pratos";
   carrinhoCompras[2].preco = 70;
   
   encontrarProdutos(carrinhoCompras, &indexMaisCaro, &indexMaisBarato);
   CU_ASSERT_EQUAL(carrinhoCompras[indexMaisBarato].nome,"Jogos de Pratos");
   CU_ASSERT_EQUAL(carrinhoCompras[indexMaisCaro].nome,"Geladeira");

}



int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("CarrinhoComprasTeste", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite,"testOrdemAleatorio",testOrdemAleatorio)) || (NULL == CU_add_test(pSuite,"testOrdemAleatorio",testOrdemAleatorio))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
