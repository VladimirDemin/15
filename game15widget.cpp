#include "game15widget.h"
#include <QPushButton>
#include <QMessageBox>

Game15Widget::Game15Widget(QWidget *parent) :
    QWidget(parent),
    m_layout(new QGridLayout(this))
{
    resize(200, 400);
    setLayout(m_layout);
}

void Game15Widget::newGame()
{
    m_game15.create_el();
    deleteButtons();
    createButtons();
}
void Game15Widget::restart_Game()
{
//    m_game15.create_el();
    deleteButtons();
     createButtons();
}
void Game15Widget::deleteButton(int index)
{
    QLayoutItem *item = m_layout->takeAt(index);
    if (item->widget())
        delete item->widget();
    delete item;
}

void Game15Widget::deleteButtons()
{
    while(m_layout->count() > 0)
        deleteButton(0);
}

void Game15Widget::createButton(int value, int row, int column)
{
    QPushButton *button = new QPushButton(QString::number(value));
    button->setMinimumSize(100,100);

    connect(button, SIGNAL(clicked()), SLOT(buttonClick()));

    m_layout->addWidget(button, row, column);


}

void Game15Widget::createButtons()
{
   for (int i = 0; i < Game15::Size; i++)
       for (int j = 0; j < Game15::Size; j++) {
           int value = m_game15.getValue(i, j);
           if (value == Game15::Blank)
               continue;

           createButton(value, i, j);
       }
}

void Game15Widget::buttonClick()
{
    QPushButton *button = (QPushButton *)sender();
    int value = button->text().toInt();
    Cell cell;

    if (m_game15.position(value, cell))
    {
        deleteButton(m_layout->indexOf(button));
        createButton(value, cell.row, cell.column);

        if (m_game15.gameIsFinished())
        {
            deleteButtons();

            QMessageBox::information(this, "", tr("Поздравляем, вы собрали пятнашки! Благодарим за игру!"));
        }
    }
}
