#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PreferenceDialog.h"
#include "Messages.h"
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Messages messages, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void openImage();
    void saveBatch();
    void openPreferences();
    void openAboutPopup();
    void openTutorialPopup();
    void openExportPopup();
    void openDisclaimerPopup();

private:
    void readPreferences();
    void updatePreferences();

    Messages m;

    QMenuBar *menu;
    QMenu *fileMenu;
    QMenu *helpMenu;

    QString initialPath;
    QString fileExtension;
    QString currentFileName;

    PreferenceDialog *prefModal;

    QLabel *fileSelectedLabel;
    QLabel *batchSelectLabel;
    QComboBox *batchSelect;
    QLabel *batchShiftLabel;
    QComboBox *batchShiftSelect;
    QLabel *batchStemLabel;
    QLineEdit *batchStemText;
    QLabel *exportingToLabel;
    QLabel *currDirectoryLabel;
};
#endif // MAINWINDOW_H
