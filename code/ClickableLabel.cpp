#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent) : QLabel(parent), selected(false) {}

void ClickableLabel::setImagePath(const QString& path) {
    imagePath = path;
}

QString ClickableLabel::getImagePath() const {
    return imagePath;
}

bool ClickableLabel::isSelected() const {
    return selected;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        selected = !selected;  // Toggle selection
        if (selected) {
            setStyleSheet("border: 2px solid red;");  // Highlight selection
        } else {
            setStyleSheet("");  // Remove highlight
        }
    } else if (event->button() == Qt::RightButton) {
        emit clicked(imagePath);  // Emit the clicked signal for single deletion
    }

    QLabel::mousePressEvent(event);
}
