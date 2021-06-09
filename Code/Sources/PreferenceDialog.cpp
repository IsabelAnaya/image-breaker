#include <PreferenceDialog.h>
#include <fstream>
#include <iostream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QFileDialog>


PreferenceDialog::PreferenceDialog() {

    setWindowTitle("IMAGE BREAKER - Preferences");

    headerLabel = new QLabel(this);
    headerLabel->setText("Currently exporting to:");
    currSaveDirLabel = new QLabel(this);
    currSaveDirLabel->setText("n/a");
    selectSaveDirButton = new QPushButton("&Select Export Directory", this);
    connect(selectSaveDirButton, &QPushButton::released, this, &PreferenceDialog::changeExportDir);

    QGroupBox *extensionRadioGroup = new QGroupBox(tr("File Extension"));
    pngRadio = new QRadioButton(tr("&.png"));
    rawRadio = new QRadioButton(tr("&.raw"));
    QVBoxLayout *radioLayout = new QVBoxLayout;
    radioLayout->addWidget(pngRadio);
    radioLayout->addWidget(rawRadio);
    extensionRadioGroup->setLayout(radioLayout);

    QPushButton *cancelButton = new QPushButton("&Cancel", this);
    connect(cancelButton, &QPushButton::released, this, &PreferenceDialog::cancel);
    QPushButton *acceptChangesButton = new QPushButton("&Accept Changes", this);
    connect(acceptChangesButton, &QPushButton::released, this, &PreferenceDialog::acceptChanges);
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(acceptChangesButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(headerLabel);
    layout->addWidget(currSaveDirLabel);
    layout->addWidget(selectSaveDirButton);
    layout->addWidget(extensionRadioGroup);
    layout->addLayout(buttonsLayout);

    setLayout(layout);
}

void PreferenceDialog::updatePreferenceLabels(QString directory, QString extension) {
    currSaveDirLabel->setText(directory);
    if (extension == ".raw") {
        rawRadio->setChecked(true);
    } else if (extension == ".png") {
        pngRadio->setChecked(true);
    }
}

void PreferenceDialog::cancel() {
    reject();
}

void PreferenceDialog::acceptChanges() {
    std::fstream file;

    file.open("breakerprefs.txt", std::fstream::out);

    if (rawRadio->isChecked()) {
        file << ".raw" << std::endl;
    } else {
        file << ".png" << std::endl;
    }

    file << currSaveDirLabel->text().toStdString() << std::endl;
    file.close();

    accept();
}

void PreferenceDialog::changeExportDir() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    if (dialog.exec() == true) {
        currSaveDirLabel->setText(dialog.directory().absolutePath());
    }
}

PreferenceDialog::~PreferenceDialog() {

}
