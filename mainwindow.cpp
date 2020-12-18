#include "mainwindow.h"
#include "ui_mainwindow.h"

int Puntaje=0;
int movimientos;
int dificult=1;
int total=0;
int vidas=3;
QTimer *timer;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    timer=new QTimer(this);
    timer->setInterval(1000);

    nuevojuego();


}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(Puntaje==total){
        dificult+=1;

        ui->dificultad->setText(QString::number(dificult));
        timer->disconnect();
        nuevojuego();
    }

    ui->tiempo->setText(QString::number(movimientos));
    QMediaPlayer *music2 =new QMediaPlayer();
    music2->setMedia(QUrl("qrc:/sounds/mario-coin.mp3"));

    if(evento->key() == Qt::Key_A){
        personaje->left();
        if(220<personaje->getPosy()<240 &&personaje->getPosx()<0){
            personaje->setPosx(400);
        }
        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
                music2->play();
                Puntaje+=1;

                movimientos=tiempo(dificult);
                ui->puntaje->setText(QString::number(Puntaje));

            }
        }
        for(int i=0;i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->right();
            }
        }


    }
    if(evento->key() == Qt::Key_D){
        personaje->right();
        if(220<personaje->getPosy()<240 &&personaje->getPosx()>400){
            personaje->setPosx(0);
        }
        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
                music2->play();
                Puntaje+=1;

                movimientos=tiempo(dificult);
                ui->puntaje->setText(QString::number(Puntaje));

            }
        }
        for(int i=0;i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->left();
            }
        }


    }
    if(evento->key() == Qt::Key_W){
        personaje->up();
        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
                music2->play();
                Puntaje+=1;

                movimientos=tiempo(dificult);
                ui->puntaje->setText(QString::number(Puntaje));

            }
        }
        for(int i=0;i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->down();
            }
        }

    }
    if(evento->key() == Qt::Key_S){
        personaje->down();
        for(int i=0;i<monedas.size();i++){
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                monedas= eliminarMoneda(monedas,i);
                music2->play();
                Puntaje+=1;

                movimientos=tiempo(dificult);
                ui->puntaje->setText(QString::number(Puntaje));

            }
        }
        for(int i=0;i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->up();
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

int MainWindow::tiempo(int x)
{
    switch(x){
    case 1:
        return 90;
    case 2:
        return 60;
    case 3:
        return 50;
    case 4:
        return 40;
    case 5:
        return 35;
    case 6:
        return 30;
    case 7:
        return 25;
    case 8:
        return 20;
    case 9:
        return 15;
    case 10:
        return 10;
    default:
        return 5;
    }

}

void MainWindow::nuevojuego()
{
    ifstream Leer;
    int ancho1,alto1,posix,posiy,posjx,posjy;
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
    timer->start();

    movimientos=tiempo(dificult);
    ui->setupUi(this);
    ui->dificultad->setText(QString::number(dificult));
    ui->puntaje->setText(QString::number(Puntaje));
    ui->vidas->setText(QString::number(vidas));
    ui->tiempo->setText(QString::number(movimientos));
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
    setFixedSize(420,700);
    scene->addPixmap(QPixmap(":/images/map.png"));
    scene->setSceneRect(0,0,398,497);

    personaje= new pacman(ancho/2,(alto/2)+32);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    scene->addItem(personaje);
    //personaje->setPos(680,340);
    //agregar funcion que lea paredes.txt y agrege las paredes en la escena

    Leer.open("/Users/Gabriel Restrepo/Documents/practica_5/coords.txt");
    char linea[20];
    Leer.getline(linea, sizeof(linea));
    while (!Leer.eof()) {
        for(int i=0; i<4;i++){
            char *puntero;
            if(i==0){
                puntero = strtok(linea, ",");
                ancho1 = atoi(puntero);
            }
            if(i==1){
                puntero = strtok(NULL, ",");
                alto1 = atoi(puntero);
            }
            if(i==2){
                puntero = strtok(NULL, ",");
                posix = atoi(puntero);
            }
            if(i==3){
                puntero = strtok(NULL, ",");
                posiy = atoi(puntero);
            }
        }
        paredes.push_back(new pared (ancho1,alto1,posix,posiy));
        scene->addItem(paredes.back());
        Leer.getline(linea, sizeof(linea));
    }
    Leer.close();
    //    for (int i=30;i<500 ;i+=30 ) {
    //        for (int j=30;j<400 ;j+=30) {
    //             monedas.push_back(new moneda(j,i));scene->addItem(monedas.back());
    //        }
    //    }
    //    for(int j=0;j<paredes.size();j++){
    //        for(int i=0;i<monedas.size();i++){
    //            if(monedas.at(i)->collidesWithItem(paredes.at(j))){
    //                scene->removeItem(monedas.at(i));
    //                monedas= eliminarMoneda(monedas,i);

    //            }
    //        }
    //    }

    Leer.open("/Users/Gabriel Restrepo/Documents/practica_5/money.txt");
    char line[20];
    Leer.getline(line, sizeof(line));
    while (!Leer.eof()) {
        for(int i=0; i<2;i++){
            char *puntero;
            if(i==0){
                puntero = strtok(line, ",");
                posjx = atoi(puntero);
            }
            if(i==1){
                puntero = strtok(NULL, ",");
                posjy = atoi(puntero);
            }
        }
        monedas.push_back(new moneda (posjx,posjy));

        scene->addItem(monedas.back());
        Leer.getline(line, sizeof(line));
    }
    Leer.close();
    total+=138;
    QMediaPlayer *music1 =new QMediaPlayer();
    music1->setMedia(QUrl("qrc:/sounds/pacman-song.mp3"));
    _sleep(2000);
    music1->play();

}

void MainWindow::timer_timeout()
{
    movimientos--;
    ui->tiempo->setText(QString::number(movimientos));
    if(movimientos<=0){
        vidas-=1;
        movimientos=tiempo(dificult);
        scene->removeItem(personaje);
        personaje= new pacman(199,280);
        personaje->setFlag(QGraphicsItem::ItemIsFocusable);
        personaje->setFocus();
        scene->addItem(personaje);
        if(vidas==0){
            dificult=1;
            Puntaje=0;
            vidas=3;
            timer->disconnect();
            nuevojuego();

        }
        ui->vidas->setText(QString::number(vidas));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


