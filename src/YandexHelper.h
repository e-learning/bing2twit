/*
 * YandexHelper.h
 *
 *  Created on: 30.11.2011
 *      Author: renoire
 */

#ifndef YANDEXHELPER_H_
#define YANDEXHELPER_H_

#include <QString>
#include <curl/curl.h>
#include <iostream>

class YandexHelper {

public:
	YandexHelper() {}
	virtual ~YandexHelper();

	QString getLocation(QString &object);
	QString getMap(float lat, float lng);

private:

	QString get(const QString str);
	static size_t writeData( char *ptr, size_t size, size_t nmemb, std::string *outputBuffer);
};

#endif /* YANDEXHELPER_H_ */
