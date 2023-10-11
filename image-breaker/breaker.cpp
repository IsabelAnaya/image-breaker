#include "Breaker.h"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <cmath>
#include <QMessageBox>


void beginSave(QString fileName, QString nameStem, int batchSize, int shifts, QString fileLocation, QString extension, Messages m) {

    std::streampos size;
    char *memblock;

    std::fstream file (fileName.toStdString(), std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open()) {
        size = file.tellg(); //roughly size of file. might be dangerous
        memblock = new char[size];
        file.seekg(0, std::ios::beg);
        file.read(memblock, size);
        file.close();

        //std::cout << "size: " << size << std::endl;
        //std::cout << "file stored" << std::endl;

        saveBatch(memblock, size, nameStem, batchSize, shifts, fileLocation, extension);

        //std::cout << "batch saved" << std::endl;
        delete[] memblock;
        m.completeMessage();
    } else {
        m.errorMessage();
    }
}

void saveBatch(char *memblock, std::streampos size, QString nameStem, int batchSize, int shifts, QString fileLocation, QString extension) {
    const double sizeC = size; //normal distribution wants a double
    std::fstream file;
    srand(time(NULL));

    //big numbers
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{sizeC/2, sizeC/5};

    //base starters
    for (int i = 0; i < batchSize; i++) {
        char *memcopy = new char[size];
        memcpy(memcopy, memblock, size);

        for (int j = 1; j <= shifts; j++) {
            //place to shift (big) (array indices want int)
            int shiftee = std::round(d(gen));

            //don't let it go out of bounds
            while (shiftee <= size/10 || shiftee >= size) {
                shiftee = std::round(d(gen));
            }

            //bit shift value (small)
            int shifter = int(rand() % 5) + 1;


            //std::cout << "shifter: " << shifter << ", shiftee: " << shiftee;
            memcopy[shiftee] = memcopy[shiftee] >> shifter;
            file.open(fileLocation.toStdString() + "/" + nameStem.toStdString() + std::to_string(i) + "shift" + std::to_string(j) + extension.toStdString(), std::ios::out | std::ios::binary | std::ios::ate);
            file.seekp(0, std::ios::beg);
            file.write(memcopy, size);
            file.close();
        }

        delete[] memcopy;
    }
}
