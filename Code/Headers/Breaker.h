#ifndef BREAKER_H
#define BREAKER_H

#include <QString>
#include "Messages.h"

void beginSave(QString fileName, QString nameStem, int batchSize, int shifts, QString fileLocation, QString extension, Messages m);
void saveBatch(char *memblock, std::streampos size, QString nameStem, int batchSize, int shifts, QString fileLocation, QString extension);

#endif // BREAKER_H
