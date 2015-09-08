#include "gamewindow.h"

#include <QPainter>

GameWindow::GameWindow(QWindow *parent) :
    QOpenGLWindow(NoPartialUpdate, parent),
    background_offset(0.f, 0.f)
{
    Q_INIT_RESOURCE(images);

    setCursor(Qt::BlankCursor);

    background_animation = new QPropertyAnimation(this, "background_offset");
    background_animation->setDuration(10000);
    background_animation->setStartValue(QPointF(0, 0));
    background_animation->setEndValue(QPointF(300, 299));



    background.load(":/images/background");
    hillary.load(":/images/hillary");
    email.load(":/images/email");
}

GameWindow::~GameWindow()
{
}

void GameWindow::setBackgroundOffset(QPointF offset)
{
    background_offset = offset;
}

void GameWindow::start()
{
    start_animation();
}

void GameWindow::start_animation()
{
    background_animation->start();
    connect(background_animation, &QPropertyAnimation::finished, this, &GameWindow::start_animation);
}

void GameWindow::update_player()
{
    player_position = this->mapFromGlobal(QCursor::pos());
}

void GameWindow::update_emails()
{
    for( int i = 0; i < emails.size(); i++ ) {
        if (emails[i].y() <= 800 ) {
            emails[i].setY(emails[i].y() + 10.0);
        } else {
            emails.remove(i);
        }
    }
}

void GameWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    update_player();
    update_emails();

    QPainter painter(this);

    painter.drawTiledPixmap(QRectF(0.0, 0.0, width(), height()), background, background_offset);

    painter.drawPixmap(player_position, hillary);

    for( int i = 0; i < emails.size(); i++ ) {
        painter.drawPixmap(emails[i], email);
    }

    emails.append(QPoint(qrand() % 800, 0));

    update();
}
