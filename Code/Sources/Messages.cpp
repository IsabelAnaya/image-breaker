#include "../Headers/Messages.h"

Messages::Messages() {
    aboutBox = new QMessageBox;
    aboutBox->setWindowTitle("About");
    aboutBox->setText("this is pure jank lol\nmade with qt");

    tutorialBox = new QMessageBox;
    tutorialBox->setWindowTitle("Tutorial");
    tutorialBox->setText("Select batch size (how many times the program will run)\nSelect shifts per copy (the amount of breaks applied)\nType batch name - it will be the prefix for each new image\nChoose image and select an image to apply breaks, or shifts to\nCheck preferences under \"File\", then click run\nNew images will be located in the export directory in your computer");

    exportBox = new QMessageBox;
    exportBox->setWindowTitle("Exporting");
    exportBox->setText("By default, new images will be placed in the same directory as the .exe\nTo change the export directory, change it in \"File -> Preferences\"\nThere will be (batch size x shifts per copy) new images, named\n[batch name][run number]shift[shift number].[extension]");

    disclaimerBox = new QMessageBox;
    disclaimerBox->setWindowTitle("Disclaimer");
    disclaimerBox->setText("IMAGE BREAKER creates copies of the base image, and will not effect the\n original, unless it follows the naming conventions.\nDifferent images with different types or sources (ex. a downloaded .jpg versus\na .bmp from a camera) may have different results, which may be entirely\n corrupted.\nSome shifts may have little or no effect, and some may block the image with\na solid color. Both are normal.\nIf you mess with the preference file and it breaks, that's on you. Delete the \npreference file and a new one should be generated.");

    errorBox = new QMessageBox;
    errorBox->setWindowTitle("ERROR");
    errorBox->setText("Unable to open file.");
}

void Messages::aboutMessage() {
    aboutBox->exec();
}

void Messages::tutorialMessage() {
    tutorialBox->exec();
}

void Messages::exportMessage() {
    exportBox->exec();
}

void Messages::disclaimerMessage() {
    disclaimerBox->exec();
}

void Messages::errorMessage() {
    errorBox->exec();
}
