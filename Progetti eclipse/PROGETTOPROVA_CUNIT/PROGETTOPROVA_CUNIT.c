#include <stdlib.h>
#include "CUnit/Basic.h"
#define INTMAX 1000
#define INTMIN -INTMAX

int sommissima (int a, int b);


/*
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_sommissima(void) {
	CU_ASSERT_TRUE(sommissima(INTMIN,0)==INTMIN);
	CU_ASSERT_TRUE(sommissima(INTMAX,0)==INTMAX);
	CU_ASSERT_TRUE(sommissima(0,INTMIN)==INTMIN);
	CU_ASSERT_TRUE(sommissima(0,INTMAX)==INTMAX);
	CU_ASSERT_TRUE(sommissima(0,0)==0);
	CU_ASSERT_TRUE(sommissima(INTMIN,INTMIN+1)==sommissima(INTMIN,INTMIN)+1);
	CU_ASSERT_TRUE(sommissima(INTMIN+1,INTMIN)==sommissima(INTMIN,INTMIN)+1);
	CU_ASSERT_TRUE(sommissima(INTMAX,INTMIN+1)==sommissima(INTMAX,INTMIN)+1);
	system("pause");
}


/*
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int init_suite_default(void) {
	return 0;
	system("pause");
}

int clean_suite_default(void) {
	return 0;
	system("pause");
}


/* **************************************************
 *	TEST di UNITA'
 */

int main() {
	/* inizializza registro - e' la prima istruzione */
	CU_initialize_registry();
	system("pause");


	/* Aggiungi le suite al test registry */
	CU_pSuite pSuite_sommissima = CU_add_suite("Suite_SOMMISSIMA", init_suite_default, clean_suite_default);

	system("pause");

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_sommissima, "test of sommissima()", test_sommissima);

	system("pause");


	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	system("pause");

	/* Pulisce il registro e termina lo unit test */
	CU_cleanup_registry();
	system("pause");

	return CU_get_error();
	system("pause");
}








