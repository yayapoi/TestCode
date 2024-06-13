#ifndef IMAGEMASKITEM_H
#define IMAGEMASKITEM_H

#include <QQmlEngine>
#include <QQuickItem>
#include <QImage>
#include <qqmlfile.h>

class ImageMaskItem : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QUrl maskSource READ maskSource WRITE setMaskSource NOTIFY maskSourceChanged)
    Q_PROPERTY(qreal alphaThreshold READ alphaThreshold WRITE setAlphaThreshold NOTIFY alphaThresholdChanged)
public:
    ImageMaskItem(QQuickItem *parent = nullptr);

    using QQuickItem::QQuickItem;

    bool contains(const QPointF &point) const override {
        if (!QQuickItem::contains(point) || m_maskImage.isNull())
            return false;

        QPoint p = point.toPoint();
        if (p.x() < 0 || p.x() >= m_maskImage.width() ||
            p.y() < 0 || p.y() >= m_maskImage.height())
            return false;

        qreal r = qBound<int>(0, m_alphaThreshold * 255, 255);
        return qAlpha(m_maskImage.pixel(p)) > r;
    }

    QUrl maskSource() const { return m_maskSource; }
    void setMaskSource(const QUrl &source) {
        if (m_maskSource != source) {
            m_maskSource = source;
            m_maskImage = QImage(QQmlFile::urlToLocalFileOrQrc(source));
            emit maskSourceChanged();
        }
    }

    qreal alphaThreshold() const { return m_alphaThreshold; }
    void setAlphaThreshold(qreal threshold) {
        if (m_alphaThreshold != threshold) {
            m_alphaThreshold = threshold;
            emit alphaThresholdChanged();
        }
    }

signals:
    void maskSourceChanged();
    void alphaThresholdChanged();

private:
    QUrl m_maskSource;
    QImage m_maskImage;
    qreal m_alphaThreshold{0.0f};
signals:

};

#endif // IMAGEMASKITEM_H
