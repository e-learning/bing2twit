#ifndef YATOTWIT_H
#define YATOTWIT_H

#include <QtGui/QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QImage>
#include <QXmlDefaultHandler>
#include <QXmlSimpleReader>
#include <QList>
#include <QLabel>

#include "YandexHelper.h"
#include "twittercli.h"

class YaToTwit : public QWidget
{
	Q_OBJECT

private:
    QVBoxLayout * mainLayout;
    QHBoxLayout * searchLayout;
    QHBoxLayout * selectLayout;

    QLineEdit * editSearch;
    QPushButton * pbSearch;
    QComboBox * comboResults;
    QPushButton * pbSelect;
    QImage * imageMap;
    QLabel * imgLabel;

    YandexHelper * yandex;

    TwitterCLI tAuth;

    struct GeoObject {
    	GeoObject(QString name = "", float latitude = 0, float longtitude = 0) : m_longtitude(longtitude), m_latitude(latitude), m_name(name) {}
    	float m_longtitude;
    	float m_latitude;
    	QString m_name;
    };

    QList<GeoObject> geoObjects;

    class XmlHandler : public QXmlDefaultHandler {
        public:
    		XmlHandler(QList<GeoObject> geoObjects) : m_geoObjects(geoObjects) {}
            bool endElement( const QString & namespaceURI, const QString & localName, const QString & qName );
            bool characters(const QString &str);

            QList<GeoObject> m_geoObjects;
            QString textElement;
    };

public:
    YaToTwit(QWidget *parent = 0);
    ~YaToTwit();

public slots:
	void oauthLogin();
	void activateSelect();
	void processData();
	void getImage();

private:
	void initGui();
};

#endif // YATOTWIT_H
