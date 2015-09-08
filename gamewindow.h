#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QOpenGLWindow>
#include <QPropertyAnimation>
#include <QPointF>

class GameWindow : public QOpenGLWindow
{
    Q_OBJECT
    Q_PROPERTY(QPointF background_offset MEMBER background_offset WRITE setBackgroundOffset)

public:
    explicit GameWindow(QWindow *parent = 0);
    ~GameWindow();

    void setBackgroundOffset(QPointF offset);
    void start();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap background;
    QPixmap hillary;
    QPixmap email;

    QPropertyAnimation *background_animation;
    QPointF background_offset;

    QPointF player_position;

    QVector<QPointF> emails;

    void start_animation();
    void update_player();
    void update_emails();
};

#endif // GAMEWINDOW_H
