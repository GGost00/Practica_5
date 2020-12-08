#ifndef MONEDA_H
#define MONEDA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class moneda : public QObject,public QGraphicsItem
{
    Q_OBJECT
    int posx,posy;
    int velocidad=3;
public:
    moneda(int posx_,int pos_y);
//    explicit pacman(QObject *parent = nullptr);


    QPixmap * pixmap;

    float filas, columnas;
    float ancho, alto;
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=nullptr);


signals:

public slots:



};


#endif // MONEDA_H
