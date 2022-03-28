#include "game15.h"
#include <cstring>
#include <ctime>
#include <QtGlobal>

Game15::Game15()
{
    memset(&m_matrix, Blank, sizeof(m_matrix));

    qsrand(time(NULL));
}

void Game15::create_el()
{
    int values[Size * Size];

    for (int i = 0; i < Size * Size; i++) {
        int value;
        bool found;

        do {
            value = qrand() % (Size * Size);
            found = false;
            for (int j = 0; j < i; j++)
                if (value == values[j]) {
                    found = true;
                    break;
                }
        } while (found);

        values[i] = value;
    }

    int index = 0;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            m_matrix[i][j] = values[index++];
}

int Game15::getValue(int row, int column) const
{
//    Q_ASSERT_X(((row >= 0 && row < Size) && (column >= 0 && column < Size)), "Game15::getValue:", "out of range");
    return m_matrix[row][column];
}

bool Game15::position(int value, Cell &cell)
{
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            if (value == m_matrix[i][j]) {
                if (j > 0 && m_matrix[i][j - 1] == Blank)
                {
                    m_matrix[i][j - 1] = m_matrix[i][j];
                    m_matrix[i][j] = Blank;

                    cell.row = i;
                    cell.column = j - 1;

                    return true;
                }

                if (j < Size - 1 && m_matrix[i][j + 1] == Blank)
                {
                    m_matrix[i][j + 1] = m_matrix[i][j];
                    m_matrix[i][j] = Blank;

                    cell.row = i;
                    cell.column = j + 1;

                    return true;
                }

                if (i > 0 && m_matrix[i - 1][j] == Blank)
                {
                    m_matrix[i - 1][j] = m_matrix[i][j];
                    m_matrix[i][j] = Blank;

                    cell.row = i - 1;
                    cell.column = j;

                    return true;
                }

                if (i < Size - 1 && m_matrix[i + 1][j] == Blank)
                {
                    m_matrix[i + 1][j] = m_matrix[i][j];
                    m_matrix[i][j] = Blank;

                    cell.row = i + 1;
                    cell.column = j;

                    return true;
                }
            }

    return false;
}


bool Game15::gameIsFinished() const
{
    int value = 1;

    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++) {
            if (value != m_matrix[i][j])
                return (value == Size * Size);

            value++;
        }

}
