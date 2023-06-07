#ifndef HEAPSORTPROCESSOR_H
#define HEAPSORTPROCESSOR_H

#include <algorithm>
#include <QString>
#include <QByteArray>
#include <QStringList>

class HeapSortProcessor
{
public:
    static QByteArray process(QString values, int step);

    static void heap_sort(double *A, int n, int step);

protected:
    static void sift(double *A, int i, int m);
};

#endif // HEAPSORTPROCESSOR_H
