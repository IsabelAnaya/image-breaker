#include "mainwidget.h"

MainWidget::MainWidget() : QWidget() {
    fileLabel->setText("No file selected.");
    batchSelect->addItem("5");
    batchSelect->addItem("10");
    batchSelect->addItem("15");

    layout->addWidget(fileLabel);
    layout->addWidget(batchSelect);
    layout->addWidget(batchStemText);
}
