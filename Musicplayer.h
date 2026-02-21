#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QFileDialog>
#include <QMediaPlayer>

class MusicPlayer : public QWidget {
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();

private slots:
    void addSong();
    void playSong();
    void stopSong();

private:
    QMediaPlayer *mediaPlayer;
    QListWidget *songList;
    QPushButton *addButton;
    QPushButton *playButton;
    QPushButton *stopButton;
};

#endif 
