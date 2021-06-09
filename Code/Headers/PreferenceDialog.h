#ifndef PREFERENCEDIALOG_H
#define PREFERENCEDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QLabel>

class PreferenceDialog : public QDialog {
    Q_OBJECT

public:
    PreferenceDialog();
    ~PreferenceDialog();
    void updatePreferenceLabels(QString directory, QString extension);

private slots:
    void cancel();
    void acceptChanges();
    void changeExportDir();

private:

    QRadioButton *pngRadio;
    QRadioButton *rawRadio;
    QLabel *headerLabel;
    QLabel *currSaveDirLabel;
    QPushButton *selectSaveDirButton;
};

#endif // PREFERENCEDIALOG_H
