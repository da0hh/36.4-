#include "imagebutton.h"
#include <QPainter>

ImageButton::ImageButton(QWidget *parent) : QPushButton(parent) {
    setFixedSize(100, 100);

    GreenButton.load("pict/greenBut.png");
    YellowButton.load("pict/blueBut.jpg");
    RedButton.load("pict/redBut.png");

    CurrentButton = GreenButton;
}

void ImageButton::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter p(this);
    p.drawPixmap(rect(), CurrentButton);
}

void ImageButton::updateColor(int newValue) {
    if (newValue <= 33) {
        CurrentButton = GreenButton;
    } else if (newValue <= 66) {
        CurrentButton = YellowButton;
    } else {
        CurrentButton = RedButton;
    }
    update();
}
