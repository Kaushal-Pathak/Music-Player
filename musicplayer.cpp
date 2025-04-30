#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(QWidget *parent) : QWidget(parent) {
    mediaPlayer = new QMediaPlayer(this);
    songList = new QListWidget(this);
    addButton = new QPushButton("Add Song", this);
    playButton = new QPushButton("Play", this);
    stopButton = new QPushButton("Stop", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(songList);
    layout->addWidget(addButton);
    layout->addWidget(playButton);
    layout->addWidget(stopButton);

    setLayout(layout);

    connect(addButton, &QPushButton::clicked, this, &MusicPlayer::addSong);
    connect(playButton, &QPushButton::clicked, this, &MusicPlayer::playSong);
    connect(stopButton, &QPushButton::clicked, this, &MusicPlayer::stopSong);
}

MusicPlayer::~MusicPlayer() {
    delete mediaPlayer;
}

void MusicPlayer::addSong() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Music File", "", "Audio Files (*.mp3 *.wav)");
    if (!fileName.isEmpty()) {
        songList->addItem(fileName);
    }
}

void MusicPlayer::playSong() {
    if (songList->currentItem()) {
        mediaPlayer->setMedia(QUrl::fromLocalFile(songList->currentItem()->text()));
        mediaPlayer->play();
    }
}

void MusicPlayer::stopSong() {
    mediaPlayer->stop();
}
