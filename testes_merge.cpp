#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "lab8.h"
}

TEST(merge, A_B_Vazios)
{
	merge(NULL, NULL, 0, NULL, 0);
}

TEST(merge, A_UmElemento_B_Vazio)
{
	int A[1] = { 0 };
	int C_depois[1] = { 0 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), NULL, 0);

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_DoisElementos_B_Vazio)
{
	int A[2] = { 0, 1 };
	int C_depois[2] = { 0, 1 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), NULL, 0);

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_Vazio_B_UmElemento)
{
	int B[1] = { 0 };
	int C_depois[1] = { 0 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, NULL, 0, B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_Vazio_B_DoisElementos)
{
	int B[2] = { 0, 1 };
	int C_depois[2] = { 0, 1 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, NULL, 0, B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_UmElemento_B_UmElemento_A0B0)
{
	int A[1] = { 0 };
	int B[1] = { 1 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_UmElemento_B_UmElemento_B0A0)
{
	int A[1] = { 1 };
	int B[1] = { 0 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_DoisElementos_B_UmElemento_A0B0A1)
{
	int A[2] = { 0, 2 };
	int B[1] = { 1 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1, 2 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_DoisElementos_B_UmElemento_A0A1B0)
{
	int A[2] = { 0, 1 };
	int B[1] = { 2 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1, 2 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_UmElemento_B_DoisElementos_B0A0B1)
{
	int A[1] = { 1 };
	int B[2] = { 0, 2 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1, 2 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_UmElemento_B_DoisElementos_B0B1A0A0)
{
	int A[1] = { 2 };
	int B[2] = { 0, 1 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1, 2 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}

TEST(merge, A_DoisElementos_B_DoisElementos_A0B0B1A1)
{
	int A[2] = { 0, 3 };
	int B[2] = { 1, 2 };
	int C_depois[(sizeof(A)+sizeof(B))/sizeof(int)] = { 0, 1, 2, 3 };
	int C[sizeof(C_depois)/sizeof(int)];

	merge(C, A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(C_depois, C));
}