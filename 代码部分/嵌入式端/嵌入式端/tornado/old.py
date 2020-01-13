# -*- coding:utf-8 -*-

import os

from tornado.web import Application, RequestHandler
from tornado.ioloop import IOLoop
from tornado.httpserver import HTTPServer

class IndexHandler(RequestHandler):

    def get(self):
        choose = self.get_query_argument("choose")
        if choose == 'q_on':
            print (choose)
            os.system('./run.sh')
        elif choose == 'q_off':
            print (choose)
            os.system('./stop.sh')
        elif choose == 'k_close':
            print (choose)
            os.system('shutdown -h now')
        elif choose == 'k_restart':
            print (choose)
            os.system('reboot')

if __name__ == "__main__":
    app = Application([(r"/",IndexHandler)])

    app.listen(8000)
    IOLoop.current().start()
