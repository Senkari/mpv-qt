import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1 as QQC2
import Qt.labs.platform 1.0

import com.mpvqt.mpv 1.0
import com.mpvqt.controller 1.0

Window {
    id: mainWindow;
    property bool fullScreen: false;
    visible: true;
    visibility: Window.AutomaticVisibility;
    width: 840;
    height: 480;
    title: qsTr("mpv-qt");

    MpvObject {
        id: renderer;
        objectName: "mpvRenderer";
        anchors.fill: parent;
    }

    MouseArea {
        id: commandMouseArea;
        anchors.fill:parent;
        acceptedButtons: Qt.LeftButton | Qt.RightButton;

        onClicked: {
            if (mouse.button & Qt.RightButton) {
                contextMenu.open();
            }
        }
    }

    Item {
        id: unloadedMessage;
        visible: (PlayerController.playerState == Controller.Unloaded);
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        Image {
            id: playerLogo;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            width: Math.max(100, mainWindow.height / 4);
            height: Math.max(100, mainWindow.height / 4);
            source: "qrc:/data/images/logo.svg";
            sourceSize.width: 1000;
            sourceSize.height: 1000;
        }
        Text {
            id: loadMessage;
            anchors.top: playerLogo.bottom;
        }
    }

    Rectangle {
        id: controls;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: parent.height / 10;
        height: Math.max(parent.height / 8, 100);
        width: Math.max(parent.width / 2, 400);
        radius: Math.max(10);
        color: Qt.rgba(1.0, 0.0, 0.0, 0.5);
    }

    Menu {
        id: contextMenu;

        MenuItem {
            text: qsTr("Open file(s)...");
            shortcut: StandardKey.Open;
            onTriggered: {
                PlayerController.openFiles();
            }
        }

        MenuItem {
            text: qsTr("Quit");
            shortcut: StandardKey.Quit;
            onTriggered: Qt.quit();
        }
    }

    Shortcut {
        sequence: "Q";
        onActivated: Qt.quit();
    }

    Shortcut {
        sequence: "Left";
        onActivated: PlayerController.seek(-5);
    }

    Shortcut {
        sequence: "Right";
        onActivated: PlayerController.seek(5);
    }

    Shortcut {
        sequence: "Up";
        onActivated: PlayerController.seek(60);
    }

    Shortcut {
        sequence: "Down";
        onActivated: PlayerController.seek(-60);
    }

    Shortcut {
        sequence: "F";
        onActivated: {
            mainWindow.visibility = fullScreen ? Window.AutomaticVisibility : Window.FullScreen;
            mainWindow.fullScreen = !mainWindow.fullScreen;
        }
    }

    Shortcut {
        sequence: "Space";
        onActivated: {
            if (PlayerController.playerState != Controller.Unloaded) {
                PlayerController.playerState == Controller.Playing ? PlayerController.pause() : PlayerController.play();
            }
        }
    }
}
