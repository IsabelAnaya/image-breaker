#include "mainwidget.h"
#include "Breaker.h"
#include "MainWindow.h"
#include "Messages.h"
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDockWidget>



MainWindow::MainWindow(Messages messages, QWidget *parent) : QMainWindow(parent) {

    this->resize(400, 100);
    this->setWindowTitle(tr("IMAGE BREAKER"));


    //file bar
    menu = new QMenuBar;
    fileMenu = menuBar()->addMenu(tr("&File"));

    //file->preferences
    QAction *preferencesAction = new QAction(tr("&Preferences"), this);
    connect(preferencesAction, &QAction::triggered, this, &MainWindow::openPreferences);
    fileMenu->addAction(preferencesAction);

    //help bar
    helpMenu = menuBar()->addMenu(tr("&Help"));
    //about
    QAction *aboutAction = new QAction(tr("&About IMAGE BREAKER"), this);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::openAboutPopup);
    helpMenu->addAction(aboutAction);
    //tutorial
    QAction *tutorialAction = new QAction(tr("&Tutorial"), this);
    connect(tutorialAction, &QAction::triggered, this, &MainWindow::openTutorialPopup);
    helpMenu->addAction(tutorialAction);
    //exporting
    QAction *exportAction = new QAction(tr("&Exporting"), this);
    connect(exportAction, &QAction::triggered, this, &MainWindow::openExportPopup);
    helpMenu->addAction(exportAction);
    //disclaimer
    QAction *disclaimerAction = new QAction(tr("&Disclaimer"), this);
    connect(disclaimerAction, &QAction::triggered, this, &MainWindow::openDisclaimerPopup);
    helpMenu->addAction(disclaimerAction);

    //file select label
    fileSelectedLabel = new QLabel(this);
    fileSelectedLabel->setText("Current base:\nNo image selected.");

    //batch size dropdown
    batchSelectLabel = new QLabel;
    batchSelectLabel->setText("Batch Size:");
    batchSelect = new QComboBox;
    batchSelect->addItem("3");
    batchSelect->addItem("5");
    batchSelect->addItem("10");
    //batchSelect->addItem("1"); //testing

    //shift dropdown
    batchShiftLabel = new QLabel;
    batchShiftLabel->setText("Shifts Per Copy:");
    batchShiftSelect = new QComboBox;
    batchShiftSelect->addItem("5");
    batchShiftSelect->addItem("6");
    batchShiftSelect->addItem("7");
    batchShiftSelect->addItem("8");
    batchShiftSelect->addItem("9");
    batchShiftSelect->addItem("10");
    //batchShiftSelect->addItem("1"); //testing

    //text edit
    batchStemLabel = new QLabel;
    batchStemLabel->setText("Batch Name:");
    batchStemText = new QLineEdit;

    //open file button
    QPushButton *openFileButton = new QPushButton("&Choose Image", this);
    connect(openFileButton, &QPushButton::released, this, &MainWindow::openImage);

    //run button
    QPushButton *runButton = new QPushButton("&Run", this);
    connect(runButton, &QPushButton::released, this, &MainWindow::saveBatch);

    //current directory
    currDirectoryLabel = new QLabel(this);
    QFileDialog dialog;
    initialPath = "Exporting to:\n" + dialog.directory().absolutePath();


    //layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(batchSelectLabel);
    layout->addWidget(batchSelect);
    layout->addWidget(batchShiftLabel);
    layout->addWidget(batchShiftSelect);
    layout->addWidget(batchStemLabel);
    layout->addWidget(batchStemText);

    QHBoxLayout *layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(openFileButton);
    layoutButtons->addWidget(runButton);

    layout->addLayout(layoutButtons);
    layout->addWidget(fileSelectedLabel);
    layout->addWidget(currDirectoryLabel);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

    prefModal = new PreferenceDialog;

    m = messages;
    readPreferences();
}


//open file dialog to select image base
void MainWindow::openImage() {
    QFileDialog file;
    currentFileName = file.getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.bmp *.tif *.jpg *.png)"));

    if (currentFileName != "") {
        fileSelectedLabel->setText("Current base:\n" + currentFileName);
        //std::cout << currentFileName.toStdString() << std::endl;
    }
}


//save batch of files
void MainWindow::saveBatch() {
    beginSave(currentFileName, batchStemText->text(), batchSelect->currentText().toInt(), batchShiftSelect->currentText().toInt(), currDirectoryLabel->text(), fileExtension, m);
}

void MainWindow::openPreferences() {
    prefModal->updatePreferenceLabels(currDirectoryLabel->text(), fileExtension);
    if (prefModal->exec() == true) {
        readPreferences();
    }
}

void MainWindow::openAboutPopup() {
    m.aboutMessage();
}

void MainWindow::openTutorialPopup() {
    m.tutorialMessage();
}

void MainWindow::openExportPopup() {
    m.exportMessage();
}

void MainWindow::openDisclaimerPopup() {
    m.disclaimerMessage();
}


//retrieves data from the pref file
void MainWindow::readPreferences() {
    std::fstream file;
    file.open("breakerprefs.txt", std::fstream::in);
    if (file.is_open()) {
        std::string temp;
        std::getline(file, temp);
        fileExtension = QString::fromStdString(temp);

        std::getline(file, temp);
        currDirectoryLabel->setText("Exporting to:\n" + QString::fromStdString(temp));
        file.close();

    } else { //file doesn't exist, make it
        file.open("breakerprefs.txt", std::fstream::out);
        QFileDialog dialog;
        file << ".raw\n" << dialog.directory().absolutePath().toStdString() << std::endl;
        file.close();

        fileExtension = ".raw";
        currDirectoryLabel->setText("Exporting to:\n" + dialog.directory().absolutePath());
    }
}


MainWindow::~MainWindow() {

}
