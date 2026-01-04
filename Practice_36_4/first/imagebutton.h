#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QPaintEvent>

class ImageButton : public QPushButton {
    Q_OBJECT

public:
    explicit ImageButton(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e) override;
    void updateColor(int newValue);

private:
    QPixmap GreenButton;
    QPixmap YellowButton;
    QPixmap RedButton;
    QPixmap CurrentButton;
};

#endif
