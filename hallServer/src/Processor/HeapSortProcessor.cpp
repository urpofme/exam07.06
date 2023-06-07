#ifndef HEAPSORTPROCESSOR_CPP
#define HEAPSORTPROCESSOR_CPP

#include "Processor/HeapSortProcessor.h"

QByteArray HeapSortProcessor::process(QString values, int step)
{
    QStringList rawValues = QString(values).trimmed().split(" ");
    double* floatValue = new double[rawValues.count()];

    int size = 0;
    for (auto value : rawValues) {
        floatValue[size] = value.toDouble();
        size++;
    }

    heap_sort(floatValue, size, step);

    QStringList finalValues;
    for (int i = 0; i < size; i++) {
        finalValues << QString::number(floatValue[i]);
    }

    delete[] floatValue;

    return finalValues.join(" ").toUtf8();
}

void HeapSortProcessor::sift(double *A, int i, int m)
{
    int j = i, k = i * 2 + 1;

    while (k <= m) {
        if (k < m && A[k] < A[k+1]) {
            k++;
        }

        if (A[j] < A[k]){
            std::swap(A[j], A[k]);
            j = k;
            k = k * 2 + 1;
        } else {
            break;
        }
    }
}

void HeapSortProcessor::heap_sort(double *A, int n, int step)
{
    int i, m;
    // построение пирамиды
    for (i = n / 2; i >= 0; i--) {
        sift(A, i, n-1);
    }

    // сортировка массива
    for (m = n-1, i = 0; m >= 1 && i < step; m--, i++) {
        std::swap(A[0], A[m]);
        sift(A, 0, m-1);
    }
}

#endif // HEAPSORTPROCESSOR_CPP
