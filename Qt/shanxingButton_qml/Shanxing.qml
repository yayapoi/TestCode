import QtQuick 2.15
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.12
import QtQuick.Shapes 1.15

Item {
    property int marginInt: 4
    id: sectorButton
    width: parent.width * 0.5
    height: width

    Shape {
        id: buttonShape
        anchors.fill: parent
        //只有FillContains才会逐个路径判断
        //默认是BoundingRectContains根据矩形区域判断
        containsMode: Shape.FillContains
        layer.enabled: true
        layer.samples: 16

        ShapePath {
            id:buttonPath
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.RoundJoin
            strokeWidth: 2
            strokeColor: mouse_area.containsMouse ? "#2A2B3B" : "#2A2B3B"
            fillColor: mouse_area.containsMouse ?"#4E5366" :"#FFFFFF"
            startX: marginInt
            startY: buttonShape.height-marginInt
            PathArc {
                x: buttonShape.width-marginInt
                y: marginInt
                radiusX: buttonShape.width
                radiusY: buttonShape.height
            }
            PathLine {
                x: buttonShape.width-marginInt
                y: buttonShape.height/2-marginInt
            }
            PathArc {
                x: buttonShape.width/2-marginInt
                y: buttonShape.height-marginInt
                radiusX: (buttonShape.width)/2
                radiusY: (buttonShape.height)/2
                direction: PathArc.Counterclockwise
            }
            PathLine {
                x: marginInt
                y: buttonShape.height-marginInt
            }
        }
    }

    MouseArea {
        id: mouse_area
        anchors.fill: parent
        containmentMask: buttonShape
        hoverEnabled: true
        onClicked: {
            console.log('click',mouseX,mouseY)
        }
    }
}
/*Item
{
    property int marginInt: 4
    id: sectorButton
    width: parent.width * 0.5
    height: width
    Canvas
    {
        anchors.fill: parent
        onPaint:
        {
            var ctx = getContext("2d");
            ctx.lineWidth = 2;
            ctx.strokeStyle = "#18aad9";
            ctx.moveTo(marginInt,height-marginInt);
            ctx.arc(width-marginInt, height-marginInt, width-marginInt*2, -Math.PI/180 * 180,-Math.PI/180 * 90,false);
            ctx.lineTo(width-marginInt,height/2-marginInt);
            ctx.arc(width-marginInt, height-marginInt, width * 0.5, -Math.PI/180 * 90,-Math.PI/180 * 180,true);
            ctx.lineTo(marginInt,height-marginInt);
            ctx.stroke();
        }
        Item
        {
            anchors.fill: parent
            opacity: 0.4
            MouseArea
            {
                id:sectorButtonArea
                anchors.fill: parent
            }
            Rectangle{
                id:sectorButtonBackgourd
                visible: false
                anchors.fill: parent
                radius: 4
                color: sectorButtonArea.pressed ? "#215d95":"transparent"
            }

            Canvas
            {
                id:sectorButtonMask
                anchors.fill: parent
                visible: false
                //anchors.bottom: parent.bottom
                onPaint:
                {
                    var ctx = getContext("2d");
                    ctx.lineWidth = 2;
                    ctx.strokeStyle = "#18aad9";
                    ctx.moveTo(marginInt,height-marginInt);
                    ctx.arc(width-marginInt, height-marginInt, width-marginInt*2, -Math.PI/180 * 180,-Math.PI/180 * 90,false);
                    ctx.lineTo(width-marginInt,height/2-marginInt);
                    ctx.arc(width-marginInt, height-marginInt, width * 0.5, -Math.PI/180 * 90,-Math.PI/180 * 180,true);
                    ctx.lineTo(marginInt,height-marginInt);
                    ctx.stroke();
                    ctx.fill();
                }
            }
            OpacityMask
            {
                anchors.fill: parent
                source: sectorButtonBackgourd
                maskSource: sectorButtonMask
            }
        }
    }
}*/
