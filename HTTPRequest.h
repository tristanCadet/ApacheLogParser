#ifndef HTTPREQUEST_H_INCLUDED
#define HTTPREQUEST_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class HTTPRequest
{

public:
    HTTPRequest()
        : ip(), logName(), authName(), dateTime(), method(), document(), httpVersion(),
          httpCode(), contentLength(), referer(), userAgent()
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
