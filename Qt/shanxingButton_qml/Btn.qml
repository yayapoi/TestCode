import QtQuick 2.12

Rectangle {
    property bool repeatFlag: false
    property color textColor: Qt.darker("#56A420", 1)
    property color backgroundColor: "#004597"

    radius: 10
    color: backgroundColor

    Text {
        id: label
        anchors.centerIn: parent
        font.pixelSize: 30
        color: textColor
        text: !repeatFlag ? "Show" :"Hide"
        font.bold: true
    }
}

