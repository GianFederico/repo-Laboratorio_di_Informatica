#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include "CUnit/Basic.h"
#include "header_per_cunit.h"
#define cont_max_tracce 21
#define cont_max_pl 3
#define cont_min 0
FILE *pfile;
FILE *pfiletest=NULL;
BRANO *struttura;
int cont_pl=0;
int cont_tracce=0;


int conta_playlist (FILE *pfile, int cont_pl);
int conta_righe(FILE *pfile, int cont_tracce);
int visualizza_playlist (FILE *pfile);
int ordina_brani (FILE *pfile, BRANO *struttura, int cont_tracce);

/*
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */

void test_conta_playlist(void) {
	CU_ASSERT_TRUE(conta_playlist(pfile,cont_pl)==cont_max_pl);
	CU_ASSERT_TRUE(conta_playlist(pfile,cont_max_pl)==cont_max_pl);
	CU_ASSERT_TRUE(conta_playlist(pfile,cont_min)==cont_max_pl);
}

void test_conta_righe(void) {
	CU_ASSERT_TRUE(conta_righe(pfile,cont_tracce)==cont_max_tracce);
	CU_ASSERT_TRUE(conta_righe(pfile,cont_min)==cont_max_tracce);
	CU_ASSERT_TRUE(conta_righe(pfile,cont_max_tracce)==cont_max_tracce);
}


void test_visualizza_playlist(void) {
	CU_ASSERT_TRUE(visualizza_playlist(pfile)==0);
	CU_ASSERT_TRUE(visualizza_playlist(pfiletest)==0);
}

void test_ordina_brani(void) {
	CU_ASSERT_TRUE(ordina_brani(pfile,struttura,cont_max_tracce)==0);
	CU_ASSERT_TRUE(ordina_brani(pfile,struttura,cont_min)==0);
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
	CU_pSuite pSuite_conta_playlist = CU_add_suite("Suite_conta_playlist", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_conta_righe = CU_add_suite("Suite_conta_righe", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_visualizza_playlist = CU_add_suite("Suite_visualizza_playlist", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_ordina_brani = CU_add_suite("Suite_ordina_brani", init_suite_default, clean_suite_default);

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_conta_playlist, "test of conta_playlist\n", test_conta_playlist);
	CU_add_test(pSuite_conta_righe, "test of conta_righe\n", test_conta_righe);
	CU_add_test(pSuite_visualizza_playlist, "test of visualizza_playlist\n", test_visualizza_playlist);
	CU_add_test(pSuite_ordina_brani, "test of ordina_brani\n", test_ordina_brani);

	system("pause");


	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/* Pulisce il registro e termina lo unit test */
	CU_cleanup_registry();

	system("pause");

	return CU_get_error();
}
