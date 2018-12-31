#ssh root@10.0.0.100 'telnet localhost 6571'

class telnetObject(object):
	"""docstring for ClassName"""
	def __init__(self, host='localhost', port=11211, timeout=3):
	        self.host = host
	        self.port = port
	        self.timeout = float(timeout)
	        self.tn = telnetlib.Telnet()
	        self.getStats()

telnetObject c