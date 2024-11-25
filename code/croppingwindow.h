#ifndef CROPPINGWINDOW_H
#define CROPPINGWINDOW_H

#include "closetmanager.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class CroppingWindow; }
QT_END_NAMESPACE

class CroppingWindow : public QMainWindow {
    Q_OBJECT

public:
    //explicit CroppingWindow(const QString &filePath, const QString &type, QWidget *parent = nullptr);
    explicit CroppingWindow(ClosetManager* manager, const QString &filePath, const QString &type, QWidget *parent = nullptr);

    ~CroppingWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void imageCropped(const QString &croppedPath);

private:
    ClosetManager* closetManager;
    Ui::CroppingWindow *ui; // Pointer to the auto-generated UI class
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPathItem *pathItem; // Single path item for lasso
    QPainterPath lassoPath;
    QPixmap originalPixmap;
    bool drawing;

    QString filePath;
    QString type;

    QImage cropImage();
    void saveCrop();
    void resetLasso();
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // CROPPINGWINDOW_H
