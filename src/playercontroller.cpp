#include <QFileDialog>
#include <QStringList>
#include <QDebug>

#include "playercontroller.h"

PlayerController::PlayerController(MpvObject *object, QObject *parent)
    : QObject(parent)
    , m_playerObject(object)
    , m_playerState(PlayerState::Unloaded)
{

}

PlayerController::PlayerState PlayerController::playerState()
{
    return m_playerState;
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
    QStringList commands;
    commands << "loadfile";
    commands << file.toString();
    m_playerObject->command(QVariant(commands));
    m_playerState = PlayerController::Playing;
}

void PlayerController::play()
{
    if (m_playerState != PlayerController::Playing) {
        QStringList commands;
        commands << "cycle";
        commands << "pause";
        m_playerObject->command(QVariant(commands));
        m_playerState = PlayerController::Playing;
    }
}

void PlayerController::pause()
{
    if (m_playerState == PlayerController::Playing) {
        QStringList commands;
        commands << "cycle";
        commands << "pause";
        m_playerObject->command(QVariant(commands));
        m_playerState = PlayerController::Paused;
    }
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

void PlayerController::seek(int amount)
{
    QStringList commands;
    commands << "seek";
    commands << QString::number(amount);
    qDebug() << commands;
    m_playerObject->command(QVariant(commands));
}
