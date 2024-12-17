#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QString>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr);
    void setImagePath(const QString& path);
    QString getImagePath() const;
    bool isSelected() const;

signals:
    void clicked(const QString& imagePath);

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    QString imagePath;
    bool selected;  // For selection tracking
};

#endif // CLICKABLELABEL_H
