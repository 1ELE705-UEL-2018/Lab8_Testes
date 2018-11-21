#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "lab8.h"
}

TEST(partition, DoisElementosOrdemInversaTestaQ)
{
	int A[2] = { 1, 0 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(0, q);
}

TEST(partition, DoisElementosOrdemInversaTestaParticao)
{
	int A[2] = { 1, 0 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 0, q, sizeof(A)/sizeof(int) - 1));
}

TEST(partition, DoisElementosEmOrdemTestaParticao)
{
	int A[2] = { 0, 1 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 0, q, sizeof(A)/sizeof(int) - 1));
}

TEST(partition, DoisElementosEmOrdemTestaQ)
{
	int A[2] = { 0, 1 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(1, q);
}

TEST(partition, TresElementosEmOrdemTestaQ)
{
	int A[3] = { 0, 1, 2 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(2, q);
}

TEST(partition, TresElementosEmOrdemTestaParticao)
{
	int A[3] = { 0, 1, 2 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 0, q, sizeof(A)/sizeof(int) - 1));
}

TEST(partition, TresElementosInsereQNoMeioTestaParticao)
{
	int A[3] = { 0, 2, 1 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 0, q, sizeof(A)/sizeof(int) - 1));
}

TEST(partition, TresElementosInsereQNoMeioTestaQ)
{
	int A[3] = { 0, 2, 1 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(1, q);
}

TEST(partition, TresElementosTrocaValoresTestaParticao)
{
	int A[3] = { 2, 0, 1 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 0, q, sizeof(A)/sizeof(int) - 1));
}

TEST(partition, TresElementosTrocaValoresTestaQ)
{
	int A[3] = { 2, 0, 1 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(1, q);
}

TEST(partition, TresElementosPMaiorQueZeroTestaQ)
{
	int A[4] = { 3, 2, 0, 1 };
	int q;

	q = partition(A, 1, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(2, q);
}

TEST(partition, TresElementosPMaiorQueZeroTestaParticao)
{
	int A[4] = { 3, 2, 0, 1 };
	int q;

	q = partition(A, 1, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 1, q, sizeof(A)/sizeof(int) - 1));
}

TEST(partition, OitoElementosExemploLivroTestaQ)
{
	int A[8] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_EQ(3, q);
}

TEST(partition, OitoElementosExemploLivroTestaParticao)
{
	int A[8] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int q;

	q = partition(A, 0, sizeof(A)/sizeof(int) - 1);

	ASSERT_TRUE(PartitionValid(A, 0, q, sizeof(A)/sizeof(int) - 1));
}