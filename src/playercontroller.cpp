#include <QFileDialog>
#include <QStringList>
#include <QDebug>

#include "playercontroller.h"

PlayerController::PlayerController(MpvObject *object, QObject *parent)
    : QObject(parent)
    , m_playerObject(object)
{

}

bool PlayerController::isPlaying()
{
    return m_playing;
}

bool PlayerController::isAutoplay()
{
    return m_autoplay;
}

bool PlayerController::isRepeat()
{
    return m_repeat;
}

void PlayerController::openFiles()
{
    QUrl file = QFileDialog::getOpenFileUrl(nullptr, tr("Open file(s)..."), QString("/home"), tr("Matroska files (*.mkv)"));
    qDebug() << file;
    QStringList commands;
    commands << "loadfile";
    commands << file.toString();
    m_playerObject->command(QVariant(commands));
}

void PlayerController::play()
{

}

void PlayerController::pause()
{

}

void PlayerController::stop()
{

}

void PlayerController::next()
{

}

void PlayerController::previous()
{

}

void PlayerController::ffw()
{

}

void PlayerController::rwd()
{

}
