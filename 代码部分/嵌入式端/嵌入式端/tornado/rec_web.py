import json
import tornado
import os

from tornado.httpserver import HTTPServer
from tornado.options import define, options, parse_config_file
from tornado.web import Application, RequestHandler
from tornado.ioloop import IOLoop

class BaseHandler(RequestHandler):
    def set_default_headers(self):
        self.set_header("Access-Control-Allow-Origin", "*");
        self.set_header('Access-Control-Allow-Headers', '*');
        self.set_header('Access-Control-Allow-Methods', 'POST, GET, OPTIONS, DELETE');
        self.set_header("Access-Control-Max-Age", "3600");   
    
    def options(self):        
        pass

class IndexHandler(BaseHandler):
    def get(self, *args, **kwargs):
        choose = self.get_argument("choose")
        print ("get:" + str(choose))

    def post(self, *args, **kwargs):
        json_byte = self.request.body
        json_str = json_byte.decode('utf-8')
        json_obj = json.loads(json_str)

        choose = json_obj.get('choose');
        print ("choose: " + choose)

        if choose == 'q_on':
            os.system('./run.sh')
        elif choose == 'q_off':
            os.system('./stop.sh')
        elif choose == 'k_close':
            os.system('shutdown -h now')
        elif choose == 'k_restart':
            os.system('reboot')


if __name__ == "__main__":
    app = Application([(r"/", IndexHandler)])
    app.listen(8888)
    IOLoop.current().start()
