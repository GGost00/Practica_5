#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect Desktop =QApplication::desktop()->screenGeometry();
    x=Desktop.x();
    y=Desktop.y();
    ancho=398;
    alto=497;

    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setBackgroundBrush(QPixmap(":/images/map.png"));


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(420,655);
    scene->addPixmap(QPixmap(":/images/map.png"));
    scene->setSceneRect(0,0,398,497);




    personaje= new pacman(ancho/2,alto/2);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    //personaje->setPos(680,340);


    monedas.push_back(new moneda(302,283));scene->addItem(monedas.back());
    monedas.push_back(new moneda(210,230));scene->addItem(monedas.back());
}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
 if(evento->key() == Qt::Key_A){
     personaje->left();
     for(int i=0;i<monedas.size();i++){
         if(personaje->collidesWithItem(monedas.at(i))){
             scene->removeItem(monedas.at(i));
             monedas= eliminarMoneda(monedas,i);
         }
     }

 }
 if(evento->key() == Qt::Key_D){
     personaje->right();
     for(int i=0;i<monedas.size();i++){
         if(personaje->collidesWithItem(monedas.at(i))){
             scene->removeItem(monedas.at(i));
             monedas= eliminarMoneda(monedas,i);
         }
     }

 }
 if(evento->key() == Qt::Key_W){
     personaje->up();
     for(int i=0;i<monedas.size();i++){
         if(personaje->collidesWithItem(monedas.at(i))){
             scene->removeItem(monedas.at(i));
             monedas= eliminarMoneda(monedas,i);
         }
     }
 }
 if(evento->key() == Qt::Key_S){
     personaje->down();
     for(int i=0;i<monedas.size();i++){
         if(personaje->collidesWithItem(monedas.at(i))){
             scene->removeItem(monedas.at(i));
             monedas= eliminarMoneda(monedas,i);
         }
     }
 }
}

QList<moneda *> MainWindow::eliminarMoneda(QList<moneda *> monedas, int pos)
{
    QList<moneda *> aux;
    for (int i; i<monedas.size() ;i++ ) {
        if(i!=pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
}
MainWindow::~MainWindow()
{
    delete ui;
}
