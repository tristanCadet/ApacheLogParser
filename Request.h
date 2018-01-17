#ifndef REQUEST_H_INCLUDED
#define REQUEST_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Request
{

public:
    Request(string anIP = "", string aLogName = "", string anAuthName = "",
            string aDateTime = "", string aMethod = "", string aDocument = "",
            string aHTTPVersion = "", uint32_t aHTTPCode = -1, uint64_t aContentLength = -1,
            string aReferer = "", string aUserAgent = "")
        : ip(anIP), logName(aLogName), authName(anAuthName), dateTime(aDateTime),
          method(aMethod), document(aDocument), httpVersion(aHTTPVersion),
          httpCode(aHTTPCode), contentLength(aContentLength), referer(aReferer),
          userAgent(aUserAgent)
    {}
    Request(const Request & aRequest);
    virtual ~Request() {}
    Request & operator = (const Request & aRequest);

    friend istream& operator >> (istream& is, Request& r);

    inline string IP() { return ip; }
    inline string LogName() { return logName; }
    inline string AuthName() { return authName; }
    inline string DateTime() { return dateTime; }
    inline string Method() { return method; }
    inline string Document() { return document; }
    inline string HTTPVersion() { return httpVersion; }
    inline uint32_t HTTPCode() { return httpCode; }
    inline uint64_t ContentLength() { return contentLength; }
    inline string Referer() { return referer; }
    inline string UserAgent() { return userAgent; }

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

#endif // REQUEST_H_INCLUDED
