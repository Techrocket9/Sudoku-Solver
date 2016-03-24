#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

//Model for Sudoku board

#include <QColor>
#include <QMap>
#include <QObject>
#include <QPoint>
#include <QPolygon>
#include <QSize>

namespace CIS5603
{

class SudokuBoardPrivate;

class SudokuBoard : public QObject
{
    Q_OBJECT
public:
    explicit SudokuBoard(QObject *parent = 0);
    explicit SudokuBoard(const QString &file, QObject *parent = 0);
    explicit SudokuBoard(SudokuBoard *other, QObject *parent = 0);
    ~SudokuBoard();

    bool isValid() const;

    QString name() const;

    //Board size
    int rows() const;
    int columns() const;

    int minimum() const; //Minimum value
    int maximum() const; //Maximum value

    QList<QPolygon> blocks() const; //All inner blocks

    //Return the block that the cell belongs to, or empty block if the cell does not belong to any block
    QPolygon findBlock(const QPoint &pos);
    inline QPolygon findBlock(int row, int column) { return findBlock(QPoint(row, column)); }

    //Background color for blocks, this is optional
    QList<QColor> colors() const;

    bool saveToFile(const QString &file, QString *error = 0);

signals:
    void configurationChanged();
    void nameChanged(const QString &oldName);
    void rowsChanged(int oldRows);
    void columnsChanged(int oldColumns);
    void minimumChanged(int oldMin);
    void maximumChanged(int oldMax);
    void rangeChanged(int oldMin, int oldMax);
    void blocksChanged(const QList<QPolygon> &oldBlocks);
    void colorsChanged(const QList<QColor> &colors);

public slots:
    bool loadFromFile(const QString &file, QString *error = 0);
    void setName(const QString &name);
    void setRows(int rows);
    void setColumns(int columns);
    inline void setSize(int rows, int columns) { setRows(rows); setColumns(columns); }
    void setMinimum(int min);
    void setMaximum(int max);
    void setRange(int min, int max);
    void setBlocks(const QList<QPolygon> &blocks);
    void setColors(const QList<QColor> &colors);

private:
    SudokuBoardPrivate *m_private;
};

}

#endif // SUDOKUBOARD_H
