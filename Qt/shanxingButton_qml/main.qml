import QtQuick 2.15
import QtQuick.Window 2.15
import ImageMaskItem 1.0

Window {
    width: 600
    height: 600
    visible: true
    title: qsTr("Hello World")



//3、功能设计思路
//1、做一个按钮，用来触发窗口切换
//2、创建一个掩码窗口，最终生成一个qml文件
//3、创建一个Loader, Loader中添加两种动画，一个是进入，一个是出去。
//4、Loader指定qml，触发动画。


    /*Btn {
        id: loadBtn
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 30
        width: 100
        height: 100
        radius: 10
        MouseArea {
            anchors.fill: parent
            onClicked: {
                loadBtn.repeatFlag = !loadBtn.repeatFlag
                if (loadBtn.repeatFlag) {
                    loaderS.show();
                } else {
                    loaderS.hide();
                }
            }
        }
    }

    LoaderSturdy {
        id: loaderS
    }*/

    Item {
            id:buttonAngle
            width: parent.width * 0.5
            height: width
            anchors.centerIn: parent
            Image{
                width: 52
                height: 52
                id: centerImg
                source: "qrc:/center.png"
                anchors.centerIn: parent
            }

            Image {
                id: imgUp
                width: 92
                height: 44
                anchors.horizontalCenter: centerImg.horizontalCenter
                anchors.bottom: centerImg.top
                source: "qrc:/img.png"
                MouseArea {
                    anchors.fill: parent
                    containmentMask: maskUp
                    ImageMaskItem {
                        id: maskUp
                        anchors.fill: parent
                        maskSource: imgUp.source
                        alphaThreshold: 0.1
                    }
                    onClicked: console.log('click up')
                }
            }
            Image {
                id: imgDown
                width: 92
                height: 44
                anchors.horizontalCenter: centerImg.horizontalCenter
                anchors.top: centerImg.bottom
                source: "qrc:/down.png"
                MouseArea {
                    anchors.fill: parent
                    containmentMask: maskDown
                    ImageMaskItem {
                        id: maskDown
                        anchors.fill: parent
                        maskSource: imgDown.source
                        alphaThreshold: 0.1
                    }
                    onClicked: console.log('click down')
                }
            }
            Image {
                id: imgLeft
                width: 44
                height: 92
                anchors.verticalCenter: centerImg.verticalCenter
                anchors.right: centerImg.left
                source: "qrc:/left.png"
                MouseArea {
                    anchors.fill: parent
                    containmentMask: maskLeft
                    ImageMaskItem {
                        id: maskLeft
                        anchors.fill: parent
                        maskSource: imgLeft.source
                        alphaThreshold: 0.1
                    }
                    onClicked: console.log('click Left')
                }
            }
            Image {
                id: imgRight
                width: 44
                height: 92
                anchors.verticalCenter: centerImg.verticalCenter
                anchors.left: centerImg.right
                source: "qrc:/right.png"
                MouseArea {
                    anchors.fill: parent
                    containmentMask: maskRight
                    ImageMaskItem {
                        id: maskRight
                        anchors.fill: parent
                        maskSource: imgRight.source
                        alphaThreshold: 0.1
                    }
                    onClicked: console.log('click Right')
                }
            }
//            Rectangle
//            {
//                id:pingbiRect
//                width: parent.width * 0.5  //屏蔽中间的鼠标事件
//                height: width
//                radius:width /2
//                color:"blue"
//                anchors.centerIn: parent
//                opacity: 0.6
//                Text
//                {
//                    anchors.centerIn: parent
//                    text: "鼠标屏蔽区域"
//                }

//                MouseArea
//                {
//                    anchors.fill: parent
//                    onClicked:
//                    {

//                    }
//                }
//                transform: Rotation{
//                    origin.x: pingbiRect.width/2
//                    origin.y: pingbiRect.height/2
//                    angle: -45
//                }
//            }

//            transform: Rotation{
//                origin.x: buttonAngle.width/2
//                origin.y: buttonAngle.height/2
//                angle: 45
//            }
        }
    /*Item {
        id:buttonAngle
        width: parent.width * 0.5
        height: width
        anchors.centerIn: parent
        Shanxing{
            id:topButton
            anchors.left: parent.left
            anchors.top: parent.top
            z:100
        }
        Shanxing{
            id:rightButton
            anchors.right: parent.right
            anchors.top: parent.top
            z:100
            transform: Rotation{
                origin.x: rightButton.width/2
                origin.y: rightButton.height/2
                angle: 90
            }
        }
        Shanxing{
            id:leftButton
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            z:100
            transform: Rotation{
                origin.x: leftButton.width/2
                origin.y: leftButton.height/2
                angle: -90
            }
        }
        Shanxing{
            id:downButton
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            z:100
            transform: Rotation{
                origin.x: downButton.width/2
                origin.y: downButton.height/2
                angle: 180
            }
        }
        Rectangle
        {
            id:pingbiRect
            width: parent.width * 0.5  //屏蔽中间的鼠标事件
            height: width
            radius:width /2
            color:"blue"
            anchors.centerIn: parent
            opacity: 0.6
            Text
            {
                anchors.centerIn: parent
                text: "鼠标屏蔽区域"
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {

                }
            }
            transform: Rotation{
                origin.x: pingbiRect.width/2
                origin.y: pingbiRect.height/2
                angle: -45
            }
        }

        transform: Rotation{
            origin.x: buttonAngle.width/2
            origin.y: buttonAngle.height/2
            angle: 45
        }
    }*/
}
