// @filename: simplified_CUnit_template.c
// @rev: 0.1
// @date: 15-02-2015
// @desc: file modello per un main.c con il framework CUnit

#include <stdlib.h>
#include "CUnit/Basic.h"

#define INT_MAX 1000
#define INT_MIN -INT_MAX

#define FACT_MAX 12

int min(int a, int b) {
	return (a < b) ? a : b;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int succ(int n){
	return ++n;
}

int pred(int n){
	return --n;
}

int sum(int a, int b) {
	if (b == 0){
		return a;
	} else if (b > 0) {
		int result = a;
		//int i;
		for (int i=0; i<b; i++){
			result = succ(result);
		}
		return result;
	} else {
		int result = a;
		int i;
		for (i=b; i<0; i++){
			result = pred(result);
		}
		return result;
	}
}

int subtract(int a, int b) {
	return sum(a, -b);
}

int product(int a, int b) {
	if (b == 0){
		return 0;
	} else if (b > 0){
		int result = 0;
		int i;
		for (i=0; i<b; i++){
			result = sum(result, a);
		}
		return result;
	} else {
		return -product(a, -b);
	}
}

int factorial(int n) {
	//printf("%d, ", n);
	return (n <= 0) ? 1 : product(factorial(pred(n)), n);
}

/*
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */

void test_succ(void){
	CU_ASSERT_EQUAL(succ(0), 1);
	CU_ASSERT_EQUAL(succ(INT_MIN), INT_MIN+1);
}

void test_pred(void){
	CU_ASSERT_EQUAL(pred(0), -1);
	CU_ASSERT_EQUAL(pred(INT_MAX), INT_MAX-1);
	CU_ASSERT_EQUAL(succ(pred(INT_MAX)), INT_MAX); // 'succ' testata prima di 'pred'
}


void test_min(void) {
	CU_ASSERT_EQUAL(min(INT_MIN,INT_MIN), INT_MIN);
	CU_ASSERT_EQUAL(min(INT_MIN,0), INT_MIN);
	CU_ASSERT_EQUAL(min(INT_MIN,INT_MAX), INT_MIN);
	CU_ASSERT_EQUAL(min(0,INT_MIN), INT_MIN);
	CU_ASSERT_EQUAL(min(0, 0), 0);
	CU_ASSERT_EQUAL(min(0,INT_MAX), 0);
	CU_ASSERT_EQUAL(min(INT_MAX,INT_MIN), INT_MIN);
	CU_ASSERT_EQUAL(min(INT_MAX,0), 0);
	CU_ASSERT_EQUAL(min(INT_MAX,INT_MAX), INT_MAX);
}

void test_max(void) {
	CU_ASSERT_EQUAL(max(INT_MIN,INT_MIN), INT_MIN);
	CU_ASSERT_EQUAL(max(INT_MIN,0), 0);
	CU_ASSERT_EQUAL(max(INT_MIN,INT_MAX), INT_MAX);
	CU_ASSERT_EQUAL(max(0,INT_MIN), 0);
	CU_ASSERT_EQUAL(max(0, 0), 0);
	CU_ASSERT_EQUAL(max(0,INT_MAX), INT_MAX);
	CU_ASSERT_EQUAL(max(INT_MAX,INT_MIN), INT_MAX);
	CU_ASSERT_EQUAL(max(INT_MAX,0), INT_MAX);
	CU_ASSERT_EQUAL(max(INT_MAX,INT_MAX), INT_MAX);
}

void test_sum(void) {
	// x + 0 == 0 + x == x
	CU_ASSERT_TRUE(sum(INT_MIN,0) == INT_MIN);
	CU_ASSERT_TRUE(sum(INT_MAX,0) == INT_MAX);
	CU_ASSERT_TRUE(sum(0,INT_MIN) == INT_MIN);
	CU_ASSERT_TRUE(sum(0,INT_MAX) == INT_MAX);
	CU_ASSERT_TRUE(sum(0,0) == 0);

	// x+(y+1) == (x+y)+1
	CU_ASSERT_TRUE(sum(INT_MIN,INT_MIN+1) == sum(INT_MIN,INT_MIN)+1);
	CU_ASSERT_TRUE(sum(INT_MIN+1,INT_MIN) == sum(INT_MIN,INT_MIN)+1);
	CU_ASSERT_TRUE(sum(INT_MAX,INT_MIN+1) == sum(INT_MAX,INT_MIN)+1);
}

void test_subtract(void) {
	// x - 0 == x
	CU_ASSERT_TRUE(subtract(INT_MIN,0) == INT_MIN);
	CU_ASSERT_TRUE(subtract(INT_MAX,0) == INT_MAX);
	// 0 - x == -x
	CU_ASSERT_TRUE(subtract(0,INT_MIN) == -INT_MIN);
	CU_ASSERT_TRUE(subtract(0,INT_MAX) == -INT_MAX);
	// x - x == 0
	CU_ASSERT_TRUE(subtract(INT_MIN,INT_MIN) == 0);

	// x-(y+1) == (x-y)-1
	CU_ASSERT_TRUE(subtract(INT_MIN,INT_MIN+1) == subtract(INT_MIN,INT_MIN)-1);
	CU_ASSERT_TRUE(subtract(INT_MAX,INT_MIN+1) == subtract(INT_MAX,INT_MIN)-1);

	// x-(y-1) == (x-y)+1
	CU_ASSERT_TRUE(subtract(INT_MIN,INT_MAX-1) == subtract(INT_MIN,INT_MAX)+1);
	CU_ASSERT_TRUE(subtract(INT_MAX,INT_MAX-1) == subtract(INT_MAX,INT_MAX)+1);

	// x-y = -(y-x)
	CU_ASSERT_TRUE(subtract(INT_MAX,INT_MIN) == -subtract(INT_MIN,INT_MAX));
	CU_ASSERT_TRUE(subtract(INT_MIN,INT_MAX) == -subtract(INT_MAX,INT_MIN));
}

void test_product(void) {
	// x*0 == 0 == 0*y
	CU_ASSERT_TRUE(product(INT_MIN,0) == 0);
	CU_ASSERT_TRUE(product(INT_MAX,0) == 0);
	CU_ASSERT_TRUE(product(0,INT_MIN) == 0);
	CU_ASSERT_TRUE(product(0,INT_MAX) == 0);

	// x*(y+1) == x*y + x
	CU_ASSERT_TRUE(product(INT_MIN,INT_MIN+1) == product(INT_MIN,INT_MIN)+INT_MIN);

	// x*y = y*x
	CU_ASSERT_TRUE(product(INT_MIN,INT_MAX) == product(INT_MAX,INT_MIN));

}

void test_factorial(void) {
	// 0! == 1
	CU_ASSERT_TRUE(factorial(0) == 1);
	CU_ASSERT_TRUE(factorial(FACT_MAX) == FACT_MAX * factorial(FACT_MAX-1));
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



// *************************************************************************************
//	TEST di UNITA'

int main() {

	/* inizializza registro - e' la prima istruzione */
	CU_initialize_registry();

	/* Aggiungi le suite al test registry */
	CU_pSuite pSuite_succ_pred = CU_add_suite("Suite_SUCC-PRED", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_min_max = CU_add_suite("Suite_MIN-MAX", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_sum = CU_add_suite("Suite_SUM", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_prod_sub = CU_add_suite("Suite_PROD-SUB", init_suite_default, clean_suite_default);
	CU_pSuite pSuite_fact = CU_add_suite("Suite_FACTORIAL", init_suite_default, clean_suite_default);

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_succ_pred, "test of succ()", test_succ);
	CU_add_test(pSuite_succ_pred, "test of pred()", test_pred);

	CU_add_test(pSuite_min_max, "test of min()", test_min);
	CU_add_test(pSuite_min_max, "test of max()", test_max);

	CU_add_test(pSuite_sum, "test of sum()", test_sum);

	CU_add_test(pSuite_prod_sub, "test of subtract()", test_subtract);
	CU_add_test(pSuite_prod_sub, "test of product()", test_product);

	CU_add_test(pSuite_fact, "test of factorial()", test_factorial);

	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/*
	 * Pulisce il registro e termina lo unit test
	 */
	CU_cleanup_registry();

	return CU_get_error();
}

