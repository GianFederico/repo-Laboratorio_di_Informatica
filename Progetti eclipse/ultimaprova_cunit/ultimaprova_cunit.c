#include <stdlib.h>
#include "CUnit/Basic.h"

void f1(void);

void f2(void);

//======================================
void test_f1(void) {
	//casi di test
        //es: CU_ASSERT_TRUE(somma(INTMIN,INTMIN+1)==somma(INTMIN,INTMIN)+1);
}

void test_f2(void) {

}

//======================================
int init_suite_default(void) {
	return 0;
}

int clean_suite_default(void) {
	return 0;
}

/* TEST DI UNITA' */

int main() {
	CU_initialize_registry();

	/* suite al test registry */

  CU_pSuite pSuite_A = CU_add_suite("Suite_A", init_suite_default, clean_suite_default);
  CU_pSuite pSuite_B = CU_add_suite("Suite_B", init_suite_default, clean_suite_default);

  CU_add_test(pSuite_A, "test of f1()", test_f1);     //con ordine
  CU_add_test(pSuite_B, "test of f2()", test_f2);

	/* Esegue i casi di test */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

	return CU_get_error();
}
