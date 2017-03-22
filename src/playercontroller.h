#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>

#include "mpvobject.h"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PlayerState playerState READ playerState)
    Q_PROPERTY(bool autoplay READ isAutoplay)
    Q_PROPERTY(bool repeat READ isRepeat)

public:
    enum PlayerState {
        Stopped,
        Playing,
        Paused,
        Unloaded
    };
    Q_ENUM(PlayerState)

private:
    MpvObject* m_playerObject;

    PlayerState m_playerState;

    bool m_autoplay;
    bool m_repeat;

public:
    explicit PlayerController(MpvObject* object, QObject *parent = 0);

    PlayerState playerState();
    bool isAutoplay();
    bool isRepeat();

    Q_INVOKABLE void openFiles();
    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void next();
    Q_INVOKABLE void previous();
    Q_INVOKABLE void ffw();
    Q_INVOKABLE void rwd();
    Q_INVOKABLE void seek(int amount);

signals:

public slots:
};

#endif // PLAYERCONTROLLER_H
