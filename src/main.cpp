#include <clocale>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mpvobject.h"
#include "playercontroller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::setlocale(LC_NUMERIC, "C");

    qmlRegisterType<MpvObject>("com.mpvqt.mpv", 1, 0, "MpvObject");
    qmlRegisterUncreatableType<PlayerController>("com.mpvqt.controller", 1, 0, "Controller", "PlayerController is defined as a ContextProperty.");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    PlayerController mainController(engine.rootObjects().at(0)->findChild<MpvObject*>("mpvRenderer"));
    engine.rootContext()->setContextProperty("PlayerController", &mainController);

    return app.exec();
}
