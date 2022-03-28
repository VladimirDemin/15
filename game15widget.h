#ifndef GAME15WIDGET_H
#define GAME15WIDGET_H

#include "game15.h"
#include <QWidget>
#include <QGridlayout>

class Game15Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Game15Widget(QWidget *parent = 0);

public slots:
    void newGame();
    void restart_Game();


private slots:
void buttonClick();

private:
    void deleteButton(int index);
    void deleteButtons();
    void createButton(int value, int row, int column);
    void createButtons();


    Game15 m_game15;
    QGridLayout *m_layout;

};

#endif // GAME15WIDGET_H
