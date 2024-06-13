import QtQuick 2.0
import QtQml 2.12
import QtQuick.Window 2.12

Window {
    id: rootWin
    width: 1000
    height: 1000
    color: "blue"
    visible: false

    // 创建一个背景为绿色的窗口
    Rectangle {
        id: background
        anchors.fill:parent
        color: "green"
    }

    // 创建一个loader对象，包含了两种动画，一个是进入，一个退出
    Loader {
        id: loader
        NumberAnimation {
            id: showMask
            target: loader.item  // 动画指定的对象是一个loader的item
            property: "x"
            duration: 1000
            from: -rootWin.width
            to: 0
            easing.type: Easing.InExpo
        }

        NumberAnimation {
            id: hideMask
            target: loader.item
            property: "x"
            duration: 1000
            from: 0
            to: rootWin.width
            easing.type: Easing.InExpo
        }
    }

    // 显示的时候加载qml，并且设置进入动画为true
    function show() {
        rootWin.visible = true;
        loader.source = "MaskWin.qml"
        showMask.running = true
    }
    // 退出的时候，将退出动画设置为true
    function hide() {
        hideMask.running = true;
    }
}

