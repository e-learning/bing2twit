#include "yatotwit.h"
#include <iostream>
#include <QTextCodec>
#include <QObject>

void YaToTwit::initGui(){
	mainLayout = new QVBoxLayout();
	searchLayout = new QHBoxLayout();
	selectLayout = new QHBoxLayout();

	editSearch = new QLineEdit();
	pbSearch = new QPushButton("Search");
	comboResults = new QComboBox();
	pbSelect = new QPushButton("Select");
	imageMap = new QImage();
	imgLabel = new QLabel();

	comboResults->setEnabled(false);
	pbSelect->setEnabled(false);

	searchLayout->addWidget(editSearch);
	searchLayout->addWidget(pbSearch);

	selectLayout->addWidget(comboResults);
	selectLayout->addWidget(pbSelect);

	mainLayout->addItem(searchLayout);
	mainLayout->addItem(selectLayout);
	mainLayout->addWidget(imgLabel);

	QObject::connect(pbSearch, SIGNAL(clicked()), this, SLOT(activateSelect()));
	QObject::connect(pbSelect, SIGNAL(clicked()), this, SLOT(processData()));

	this->setLayout(mainLayout);
}

void YaToTwit::activateSelect(){
	QString s = editSearch->text().toUtf8().data();
	QString myXml = yandex->getLocation(s);

	QXmlSimpleReader reader;
	QXmlInputSource buf;
	buf.setData(myXml);

	geoObjects.clear();

	XmlHandler * xmlHandler = new XmlHandler(geoObjects);
    reader.setContentHandler(xmlHandler);

    reader.parse(&buf);

    comboResults->clear();

    geoObjects = xmlHandler->m_geoObjects;

    GeoObject obj;
    foreach (obj, xmlHandler->m_geoObjects){
    	QString str = QString::fromUtf8(obj.m_name.toStdString().c_str());
    	comboResults->addItem(str);
    }

    pbSelect->setEnabled(true);
    comboResults->setEnabled(true);

    delete xmlHandler;
}

bool YaToTwit::XmlHandler::characters(const QString &str){
	textElement = str;
	return true;
}

bool YaToTwit::XmlHandler::endElement( const QString & namespaceURI, const QString & localName, const QString & qName ){
	if(qName == "text") {
		m_geoObjects.append(GeoObject(textElement, 0, 0));

	}
	if(qName == "pos") {
		if(!m_geoObjects.isEmpty()){
			QStringList sl = textElement.split(" ");
			//GeoObject go = m_geoObjects.back();
			m_geoObjects.back().m_latitude = sl.value(0).toFloat();
			m_geoObjects.back().m_longtitude = sl.value(1).toFloat();
		}
	}
	return true;
}
void YaToTwit::oauthLogin(){
	tAuth.getAccess();
}

void YaToTwit::processData(){
	oauthLogin();
	tAuth.sendTweet(comboResults->currentText());

	getImage();
}

void YaToTwit::getImage(){
	GeoObject obj;

	foreach (obj, geoObjects){
	    QString str = QString::fromUtf8(obj.m_name.toStdString().c_str());
	    if(str == comboResults->currentText()){

	    	yandex->getMap(obj.m_latitude, obj.m_longtitude);
	    	imageMap->load("map.png");
	    	imgLabel->setPixmap(QPixmap::fromImage(*imageMap));
	    	break;
	    }
	}
}


YaToTwit::YaToTwit(QWidget *parent)
    : QWidget(parent)
{
	initGui();
	yandex = new YandexHelper();
}

YaToTwit::~YaToTwit()
{

}
