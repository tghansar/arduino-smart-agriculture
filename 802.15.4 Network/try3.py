import getpass
import sys
import telnetlib

HOST = "localhost"
user = "root"

#user = raw_input("Enter your remote account: ")

print("Enter Password")
password = getpass.getpass()

tn = telnetlib.Telnet(HOST)

tn.read_until("login: ")

tn.write(user + "\n")

if password:
    tn.read_until("Password: ")
    tn.write(password + "\n")

tn.write("ls\n")

tn.write("exit\n")

print tn.read_all()

"""https://stackoverflow.com/questions/28295501/ssh-and-telnet-to-localhost-using-python"""