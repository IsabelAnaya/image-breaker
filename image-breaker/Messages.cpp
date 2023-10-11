#include "Messages.h"

Messages::Messages() {
    aboutBox = new QMessageBox;
    aboutBox->setWindowTitle("About");
    aboutBox->setText("Image glitching program.\nMade with Qt.");

    tutorialBox = new QMessageBox;
    tutorialBox->setWindowTitle("Tutorial");
    tutorialBox->setText("Select batch size (how many times the program will try\nglitching the image).\nSelect shifts per copy (how many bit shifts will occur in a\nrow).\nType batch name - each created image's name will start\nwith this.\nClick Choose Image and select an image to use as the base\nfor bit shifting (it will not be affected).\nCheck preferences under \"File\" in the toolbar, then click run.\nNew images will be located in the export directory listed at\nthe bottom of the program's window.");

    exportBox = new QMessageBox;
    exportBox->setWindowTitle("Exporting");
    exportBox->setText("By default, new images will be placed in the same directory as\nthe .exe.\nThe export directory can be changed under\n\"File -> Preferences\".\nThere will be (batch size * shifts per copy) new images, named\n[batch name][run number]shift[shift number].[raw/png].");

    disclaimerBox = new QMessageBox;
    disclaimerBox->setWindowTitle("Disclaimer");
    disclaimerBox->setText("IMAGE BREAKER creates copies of the base image, and should not\neffect the original, unless the image is in the output folder and will\nshare the name of one of the created images.\nDifferent images with different types or sources (ex. a downloaded\n.jpg versus a .bmp from a camera) may have different results, which\nmay be entirely corrupted.\nSome bit shifts may have little or no effect, and some may block the\nimage with a solid color. Both are normal.\nThe preference file should not be manually edited. If it breaks, delete\nthe preference file and a new one should be generated.");

    errorBox = new QMessageBox;
    errorBox->setWindowTitle("ERROR");
    errorBox->setText("Unable to open file.");

    completeBox = new QMessageBox;
    completeBox->setWindowTitle("Success");
    completeBox->setText("Images generated successfully.");
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

void Messages::completeMessage() {
    completeBox->exec();
}
