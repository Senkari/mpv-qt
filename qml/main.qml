import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1 as QQC2
import Qt.labs.platform 1.0

import com.mpvqt.mpv 1.0

Window {
    id: mainWindow;
    visible: true;
    width: 640;
    height: 480;
    title: qsTr("mpv-qt");

    MpvObject {
        id: renderer;
        z: -1;
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

    Rectangle {
        id: controls;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: parent.height / 10;
        height: 200;
        width: 400;
        radius: 10;
        color: Qt.rgba(0.0, 0.0, 0.0, 0.5);
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
}
