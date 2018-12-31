import telnetlib

HOST = "localhost"

tn = telnetlib.Telnet(HOST)
tn.read_until("lo  gin: ")
tn.write(user + "\n")
if password:
    tn.read_until("Password: ")
    tn.write(password + "\n")

tn.write("command1")
tn.write("command2")
tn.write("command3")
tn.write("command4")
tn.write("exit\n")

sess_op = tn.read_all()
print sess_op
#here I get the whole output