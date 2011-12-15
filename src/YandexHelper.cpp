/*
 * YandexHelper.cpp
 *
 *  Created on: 30.11.2011
 *      Author: renoire
 */

#include "YandexHelper.h"


size_t YandexHelper::writeData( char *data, size_t size, size_t nmemb, std::string *outputBuffer){
	if (outputBuffer != NULL){
	     outputBuffer->append(data, size * nmemb);


	    	 FILE * pFile = fopen ("map.png" , "a");
	    	 fwrite (data , size , nmemb , pFile );
	    	 fclose (pFile);

	}
	return nmemb;
}

QString YandexHelper::getLocation(QString &object){
	object.replace(" ", "+");
	return get("http://geocode-maps.yandex.ru/1.x/?geocode=" + object + "&key=AFUErU4BAAAAtAbCNQMAfT5GKPsneqh7SGpxXzR9LT_XQfoAAAAAAAAAAAB7ZlYsxhCX1dY5oukeofQBDieS4g==");
	//Москва,+Тверская+улица,+дом+7
}

QString YandexHelper::getMap(float lat, float lng){
	return get("http://static-maps.yandex.ru/1.x/?ll=" + QString::number(lat) + "," +  QString::number(lng) + "&spn=0.016457,0.00619&l=map&key=AFUErU4BAAAAtAbCNQMAfT5GKPsneqh7SGpxXzR9LT_XQfoAAAAAAAAAAAB7ZlYsxhCX1dY5oukeofQBDieS4g==");
//	return get("http://static-maps.yandex.ru/1.x/?ll=37.677751,55.757718&spn=0.016457,0.00619&l=map&key=AFUErU4BAAAAtAbCNQMAfT5GKPsneqh7SGpxXzR9LT_XQfoAAAAAAAAAAAB7ZlYsxhCX1dY5oukeofQBDieS4g==");
//37.677751,55.757718
}

QString YandexHelper::get(const QString str){
	CURL *curl;
	CURLcode res;

	remove( "map.png" );
	QByteArray location = str.toAscii();

	curl = curl_easy_init();

	std::string outputBuffer = "";

	if(curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, location.data());
	  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
	  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outputBuffer);
	  res = curl_easy_perform(curl);

	  curl_easy_cleanup(curl);
	  return QString(outputBuffer.c_str());
	  //std::cout<<outputBuffer;
	}
}

YandexHelper::~YandexHelper() {
	// TODO Auto-generated destructor stub
}
