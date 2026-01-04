#include "mainwindow.h"
#include "imagebutton.h"
#include <QApplication>
#include <iostream>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 250);
    window.setWindowTitle("Color Switcher 2026");

    ImageButton* circle = new ImageButton(&window);
    QSlider* slider = new QSlider(Qt::Horizontal, &window);
    slider->setRange(0, 99);

    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->addWidget(circle, 0, Qt::AlignCenter);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, circle, [circle](int newValue) {
        circle->updateColor(newValue);
    });

    window.show();
    return app.exec();
}
