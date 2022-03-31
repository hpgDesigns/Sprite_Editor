#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QPainter>
#include <QImage>
#include "panels/editor.h"
#include "panels/palette.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT
public:
    View(Editor& editorPanel, Palette& palettePanel, QWidget *parent = nullptr);
    ~View();
private:
    Ui::View* ui;
    QActionGroup* toolActionGroup;
    QImage viewCanvas;
    QPoint viewCanvasOffset;
    void updateViewCanvas(const QImage&, QPoint);
    void updateViewPalette(const QVector<QString>&, QSize);
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
signals:
    void mousePressed(QMouseEvent*);
    void mouseReleased(QMouseEvent*);
    void mouseMoved(QMouseEvent*);
};
#endif // VIEW_H
