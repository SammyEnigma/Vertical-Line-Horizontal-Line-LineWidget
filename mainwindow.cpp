#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "LineWidget.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    auto hLine1 = new HorizontalLine();
//    hLine1->setBlended(true);
//    auto hLine2 = new HorizontalLine();
//    hLine2->setColor(QColor(Qt::red));

    auto hLine1 = new LineWidget(LineWidget::Horizontal);
    hLine1->setBlended(true);
    auto hLine2 = new LineWidget(LineWidget::Horizontal);
    hLine2->setColor(QColor(Qt::red));

//    auto vLine1 = new VerticalLine();
//    vLine1->setBlended(true);
//    auto vLine2 = new VerticalLine();
//    vLine2->setColor(QColor(Qt::green));
//    auto vLine3 = new VerticalLine();
//    vLine3->setBlended(true);

    auto vLine1 = new LineWidget(LineWidget::Vertical);
    vLine1->setBlended(true);
    auto vLine2 = new LineWidget(LineWidget::Vertical);
    vLine2->setColor(QColor(Qt::green));
    auto vLine3 = new LineWidget(LineWidget::Vertical);
    vLine3->setBlended(true);

    auto *mainLayout = new QVBoxLayout;
    auto *hBoxLayout = new QHBoxLayout;
    auto *vBoxLayout = new QVBoxLayout;

    mainLayout->addLayout(hBoxLayout);
    mainLayout->addLayout(vBoxLayout);

    hBoxLayout->addWidget(vLine1);
    hBoxLayout->addWidget(vLine2);
    hBoxLayout->addWidget(vLine3);

    vBoxLayout->addWidget(hLine1);
    vBoxLayout->addWidget(hLine2);

    auto *widget = new QWidget;
    widget->setLayout(mainLayout);

    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
