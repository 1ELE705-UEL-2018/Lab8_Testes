#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "lab8.h"
}

TEST(insertion_sort, EspecificoArrayDoisElementosInsereSegundoAntesDoPrimeiro)
{
	int v[2] = { 1, 0 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	insertion_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(insertion_sort, EspecificoArrayVazio)
{
	insertion_sort(NULL, 0);
}

TEST(insertion_sort, EspecificoArrayUmElemento)
{
	int v[2] = { 0, 1 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	insertion_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(insertion_sort, EspecificoArrayDoisElementosEmOrdem)
{
	int v[2] = { 0, 1 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	insertion_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(insertion_sort, EspecificoArrayTresElementosInsereSegundoAposPrimeiro)
{
	int v[3] = { 0, 2, 1 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2 };

	insertion_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(insertion_sort, EspecificoArrayDoisElementosInserePrimeiroNoInicio)
{
	int v[2] = { 0, -2147483647-1 };
	int v_depois[sizeof(v)/sizeof(int)] = { -2147483647-1, 0 };

	insertion_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

#define FUNCAO_ORDENACAO insertion_sort

#include "testes_ordenacao.h"
