#!/usr/bin/env python3

from random import randint, choice
from datetime import datetime
from time import time
import string

methods = ["GET", "POST", "PROPFIND", "OPTIONS", "HEAD"]
pages = ["a", "A", "b", "B", "c", "C"]
exts = ["", ".html", ".php", ".bmp", ".png", ".jpg", ".jpeg", ".gif", ".svg", ".ico", ".css", ".js"]
codes = ["200", "206", "301", "302", "304", "401", "403", "404", "405", "500"]
domains = ["http://intranet-if.insa-lyon.fr", "http://intranet-if.insa-lyon.fr:90", "http://intranet-if", "http://intranet-if:90", "http://google.com", "https://google.com"]
userAgents = ["Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.84 Safari/537.36",
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:57.0) Gecko/20100101 Firefox/57.0",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_2) AppleWebKit/604.4.7 (KHTML, like Gecko) Version/11.0.2 Safari/604.4.7",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.84 Safari/537.36",
                "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:57.0) Gecko/20100101 Firefox/57.0",
                "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:57.0) Gecko/20100101 Firefox/57.0",
                "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.84 Safari/537.36",
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36 Edge/16.16299",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.13; rv:57.0) Gecko/20100101 Firefox/57.0",
                "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36",
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.108 Safari/537.36",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.84 Safari/537.36",
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36"]

def randomIP():
    ip = str(randint(0, 255))
    ip += "."
    ip += str(randint(0, 255))
    ip += "."
    ip += str(randint(0, 255))
    ip += "."
    ip += str(randint(0, 255))
    return ip


def randomDate():
    date = datetime.fromtimestamp(randint(0, int(time()))).strftime("[%d/%b/%Y:%H:%M:%S ")
    date += "+" if randint(0,1) else "-";
    date += "0"
    date += str(randint(0,9))
    date += "00]"
    return date

def randomURL():
    url = "/" + choice(pages)
    url += choice(exts)

    params = ["", "?", ";", "#", '&']
    param = randint(0, 3)
    if param:
        url += params[param] + "".join([choice(string.ascii_letters) for i in range(10)])

    return url

def randomRequest():
    request = "\""

    request += choice(methods)

    request += " "
    request += randomURL()

    request += " HTTP/1.1"
    request += "\""
    return request

def randomHTTPCode():
    return choice(codes)

def randomContentLength():
    return str(randint(0, 10000000)) if randint(0,1) else "-"

def randomReferer():
    return "\"" + choice(domains) + randomURL() + "\"" if randint(0,3) != 3 else "\"-\""

def randomUserAgent():
    return "\"" + choice(userAgents) + "\""

for i in range(10000):
    print(" ".join([randomIP(), "-", "-", randomDate(), randomRequest(), randomHTTPCode(), randomContentLength(), randomReferer(), randomUserAgent()]))
