#ifndef HTTPREQUEST_H_INCLUDED
#define HTTPREQUEST_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class HTTPRequest
{

public:
    HTTPRequest(string anIP = "", string aLogName = "", string anAuthName = "",
            string aDateTime = "", string aMethod = "", string aDocument = "",
            string aHTTPVersion = "", uint32_t aHTTPCode = -1, uint64_t aContentLength = -1,
            string aReferer = "", string aUserAgent = "")
        : ip(anIP), logName(aLogName), authName(anAuthName), dateTime(aDateTime),
          method(aMethod), document(aDocument), httpVersion(aHTTPVersion),
          httpCode(aHTTPCode), contentLength(aContentLength), referer(aReferer),
          userAgent(aUserAgent)
    {}
    HTTPRequest(const HTTPRequest & aHTTPRequest);
    virtual ~HTTPRequest() {}
    HTTPRequest & operator = (const HTTPRequest & aHTTPRequest);

    friend istream& operator >> (istream& is, HTTPRequest& r);

    inline string IP() const { return ip; }
    inline string LogName() const { return logName; }
    inline string AuthName() const { return authName; }
    inline string DateTime() const { return dateTime; }
    inline string Method() const { return method; }
    inline string Document() const { return document; }
    inline string HTTPVersion() const { return httpVersion; }
    inline uint32_t HTTPCode() const { return httpCode; }
    inline uint64_t ContentLength() const { return contentLength; }
    inline string Referer() const { return referer; }
    inline string UserAgent() const { return userAgent; }

protected:
    string ip;
    string logName;
    string authName;
    string dateTime;
    string method;
    string document;
    string httpVersion;
    uint32_t httpCode;
    uint64_t contentLength;
    string referer;
    string userAgent;
};

#endif // HTTPREQUEST_H_INCLUDED
