#ifndef MESSAGES_H
#define MESSAGES_H

#include <QMessageBox>

class Messages {

public:
    Messages();
    void aboutMessage();
    void tutorialMessage();
    void exportMessage();
    void disclaimerMessage();
    void errorMessage();

private:
    QMessageBox *aboutBox;
    QMessageBox *tutorialBox;
    QMessageBox *exportBox;
    QMessageBox *disclaimerBox;
    QMessageBox *errorBox;
};



#endif // MESSAGES_H
