#include "moneda.h"

int moneda::getPosx() const
{
    return posx;
}

void moneda::setPosx(int value)
{
    posx = value;
}

int moneda::getPosy() const
{
    return posy;
}

void moneda::setPosy(int value)
{
    posy = value;
}

//pacman::pacman(QObject *parent) : QObject(parent)
//{
//    timer= new QTimer();
//    filas=0;
//    columnas=0;

//    pixmap = new QPixmap(":/images/pac.png");
//    ancho=100;
//    alto=100;
//    timer->start(33);


//    connect(timer,&QTimer::timeout,this,&pacman::Actualizacion);


//}

moneda::moneda(int x, int y)
{
    posx=x;
    posy=y;
    setPos(posx,posy);
    filas=0;
    columnas=0;

    pixmap = new QPixmap(":/images/moneda.png");

    ancho=10;
    alto=10;


}

QRectF moneda::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}



