#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QObject>
#include <QImage>
#include <QMouseEvent>

class Editor : public QWidget
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
private:
    const int canvasCheckerboardSize = 8;
    int canvasScale;
    QSize canvasSize;
    QPoint canvasOffset;
    QImage canvas;
    enum tool
    {
        pencil,
        eraser,
        bucket,
        eyedrop,
        select,
        move
    };
    std::map<std::string, tool> toolResolve =
    {
        {"pencil", pencil},
        {"eraser", eraser},
        {"bucket", bucket},
        {"eyedrop", eyedrop},
        {"select", select},
        {"move", move}
    };
    tool activeTool = pencil;
    void refreshCanvas();
public slots:
    void canvasScaleChanged(int);
    void canvasWidthChanged(int);
    void canvasHeightChanged(int);
    void toolSelected();
    void mousePressed(QMouseEvent*);
    void mouseReleased(QMouseEvent*);
    void mouseMoved(QMouseEvent*);
signals:
    void updateViewCanvas(const QImage&, QPoint);
};

#endif // EDITOR_H
