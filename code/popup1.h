#ifndef POPUP1_H
#define POPUP1_H

#include <QWidget>

namespace Ui {
class popup1;
}

class popup1 : public QWidget
{
    Q_OBJECT

public:
    explicit popup1(QWidget *parent = nullptr);
    ~popup1();

private:
    Ui::popup1 *ui;
};

#endif // POPUP1_H
