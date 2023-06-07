#include <QtTest>
#include "Processor/HeapSortProcessor.h"

// add necessary includes here

class heapSortTest : public QObject
{
    Q_OBJECT

public:
    heapSortTest();
    ~heapSortTest();

private slots:
    void test_case1();

};

heapSortTest::heapSortTest()
{

}

heapSortTest::~heapSortTest()
{

}

void heapSortTest::test_case1()
{
    double *testValues[10] {
        new double[10] {8., 3., 6., 1., 9., 4., 7., 2., 5., 8.},
        new double[10] {2., 7., 9., 4., 5., 1., 3., 6., 8., 7.},
        new double[10] {6., 3., 9., 4., 7., 2., 8., 1., 5., 8.},
        new double[10] {9., 5., 2., 7., 3., 6., 1., 8., 4., 1.},
        new double[10] {3., 7., 5., 1., 6., 4., 8., 2., 9., 6.},
        new double[10] {8., 2., 4., 9., 5., 3., 7., 6., 1., 4.},
        new double[10] {4., 9., 1., 5., 2., 7., 8., 3., 6., 9.},
        new double[10] {2., 6., 8., 3., 1., 9., 5., 7., 4., 4.},
        new double[10] {7., 1., 3., 6., 4., 5., 9., 8., 2., 3.},
        new double[10] {5., 3., 1., 9., 3., 2., 9., 1., 2., 5.},
    };
    double *realValus[10] = {
        new double[10] {8., 5., 7., 2., 3., 4., 6., 1., 8., 9.},
        new double[10] {5., 4., 3., 2., 1., 6., 7., 7., 8., 9.},
        new double[10] {1., 2., 3., 4., 5., 6., 7., 8., 8., 9.},
        new double[10] {8., 7., 6., 5., 3., 2., 1., 1., 4., 9.},
        new double[10] {1., 2., 3., 4., 5., 6., 6., 7., 8., 9.},
        new double[10] {1., 2., 3., 4., 4., 5., 6., 7., 8., 9.},
        new double[10] {5., 4., 3., 1., 2., 6., 7., 8., 9., 9.},
        new double[10] {1., 2., 3., 4., 4., 5., 6., 7., 8., 9.},
        new double[10] {1., 2., 3., 3., 4., 5., 6., 7., 8., 9.},
        new double[10] {5., 3., 3., 1., 2., 2., 1., 5., 9., 9.},
    };
    int step[10] = {2, 5, 9, 1, 10, 23, 5, 22, 18, 3};

    for (int i = 0; i < 10; i++) {
        HeapSortProcessor::heap_sort(testValues[i], 10, step[i]);
        QCOMPARE(testValues[i], realValus[i]);
    }
}

QTEST_APPLESS_MAIN(heapSortTest)

#include "tst_heapsorttest.moc"
