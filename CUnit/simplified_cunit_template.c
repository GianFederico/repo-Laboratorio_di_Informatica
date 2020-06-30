// @filename: simplified_cunit_template.c
// @rev: 0.1
// @date: 15-02-2015
// @desc: file modello per un main.c con il framework CUnit

#include <stdlib.h>
#include "CUnit/Basic.h"

void f1(void) {

}
void f2(void) {

}
void f3(void) {

}
void f4(void) {

}

/*
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_f1(void) {
	// TODO
	f1();
	CU_FAIL("test non implementato");
}

void test_f2(void) {
	// TODO
	f2();
	CU_FAIL("test non implementato");
}

void test_f3(void) {
	// TODO
	f3();
	CU_FAIL("test non implementato");
}

void test_f4(void) {
	// TODO
	f4();
	CU_FAIL("test non implementato");
}

/*
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int init_suite_default(void) {
	return 0;
}

int clean_suite_default(void) {
	return 0;
}


/* **************************************************
 *	TEST di UNITA'
 */

int main() {
	/* inizializza registro - e' la prima istruzione */
	CU_initialize_registry();

	/* Aggiungi le suite al test registry */
	CU_pSuite pSuite_A = CU_add_suite("Suite_A", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_B = CU_add_suite("Suite_B", init_suite_default, clean_suite_default);

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_A, "test of f1()", test_f1);
	CU_add_test(pSuite_A, "test of f3()", test_f3);

	CU_add_test(pSuite_B, "test of f4()", test_f4);
	CU_add_test(pSuite_B, "test of f2()", test_f2);

	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/* Pulisce il registro e termina lo unit test */
	CU_cleanup_registry();

	return CU_get_error();
}

