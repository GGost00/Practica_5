#include "pacman.h"
int pacman::getPosx() const
{
    return posx;
}

void pacman::setPosx(int value)
{
    posx = value;
}

int pacman::getPosy() const
{
    return posy;
}

void pacman::setPosy(int value)
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

pacman::pacman(int x, int y)
{
    posx=x;
    posy=y;
    setPos(posx,posy);
    timer= new QTimer();
    filas=0;
    columnas=0;

    pixmap = new QPixmap(":/images/pac.png");
    setScale(0.22);
    ancho=100;
    alto=100;
    timer->start(33);


    connect(timer,&QTimer::timeout,this,&pacman::Actualizacion);


}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void pacman::up()
{
Actualizacion();
setRotation(270);
posy -= 2*velocidad;
    setPos(posx,posy);

}

void pacman::down()
{
Actualizacion();
setRotation(90);
posy += 2*velocidad;
    setPos(posx,posy);

}

void pacman::left()
{
Actualizacion();
setRotation(180);
posx -= 2*velocidad;
    setPos(posx,posy);

}

void pacman::right()
{
Actualizacion();
setRotation(0);

posx += 2*velocidad;
    setPos(posx,posy);

}

void pacman::Actualizacion()
{

 columnas+=100;
 if(columnas>=900){columnas=0;}
 this->update(-ancho/2,-alto/2,ancho,alto);

}
