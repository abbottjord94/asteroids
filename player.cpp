#include "player.h"
#include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>

Player::Player()
{
    //xpos = 0;
    //ypos = 0;
    //angle = 0;
    //setRotation(angle);
    //setPos(50,50);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT (move()));
    timer->start(33.33);
}

Player::~Player() {

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::SolidPattern);
    painter->drawLine(0,0,18,0);
    painter->drawLine(0,0,9,-25);
    painter->drawLine(18,0,9,-25);
}

void Player::keyPressEvent(QKeyEvent *event) {

    //qDebug() << "pressed a key";

    //this can read a key from key board to move the player
    if (event->key()== Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key()== Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key()== Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key()== Qt::Key_Down){
        setPos(x(),y()+10);
    }
}

void Player::move() {
   // ypos += 1;
    //setPos(xpos, ypos);

}

QRectF Player::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}

