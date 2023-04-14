from http.server import BaseHTTPRequestHandler, HTTPServer


class Serv(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/':
            self.path = '/index.html'
        try:
            file_to_open = open(self.path[1:]).read()
            URL = 'index.html'
            file = open(URL, 'r')
            data = file.read()
            reconocedor = 'class="cosaImportante"'
            if (reconocedor in data):
                self.send_response(200)
            else:
                self.send_response(403)
        except:
            file_to_open = "File not found"
            self.send_response(404)
        self.end_headers()
        self.wfile.write(bytes("Hola!", 'utf-8'))


httpd = HTTPServer(('0.0.0.0', 8080), Serv)
httpd.serve_forever()
