import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    id:maskWin
    color: Qt.rgba(0.2,0.2,0.2,0.8)
    width: 1000
    height: 1000
    z: 100
    MouseArea {
        anchors.fill: parent
    }

    Rectangle {
        id:showWin
        visible: true
        width: parent.width/2
        height: parent.height/2
        x: (parent.width - width)/2
        y: (parent.height - height)/2
        color: "white"
        radius: 10
    }

    Rectangle {
        id:exitIcon
        anchors.right: showWin.right
        anchors.bottom: showWin.top
        anchors.bottomMargin: 20
        width: 40
        height: 40
        radius: width/2
        border.color: "white"
        border.width: 1
        color: "transparent"

        Text {
            id: cancel
            text: qsTr("X")
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
            color: "white"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                maskWin.visible = false;
            }
        }
    }
}

