#ifndef HUMBUGWEBBRIDGE_H
#define HUMBUGWEBBRIDGE_H

#include <QObject>
#include <QWebView>
#include <QVariant>
#include "HumbugTrayIcon.h"

class HumbugWebBridge : public QObject
{
    Q_OBJECT
public:
    explicit HumbugWebBridge(QObject *parent = 0);

public slots:
    QVariantMap systemInfo();
    void notify(const QVariant &msg);
    void updateCount(int count);
    int getCount();

private:
    QWebView *m_webView;
    HumbugTrayIcon *m_trayIcon;
    int m_unreadCount;

signals:
    void countUpdated(int current, int previous);
    void notificationRequested(QString* title, QString* content);

};

#endif // HUMBUGWEBBRIDGE_H
