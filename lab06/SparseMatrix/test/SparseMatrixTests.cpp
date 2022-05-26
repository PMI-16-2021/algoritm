#include <SparseMatrix.h>
#include <gtest/gtest.h>

TEST(SparseMatrixTests, constructionTest) {
    SparseMatrix<int> sparseMatrix(4);
    sparseMatrix.set(5, 2, 1);
    EXPECT_EQ(sparseMatrix.get(2, 1), 5);
    EXPECT_EQ(sparseMatrix.get(4, 3), 0);
    EXPECT_EQ(sparseMatrix.getColumnCount(), 4);
    EXPECT_EQ(sparseMatrix.getRowCount(), 4);
}

TEST(SparseMatrixTests, significantElementsTest) {
    SparseMatrix<int> sparseMatrix(4, 10);
    sparseMatrix.set(5, 2, 1);
    sparseMatrix.set(1, 4, 1);
    sparseMatrix.set(2, 1, 6);
    sparseMatrix.set(4, 3, 6);
    int numbers[4] = {2, 5, 4, 1};
    std::vector<int> significantElements = sparseMatrix.significantElements();
    for (int i = 0; i < significantElements.size(); ++i) {
        EXPECT_EQ(significantElements[i], numbers[i]);
    }
}

TEST(SparseMatrixTests, getTest) {
    SparseMatrix<int> sparseMatrix(3);
    sparseMatrix.set(1, 3, 1);
    sparseMatrix.set(5, 1, 2);
    sparseMatrix.set(7, 1, 1);
    sparseMatrix.set(10, 2, 2);

    EXPECT_EQ(sparseMatrix.get(3, 1), 1);
    EXPECT_EQ(sparseMatrix.get(1, 2), 5);
    EXPECT_EQ(sparseMatrix.get(1, 1), 7);
    EXPECT_EQ(sparseMatrix.get(2, 2), 10);
}

TEST(SparseMatrixTests, additionTest) {
    SparseMatrix<int> sparseMatrix1(4);
    sparseMatrix1.set(1, 1, 1);
    sparseMatrix1.set(2, 1, 2);
    sparseMatrix1.set(3, 1, 3);
    sparseMatrix1.set(4, 1, 4);
    sparseMatrix1.set(5, 2, 1);
    sparseMatrix1.set(6, 2, 2);
    sparseMatrix1.set(7, 2, 3);
    sparseMatrix1.set(8, 2, 4);
    sparseMatrix1.set(9, 3, 1);
    sparseMatrix1.set(10, 3, 2);
    sparseMatrix1.set(11, 3, 3);
    sparseMatrix1.set(12, 3, 4);
    sparseMatrix1.set(13, 4, 1);
    sparseMatrix1.set(14, 4, 2);
    sparseMatrix1.set(15, 4, 3);
    sparseMatrix1.set(16, 4, 4);
    // MATRIX 1
    /* 1 2 3 4
     * 5 6 7 8
     * 9 10 11 12
     * 13 14 15 16
     */
    SparseMatrix<int> sparseMatrix2(4);
    sparseMatrix2.set(4, 3, 4);
    sparseMatrix2.set(5, 1, 2);
    sparseMatrix2.set(10, 3, 1);
    sparseMatrix2.set(17, 2, 2);
    sparseMatrix2.set(17, 4, 2);
    // MATRIX 2
    /* 0 5 0 0
     * 0 17 0 0
     * 10 0 0 4
     * 0 17 0 0
    */
    // RESULT MATRIX
    /*
    1	7	3	4
    5	23	7	8
    19	10	11	16
    13	31	15	16
     */
    SparseMatrix<int> expectedResultMatrix(4);
    expectedResultMatrix.set(1, 1, 1);
    expectedResultMatrix.set(7, 1, 2);
    expectedResultMatrix.set(3, 1, 3);
    expectedResultMatrix.set(4, 1, 4);
    expectedResultMatrix.set(5, 2, 1);
    expectedResultMatrix.set(23, 2, 2);
    expectedResultMatrix.set(7, 2, 3);
    expectedResultMatrix.set(8, 2, 4);
    expectedResultMatrix.set(19, 3, 1);
    expectedResultMatrix.set(10, 3, 2);
    expectedResultMatrix.set(11, 3, 3);
    expectedResultMatrix.set(16, 3, 4);
    expectedResultMatrix.set(13, 4, 1);
    expectedResultMatrix.set(31, 4, 2);
    expectedResultMatrix.set(15, 4, 3);
    expectedResultMatrix.set(16, 4, 4);

    SparseMatrix<int> currentResultMatrix = sparseMatrix1.addition(sparseMatrix2);

    for (int i = 1; i < sparseMatrix1.getRowCount(); ++i) {
        for (int j = 1; j < sparseMatrix1.getColumnCount(); ++j) {
            EXPECT_EQ(currentResultMatrix.get(i, j), expectedResultMatrix.get(i, j));
        }
    }
}

TEST(SparseMatrixTests, subtractTest) {
    SparseMatrix<int> sparseMatrix1(4);
    sparseMatrix1.set(1, 1, 1);
    sparseMatrix1.set(2, 1, 2);
    sparseMatrix1.set(3, 1, 3);
    sparseMatrix1.set(4, 1, 4);
    sparseMatrix1.set(5, 2, 1);
    sparseMatrix1.set(6, 2, 2);
    sparseMatrix1.set(7, 2, 3);
    sparseMatrix1.set(8, 2, 4);
    sparseMatrix1.set(9, 3, 1);
    sparseMatrix1.set(10, 3, 2);
    sparseMatrix1.set(11, 3, 3);
    sparseMatrix1.set(12, 3, 4);
    sparseMatrix1.set(13, 4, 1);
    sparseMatrix1.set(14, 4, 2);
    sparseMatrix1.set(15, 4, 3);
    sparseMatrix1.set(16, 4, 4);
    // MATRIX 1
    /* 1 2 3 4
     * 5 6 7 8
     * 9 10 11 12
     * 13 14 15 16
     */
    SparseMatrix<int> sparseMatrix2(4);
    sparseMatrix2.set(4, 3, 4);
    sparseMatrix2.set(5, 1, 2);
    sparseMatrix2.set(10, 3, 1);
    sparseMatrix2.set(17, 2, 2);
    sparseMatrix2.set(17, 4, 2);
    // MATRIX 2
    /* 0 5 0 0
     * 0 17 0 0
     * 10 0 0 4
     * 0 17 0 0
    */
    // RESULT MATRIX
    /*
    1	-3	3	4
    5	-11	7	8
    -1	10	11	8
    13	-3	15	16
     */
    SparseMatrix<int> expectedResultMatrix(4);
    expectedResultMatrix.set(1, 1, 1);
    expectedResultMatrix.set(-3, 1, 2);
    expectedResultMatrix.set(3, 1, 3);
    expectedResultMatrix.set(4, 1, 4);
    expectedResultMatrix.set(5, 2, 1);
    expectedResultMatrix.set(-11, 2, 2);
    expectedResultMatrix.set(7, 2, 3);
    expectedResultMatrix.set(8, 2, 4);
    expectedResultMatrix.set(-1, 3, 1);
    expectedResultMatrix.set(10, 3, 2);
    expectedResultMatrix.set(11, 3, 3);
    expectedResultMatrix.set(8, 3, 4);
    expectedResultMatrix.set(13, 4, 1);
    expectedResultMatrix.set(-3, 4, 2);
    expectedResultMatrix.set(15, 4, 3);
    expectedResultMatrix.set(16, 4, 4);

    SparseMatrix<int> currentResultMatrix = sparseMatrix1.subtract(sparseMatrix2);

    for (int i = 1; i < sparseMatrix1.getRowCount(); ++i) {
        for (int j = 1; j < sparseMatrix1.getColumnCount(); ++j) {
            EXPECT_EQ(currentResultMatrix.get(i, j), expectedResultMatrix.get(i, j));
        }
    }
}

TEST(SparseMatrixTests, multiplicationTest) {
    SparseMatrix<int> sparseMatrix1(4);
    sparseMatrix1.set(1, 1, 1);
    sparseMatrix1.set(2, 1, 2);
    sparseMatrix1.set(3, 1, 3);
    sparseMatrix1.set(4, 1, 4);
    sparseMatrix1.set(5, 2, 1);
    sparseMatrix1.set(6, 2, 2);
    sparseMatrix1.set(7, 2, 3);
    sparseMatrix1.set(8, 2, 4);
    sparseMatrix1.set(9, 3, 1);
    sparseMatrix1.set(10, 3, 2);
    sparseMatrix1.set(11, 3, 3);
    sparseMatrix1.set(12, 3, 4);
    sparseMatrix1.set(13, 4, 1);
    sparseMatrix1.set(14, 4, 2);
    sparseMatrix1.set(15, 4, 3);
    sparseMatrix1.set(16, 4, 4);
    // MATRIX 1
    /* 1 2 3 4
     * 5 6 7 8
     * 9 10 11 12
     * 13 14 15 16
     */
    SparseMatrix<int> sparseMatrix2(4);
    sparseMatrix2.set(4, 3, 4);
    sparseMatrix2.set(5, 1, 2);
    sparseMatrix2.set(10, 3, 1);
    sparseMatrix2.set(17, 2, 2);
    sparseMatrix2.set(17, 4, 2);
    // MATRIX 2
    /* 0 5 0 0
     * 0 17 0 0
     * 10 0 0 4
     * 0 17 0 0
    */
    // RESULT MATRIX
    /*
    30	107	0	12
    70	263	0	28
    110	419	0	44
    150	575	0	60
     */
    SparseMatrix<int> expectedResultMatrix(4);
    expectedResultMatrix.set(30, 1, 1);
    expectedResultMatrix.set(107, 1, 2);
    expectedResultMatrix.set(12, 1, 4);
    expectedResultMatrix.set(70, 2, 1);
    expectedResultMatrix.set(263, 2, 2);
    expectedResultMatrix.set(28, 2, 4);
    expectedResultMatrix.set(110, 3, 1);
    expectedResultMatrix.set(419, 3, 2);
    expectedResultMatrix.set(44, 3, 4);
    expectedResultMatrix.set(150, 4, 1);
    expectedResultMatrix.set(575, 4, 2);
    expectedResultMatrix.set(60, 4, 4);

    SparseMatrix<int> currentResultMatrix = sparseMatrix1.multiply(sparseMatrix2);

    for (int i = 1; i < sparseMatrix1.getRowCount(); ++i) {
        for (int j = 1; j < sparseMatrix1.getColumnCount(); ++j) {
            EXPECT_EQ(currentResultMatrix.get(i, j), expectedResultMatrix.get(i, j));
        }
    }
}

TEST(SparseMatrixTests, setTest) {
    SparseMatrix<int> sparseMatrix(7);
    sparseMatrix.set(1, 5, 6);
    sparseMatrix.set(4, 7, 1);

    EXPECT_EQ(sparseMatrix.get(5, 6), 1);
    EXPECT_EQ(sparseMatrix.get(7, 1), 4);
    EXPECT_EQ(sparseMatrix.get(1, 1), 0);
}

