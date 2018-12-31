import getpass
import telnetlib

HOST = "localhost"
user = "root"
password = "agriculture"
#user = input("Enter your remote account: ")
#password = getpass.getpass()

tn = telnetlib.Telnet()

tn.open(HOST, 6571)

'''
tn.read_until(b"login: ")
tn.write(user.encode('ascii') + b"\n")
if password:
    tn.read_until(b"Password: ")
    tn.write(password.encode('ascii') + b"\n")

tn.write(b"ls\n")
tn.write(b"exit\n")

print(tn.read_all().decode('ascii'))'''