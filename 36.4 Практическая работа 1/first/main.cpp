#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QPushButton>
#include <QSlider>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>

using namespace std;

class ImageButton : public QPushButton
{
public:
    ImageButton(QWidget *parent = nullptr) : QPushButton(parent) {
        setFixedSize(100, 100);
        RedButton.load("redBut.png");
        GreenButton.load("greenBut.png");
        BlueButton.load("blueBut.jpg");
        CurrentButton = GreenButton;
    }

    void paintEvent(QPaintEvent *e) override{
        QPainter p(this);
        p.drawPixmap(e->rect(), CurrentButton);
    }

    void updateColor(int newValue) {
        if (newValue <= 33)
            CurrentButton = GreenButton;
        else if (newValue <= 66)
            CurrentButton = BlueButton;
        else
            CurrentButton = RedButton;
        update();
    }
private:
    QPixmap GreenButton, BlueButton, RedButton, CurrentButton;
};

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 250);

    ImageButton* circle = new ImageButton(&window);
    QSlider* slider = new QSlider(Qt::Horizontal, &window);
    slider->setRange(0, 100);

    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->addWidget(circle, 0, Qt::AlignCenter);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, circle, [circle](int newValue) {
        circle->updateColor(newValue);
    });

    window.show();
    return app.exec();
}
