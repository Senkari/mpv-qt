#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>

#include "mpvobject.h"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playing READ isPlaying)
    Q_PROPERTY(bool autoplay READ isAutoplay)
    Q_PROPERTY(bool repeat READ isRepeat)
private:
    MpvObject* m_playerObject;

    bool m_playing;
    bool m_autoplay;
    bool m_repeat;

public:
    explicit PlayerController(MpvObject* object, QObject *parent = 0);

    bool isPlaying();
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


signals:

public slots:
};

#endif // PLAYERCONTROLLER_H
