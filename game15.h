#ifndef GAME15_H
#define GAME15_H

struct Cell
{
    int row;
    int column;
};

class Game15 {
public:
    Game15();

    enum {
        Size = 4,
        Blank = 0
    };

    void create_el();
    int getValue(int row, int column) const;
    bool position(int value, Cell &cell);

    bool gameIsFinished() const;

private:
    int m_matrix[Size][Size];

};

#endif // GAME15_H

