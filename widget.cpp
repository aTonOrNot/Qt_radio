#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer(this);          // Initialize the player


    m_player->setVolume(70);                    // Set the volume for playing tracks
    ui->volumedial->setValue(70);


    // connect the control buttons to the control slots
    connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
    connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_volumedial_valueChanged(int value)
{
    m_player->setVolume(value);//adjust player volume
    QString vol = QString::number(value);//convert volume value integer to string
    ui->volumeLabel->setText("Volume : "+vol+"%");//display current volume
}

void Widget::on_kissButton_clicked()
{
    m_player->stop();//stop current playback
    m_player->setMedia(QUrl("https://rusradio.hostingradio.ru/rusradio128.mp3"));//set new stream url
    m_player->play();//start playing selected channel
    ui->statuslabel->setText("Now Playing : Kiss FM");//
}

void Widget::on_rathumakaraButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("http://nashe1.hostingradio.ru/nashe-64.mp3"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : RathuMakara FM");
}


void Widget::on_siyathaButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("https://dorognoe.hostingradio.ru/radio"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Siyatha FM");
}

void Widget::on_nethButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("http://69.46.24.226:7669/stream"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Neth FM");
}

void Widget::on_rhythmworldButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("http://live.tnlrn.com:8030/live.mp3"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Rhythm World");
}

void Widget::on_lakhandaButton_clicked()
{
    m_player->stop();
    m_player->setMedia(QUrl("https://e17-2c0-402gv.stream-balancer-allo-1.live/M2/0/1/1767821377/T7dCaVQ1yirLsq2tI6rnTg/4/480/1/1160266/master.m3u8"));
    m_player->play();
    ui->statuslabel->setText("Now Playing : Lakhanda");
}
