#ifndef HTTPREQUEST_H_INCLUDED
#define HTTPREQUEST_H_INCLUDED

#include <string>

class HTTPRequest
{

public:
    HTTPRequest()
        : ip(), logName(), authName(), dateTime(), method(), document(), httpVersion(),
          httpCode(), contentLength(), referer(), userAgent()
    {}
    HTTPRequest(const HTTPRequest & aHTTPRequest) = default;
    HTTPRequest & operator = (const HTTPRequest & aHTTPRequest) = default;
    virtual ~HTTPRequest() = default;

    friend std::istream& operator >> (std::istream& is, HTTPRequest& r);

    inline std::string IP() const { return ip; }
    inline std::string LogName() const { return logName; }
    inline std::string AuthName() const { return authName; }
    inline std::string DateTime() const { return dateTime; }
    inline std::string Method() const { return method; }
    inline std::string Document() const { return document; }
    inline std::string HTTPVersion() const { return httpVersion; }
    inline uint32_t HTTPCode() const { return httpCode; }
    inline std::string ContentLength() const { return contentLength; }
    inline std::string Referer() const { return referer; }
    inline std::string UserAgent() const { return userAgent; }

protected:
    std::string ip;
    std::string logName;
    std::string authName;
    std::string dateTime;
    std::string method;
    std::string document;
    std::string httpVersion;
    std::uint32_t httpCode;
    std::string contentLength;
    std::string referer;
    std::string userAgent;
};

#endif // HTTPREQUEST_H_INCLUDED
