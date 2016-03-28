#-*- coding: utf-8 -*-
import cookielib
import urllib2
import re
import urllib
import json
from bs4 import BeautifulSoup


def save_to_file(data,filename):
    with open(filename.encode('utf-8'),'w') as f:
        f.write(data.encode('utf-8'))



def save_problems(opener,username):
    max_sid = lambda x,y: x if x[1] < y[1] else y
    url = 'http://soj.sysu.edu.cn/status.php?username=%s&status=1&language=2&submit=Go&p=%s'
    page = 1
    problem_list = {}
    while True:
        print url % ('huangzj1144',page)
        response = opener.open(url % (username,page))
        soup = BeautifulSoup(response.read(),'lxml')
        accept_list = soup.find('table').find_all('tr')
        if len(accept_list) == 1: break
        for line in accept_list[1:]:
            cols = line.find_all('td')
            cols = [col.get_text().strip() for col in cols]
            pid = cols[3]
            sid = cols[0]
            run_time = float(cols[6][:-3])
            if pid not in problem_list:
                problem_list[pid] = (sid,run_time)
            problem_list[pid] = max_sid((sid,run_time),problem_list[pid])
        page += 1
    for key,value in problem_list.items():
        filename = get_problem_name(opener,key) + '.cpp'
        source_code = get_source_code(opener,value[0])
        save_to_file(source_code,filename)


def get_problem_name(opener,pid):
    url = 'http://soj.sysu.edu.cn/show_problem.php?pid=%s' % pid
    response = opener.open(url)
    soup = BeautifulSoup(response.read(),'lxml')
    name = soup.find('div',class_ = 'cent').get_text().strip()
    return re.sub(u'[^a-zA-Z0-9\u4e00-\u9fa5]+',"_",name)


def get_source_code(opener,sid):
    url = 'http://soj.sysu.edu.cn/viewsource.php?sid=%s' %sid
    response = opener.open(url)
    soup = BeautifulSoup(response.read(),'lxml')
    return soup.find('pre').get_text()

def main():
    opener = set_cookie()
    login(opener,'huangzj1144','123456')
    save_problems(opener,'huangzj1144')

    return True

def set_cookie():
    cookie = cookielib.CookieJar()
    opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookie))
    return opener

def login(opener,username,password):
    url = 'http://soj.sysu.edu.cn/action.php?act=Login'
    values = {'lsession':'on','username':username,'password':password}
    data = urllib.urlencode(values)
    req = urllib2.Request(url)
    response = opener.open(req,data)
    for key,value in response.info().items():
        print key,value
    return response.read()



if __name__ == '__main__':
    main()

