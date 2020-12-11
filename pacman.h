#ifndef PACMAN_H
#define PACMAN_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class pacman : public QObject,public QGraphicsItem
{
    Q_OBJECT
    int posx,posy;
    int velocidad=3;
public:
    pacman(int posx_,int pos_y);
//    explicit pacman(QObject *parent = nullptr);

    QTimer * timer;

    QPixmap * pixmap;

    float filas, columnas;
    float ancho, alto;
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=nullptr);
    void up();
    void down();
    void left();
    void right();



signals:

public slots:
    void Actualizacion();


};

#endif // PACMAN_H
