#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDesktopWidget>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QWidget>
#include "pacman.h"
#include "moneda.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<moneda *> monedas;

private slots:
    void on_label_3_linkHovered(const QString &link);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    pacman *personaje;
    void keyPressEvent(QKeyEvent * evento);
    QList<moneda *> eliminarMoneda(QList<moneda *> monedas,int pos);
    float x,y,ancho,alto;
};
#endif // MAINWINDOW_H
