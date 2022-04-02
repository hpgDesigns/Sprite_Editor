#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QPainter>
#include <QImage>
#include "panels/editor.h"
#include "panels/palette.h"
#include "panels/frame.h"
#include <QListWidget>
#include <QTableWidgetItem>

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
    Frame frame;
    Ui::View* ui;
    QActionGroup* toolActionGroup;
    QImage viewCanvas;
    QPoint viewCanvasOffset;
    QPoint calculateViewCanvasAnchor();
    void updateViewCanvas(const QImage&, QPoint);
    void updateViewPalette(const QVector<QString>&, QSize);
protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
signals:
    void mousePressed(QMouseEvent*);
    void mouseReleased(QMouseEvent*);
    void mouseMoved(QMouseEvent*);
    void canvasAnchorChanged(QPoint);
    void pressedAddFrame();
    void pressedRemoveFrame();
    void colorSelected(QColor);
private slots:
    void on_addFrameButton_pressed();
    void on_removeFrameButton_pressed();
    void on_frameslist_itemDoubleClicked(QListWidgetItem *item);
    void on_frameslist_itemClicked(QListWidgetItem *item);
    void setColor(QTableWidgetItem *item);
};
#endif // VIEW_H
