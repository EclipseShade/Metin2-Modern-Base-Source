import sys

if len (sys.argv) != 4:
	exit(1)

option = sys.argv[1]
if option != "ADD" and option != "DEL":
	exit (1)

pack_list_name = sys.argv[2]

filename = '"'+sys.argv[3]+'"'

rf = open (pack_list_name, "rb")
wf = open (pack_list_name+".new", "wb")

c = False
if option == "ADD":
	for line in rf.readlines():
		if line[-1:] == "\n":
			line = line[:-1]
		if line[-1:] == "\r":
			line = line[:-1]
		wf.write ("%s\r\n" % line)
		if c == True:
			wf.write ("\t%s\r\n" % filename)
			c = False
		if line == "List FileList":
			c = True
else:
	for line in rf.readlines():
		if line[-1:] == "\n":
			line = line[:-1]
		if line[-1:] == "\r":
			line = line[:-1]
		ss = line.split("\t")
		if c == True and len (ss) >= 2 and ss[1] == filename:
			continue
		wf.write ("%s\r\n" % line)
		if line == "List FileList":
			c = True

import os
os.system ("move "+pack_list_name+".new "+pack_list_name)
